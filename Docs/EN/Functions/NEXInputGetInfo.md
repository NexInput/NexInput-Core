# NEXInputGetInfo
Retrieves the controller type, connection type and battery level.

С++
```c
NEXInputGetInfo(
	__in DWORD dwUserIndex,
	__out NEX_CONTROLLER_INFO *pControllerInfo
);
```

#### Parameters
dwIndex - Index of the user's controller. Can be a value from 0 to 3.

NEX_CONTROLLER_INFO [out] - Pointer to an NEX_CONTROLLER_INFO structure that receives the current state of the controller.

#### NEX_CONTROLLER_INFO structure
C++
```c
typedef struct _NEX_CONTROLLER_INFO
{
	WORD								ControllerType;
	BYTE								ConnectType;
	BYTE								BatteryLevel;
	bool								SupportRotation;
} NEX_CONTROLLER_INFO, *PNEX_CONTROLLER_INFO;
```

| Type | Description | Values |
| ------------- | ------------- | ------------- |
| ControllerType | Controller type | Below |
| ConnectType | Type of connection, wired or wireless | NEX_CONTROLLER_WIRED - 0 or NEX_CONTROLLER_WIRELESS - 1 |
| BatteryLevel | Battery charge status | Range 1 to 5 (where 1 is 0%, 3 is 50%, and 5 is 100% charge) with no battery - 0 |
| SupportRotation | Support for rotation sensors (gyroscope) | True or False |

#### ControllerType
Types of controllers. It is necessary to change the display of button icons. The list will be updated as new controllers appear.

| Constant | Value |
| ------------- | ------------- |
| MICROSOFT_XBOX_360_CONTROLLER | 1 |
| MICROSOFT_XBOX_ONE_CONTROLLER | 2 |
| SONY_DUALSHOCK_3_CONTROLLER | 26 |
| SONY_DUALSHOCK_4_CONTROLLER | 27 |
| SONY_DUALSHOCK_5_CONTROLLER | 28 |
| NINTENDO_SWITCH_PRO_CONTROLLER | 51 |

#### Return Value
If the controller is connected and the function succeeded, the return value is ERROR_SUCCESS - 0, otherwise ERROR_DEVICE_NOT_CONNECTED - 1.