//=================== Nex Input ===================
//========== https://github.com/NexInput ==========
//=================================================

#include <windows.h>
#include <atlstr.h>
#include "NexInput.h"

#define DLLEXPORT extern "C" __declspec(dllexport)

_NEXInputGetState DriverNEXInputGetState[NEX_INPUT_MAX_COUNT + 1]; // "+ 1" since "0" is used to check the driver
_NEXInputSetState DriverNEXInputSetState[NEX_INPUT_MAX_COUNT + 1];
_NEXInputGetInfo DriverNEXInputGetInfo[NEX_INPUT_MAX_COUNT + 1];
_NEXInputPowerOff DriverNEXInputPowerOff[NEX_INPUT_MAX_COUNT + 1];

HMODULE DriverDll[NEX_INPUT_MAX_COUNT + 1];
BYTE DriverDllCount = 0;
BYTE NexInputCount = 0;

typedef struct
{
	BYTE DllIndex, ControllerIndex;
} _DriverIndex;
_DriverIndex DriverControllerIndex[NEX_INPUT_MAX_COUNT];

void Init() {
	WIN32_FIND_DATA ffd;
	HANDLE hFind = INVALID_HANDLE_VALUE;

	CRegKey key;
	TCHAR driversPath[MAX_PATH] = { 0 };
	TCHAR _driversPath[MAX_PATH] = { 0 };

	LONG status = key.Open(HKEY_CURRENT_USER, _T("Software\\NexInput"));
	if (status == ERROR_SUCCESS)
	{
		ULONG regSize = sizeof(driversPath);

		#if _M_IX86
			status = key.QueryStringValue(_T("Drivers32"), driversPath, &regSize);
		#elif _WIN64
			status = key.QueryStringValue(_T("Drivers64"), driversPath, &regSize);
		#endif

		_tcscpy_s(_driversPath, driversPath);
	}
	key.Close();

	if (status == ERROR_SUCCESS) {

		_tcscat_s(_driversPath, sizeof(_driversPath), _T("*.dll"));

		// Search drivers
		hFind = FindFirstFile(_driversPath, &ffd);

		bool FoundNewDriver;

		if (hFind != INVALID_HANDLE_VALUE)
			do
			{
				TCHAR driverPath[MAX_PATH] = { 0 };
				_tcscpy_s(driverPath, driversPath);

				if ((ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == false)
				{
					_tcscat_s(driverPath, sizeof(driverPath), ffd.cFileName);

					DriverDll[0] = LoadLibrary(driverPath);
					if (DriverDll[0] != NULL) {
						DriverNEXInputGetState[0] = (_NEXInputGetState)GetProcAddress(DriverDll[0], "NEXInputGetState");

						// Search connected gamepads
						NEX_INPUT_STATE DriverInputState;
						FoundNewDriver = true;
						if (DriverNEXInputGetState[0] != NULL) //Check valid function
							for (int i = 0; i < NEX_INPUT_MAX_COUNT; i++)

								//If found the connected gamepad then adding driver
								if (DriverNEXInputGetState[0](i, &DriverInputState) == ERROR_SUCCESS)
								{
									//Add new driver only 1 time.
									if (FoundNewDriver) {
										FoundNewDriver = false;
										DriverDllCount++;
										DriverDll[DriverDllCount] = LoadLibrary(driverPath);
										DriverNEXInputGetState[DriverDllCount] = (_NEXInputGetState)GetProcAddress(DriverDll[DriverDllCount], "NEXInputGetState");
										DriverNEXInputSetState[DriverDllCount] = (_NEXInputSetState)GetProcAddress(DriverDll[DriverDllCount], "NEXInputSetState");
										DriverNEXInputGetInfo[DriverDllCount] = (_NEXInputGetInfo)GetProcAddress(DriverDll[DriverDllCount], "NEXInputGetInfo");
										DriverNEXInputPowerOff[DriverDllCount] = (_NEXInputPowerOff)GetProcAddress(DriverDll[DriverDllCount], "NEXInputPowerOff");
									}

									//Adding address
									DriverControllerIndex[NexInputCount].DllIndex = DriverDllCount;
									DriverControllerIndex[NexInputCount].ControllerIndex = i;
									NexInputCount++;
								}

						FreeLibrary(DriverDll[0]);
						DriverDll[0] = nullptr;
					}

				}
			} while (FindNextFile(hFind, &ffd) != 0);

		FindClose(hFind);
	}
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH: {
			Init();
			break;
		}

		case DLL_PROCESS_DETACH: {
			for (int i = 1; i < DriverDllCount + 1; i++)
				if (DriverDll[i] != NULL) {
					FreeLibrary(DriverDll[i]);
					DriverDll[i] = nullptr;
				}
			break;
		}
	}
	return true;
}

DLLEXPORT DWORD __stdcall NEXInputGetState(__in DWORD dwUserIndex, __out NEX_INPUT_STATE *pInputState)
{
	pInputState->Buttons = 0;
	pInputState->RightTrigger = 0;
	pInputState->LeftTrigger = 0;
	pInputState->AxisLX = 0;
	pInputState->AxisLY = 0;
	pInputState->AxisRX = 0;
	pInputState->AxisRY = 0;
	pInputState->Yaw = 0;
	pInputState->Pitch = 0;
	pInputState->Roll = 0;

	if (dwUserIndex < NexInputCount)
		return DriverNEXInputGetState[DriverControllerIndex[dwUserIndex].DllIndex](DriverControllerIndex[dwUserIndex].ControllerIndex, pInputState);
	else
		return ERROR_DEVICE_NOT_CONNECTED;
}

DLLEXPORT DWORD __stdcall NEXInputSetState(__in DWORD dwUserIndex, __in NEX_OUTPUT_STATE *pOutputState)
{
	if (dwUserIndex < NexInputCount)
		return DriverNEXInputSetState[DriverControllerIndex[dwUserIndex].DllIndex](DriverControllerIndex[dwUserIndex].ControllerIndex, pOutputState);
	else
		return ERROR_DEVICE_NOT_CONNECTED;
}

DLLEXPORT DWORD __stdcall NEXInputGetInfo(__in DWORD dwUserIndex, __out NEX_CONTROLLER_INFO *pControllerInfo)
{
	pControllerInfo->ControllerType = NEX_UNKNOWN_CONTROLLER;
	pControllerInfo->ConnectType = NEX_CONTROLLER_WIRED;
	pControllerInfo->BatteryLevel = NEX_BATTERY_NONE;
	pControllerInfo->SupportRotation = false;

	if (dwUserIndex < NexInputCount)
		return DriverNEXInputGetInfo[DriverControllerIndex[dwUserIndex].DllIndex](DriverControllerIndex[dwUserIndex].ControllerIndex, pControllerInfo);
	else
		return ERROR_DEVICE_NOT_CONNECTED;
}

DLLEXPORT DWORD __stdcall NEXInputPowerOff(__in DWORD dwUserIndex)
{
	if (dwUserIndex < NexInputCount)
		return DriverNEXInputPowerOff[DriverControllerIndex[dwUserIndex].DllIndex](DriverControllerIndex[dwUserIndex].ControllerIndex);
	else
		return ERROR_DEVICE_NOT_CONNECTED;
}
