//=================== Nex Input ===================
//========== https://github.com/NexInput ==========

#include "stdafx.h"
#include <atlstr.h>
#include <Windows.h>

#define DLLEXPORT extern "C" __declspec(dllexport)

#define NEX_GAMEPAD_DPAD_UP				0x0001
#define NEX_GAMEPAD_DPAD_DOWN			0x0002
#define NEX_GAMEPAD_DPAD_LEFT			0x0004
#define NEX_GAMEPAD_DPAD_RIGHT			0x0008
#define NEX_GAMEPAD_START				0x0010
#define NEX_GAMEPAD_BACK				0x0020
#define NEX_GAMEPAD_LEFT_THUMB			0x0040
#define NEX_GAMEPAD_RIGHT_THUMB			0x0080
#define NEX_GAMEPAD_LEFT_SHOULDER		0x0100
#define NEX_GAMEPAD_RIGHT_SHOULDER		0x0200
#define NEX_GAMEPAD_A					0x1000
#define NEX_GAMEPAD_B					0x2000
#define NEX_GAMEPAD_X					0x4000
#define NEX_GAMEPAD_Y					0x8000

#define NEX_CONTROLLER_WIRED			0
#define NEX_CONTROLLER_WIRELESS			1
#define NEX_BATTERY_NONE				0
#define NEX_BATTERY_LOW					1
#define NEX_BATTERY_FULL				5

#define NEX_INPUT_MAX_COUNT				4

#define ERROR_DEVICE_NOT_CONNECTED		1
#define ERROR_SUCCESS					0

typedef struct _NEX_INPUT_STATE
{
	WORD								Buttons;
	BYTE								LeftTrigger;
	BYTE								RightTrigger;
	SHORT								AxisLX;
	SHORT								AxisLY;
	SHORT								AxisRX;
	SHORT								AxisRY;
	bool								SupportRotation;
	float								Yaw;
	float								Pitch;
	float								Roll;
} NEX_INPUT_STATE, *PNEX_INPUT_STATE;

typedef struct _NEX_OUTPUT_STATE
{
	WORD								LeftMotorSpeed;
	WORD								RightMotorSpeed;
	BYTE								LEDBrightness;
	BYTE								LEDRed;
	BYTE								LEDGreen;
	BYTE								LEDBlue;
} NEX_OUTPUT_STATE, *PNEX_OUTPUT_STATE;

#define NEX_UNKNOWN_CONTROLLER			0;

#define MICROSOFT_XBOX_360_CONTROLLER	1;
#define MICROSOFT_XBOX_ONE_CONTROLLER	2;

#define SONY_DUALSHOCK_3_CONTROLLER		26;
#define SONY_DUALSHOCK_4_CONTROLLER		27;
#define SONY_DUALSHOCK_5_CONTROLLER		28;

#define NINTENDO_SWITCH_PRO_CONTROLLER	51;

typedef struct _NEX_CONTROLLER_INFO
{
	WORD								ControllerType;
	BYTE								ConnectType;
	BYTE								BatteryLevel;
} NEX_CONTROLLER_INFO, *PNEX_CONTROLLER_INFO;

typedef DWORD(__stdcall *_NEXInputGetState)(__in DWORD dwUserIndex, __out NEX_INPUT_STATE *pInputState);
typedef DWORD(__stdcall *_NEXInputSetState)(__in DWORD dwUserIndex, __in NEX_OUTPUT_STATE *pOutputState);
typedef DWORD(__stdcall *_NEXInputGetInfo)(__in DWORD dwUserIndex, __out NEX_CONTROLLER_INFO *pControllerInfo);
typedef DWORD(__stdcall *_NEXInputPowerOff)(__in DWORD dwUserIndex);

_NEXInputGetState DriverNEXInputGetState[NEX_INPUT_MAX_COUNT + 1]; // "+ 1" since "0" is used to test the driver
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

	#ifdef _WIN64
		status = key.QueryStringValue(_T("Drivers64"), driversPath, &regSize);
	#else
		status = key.QueryStringValue(_T("Drivers32"), driversPath, &regSize);
	#endif

		_tcscpy_s(_driversPath, driversPath);
	}
	key.Close();

	if (status == ERROR_SUCCESS) {

		_tcscat_s(_driversPath, sizeof(_driversPath), _T("*.dll"));

		//Search drivers
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

						//Search connected gamepads
						NEX_INPUT_STATE DriverInputState;
						FoundNewDriver = true;
						if (DriverNEXInputGetState[0] != NULL)
							for (int i = 0; i < NEX_INPUT_MAX_COUNT; i++)

								//If found the connected gamepad then adding driver
								if (DriverNEXInputGetState[0](i, &DriverInputState) == ERROR_SUCCESS)
								{
									//Add new driver only 1 time.
									if (FoundNewDriver) {
										FoundNewDriver = false;
										DriverDllCount += 1;
										DriverDll[DriverDllCount] = LoadLibrary(driverPath);
										DriverNEXInputGetState[DriverDllCount] = (_NEXInputGetState)GetProcAddress(DriverDll[DriverDllCount], "NEXInputGetState");
										DriverNEXInputSetState[DriverDllCount] = (_NEXInputSetState)GetProcAddress(DriverDll[DriverDllCount], "NEXInputSetState");
										DriverNEXInputGetInfo[DriverDllCount] = (_NEXInputGetInfo)GetProcAddress(DriverDll[DriverDllCount], "NEXInputGetInfo");
										DriverNEXInputPowerOff[DriverDllCount] = (_NEXInputPowerOff)GetProcAddress(DriverDll[DriverDllCount], "NEXInputPowerOff");
									}

									//Adding address
									DriverControllerIndex[NexInputCount].DllIndex = DriverDllCount;
									DriverControllerIndex[NexInputCount].ControllerIndex = i;
									NexInputCount += 1;
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
	pInputState->SupportRotation = false;
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
