# NEXInputGetState
Retrieves the state of the rotation, buttons, sticks and triggers of the controller.

С++
```c
DWORD NEXInputGetState(
	__in DWORD dwUserIndex,
	__out NEX_INPUT_STATE *pInputState
);
```

#### Parameters
dwIndex - Index of the user's controller. Can be a value from 0 to 3.

NEX_INPUT_STATE [out] - Pointer to an NEX_INPUT_STATE structure that receives the current state of the controller.

#### NEX_INPUT_STATE structure
C++
```c
typedef struct _NEX_INPUT_STATE
{
	WORD			Buttons;
	BYTE			LeftTrigger;
	BYTE			RightTrigger;
	SHORT			AxisLX;
	SHORT			AxisLY;
	SHORT			AxisRX;
	SHORT			AxisRY;
	float			Yaw;
	float			Pitch;
	float			Roll;
} NEX_INPUT_STATE, *PNEX_INPUT_STATE;
```

| Type | Description | Values |
| ------------- | ------------- | ------------- |
| LeftTrigger, RightTrigger | Controller triggers | Range 0 to 255 |
| AxisLX, AxisRX | Axes of sticks on X | Range -32768 to 32767 |
| AxisLY, AxisRY | Axes of sticks on Y | Range  -32768 to 32767 |
| Yaw, Pitch, Roll | Tracking rotation | Range -179.99 to 179.99 (in degrees) |

If you need a quaternion, then you can get it from Yaw, Pitch, Roll.
```c
double qW, qX, qY, qZ;
myYaw = yaw * (3.14159265358979323846 / 180); //degrees to radians
myRoll = roll * (3.14159265358979323846 / 180); //degrees to radians
myPitch = pitch * (3.14159265358979323846 / 180); //degrees to radians
qW = cos(myYaw * 0.5) * cos(myRoll * 0.5) * cos(myPitch * 0.5) + sin(myYaw * 0.5) * sin(myRoll * 0.5) * sin(myPitch * 0.5);
qX = cos(myYaw * 0.5) * sin(myRoll * 0.5) * cos(myPitch * 0.5) - sin(myYaw * 0.5) * cos(myRoll * 0.5) * sin(myPitch * 0.5);
qY = cos(myYaw * 0.5) * cos(myRoll * 0.5) * sin(myPitch * 0.5) + sin(myYaw * 0.5) * sin(myRoll * 0.5) * cos(myPitch * 0.5);
qZ = sin(myYaw * 0.5) * cos(myRoll * 0.5) * cos(myPitch * 0.5) - cos(myYaw * 0.5) * sin(myRoll * 0.5) * sin(myPitch * 0.5);
```

#### Buttons
Bitmask of the device digital buttons, as follows. A set bit indicates that the corresponding button is pressed.

| Button | Bitmask |
| ------------- | ------------- |
| NEX_GAMEPAD_DPAD_UP | 0x0001  |
| NEX_GAMEPAD_DPAD_DOWN | 0x0002  |
| NEX_GAMEPAD_DPAD_LEFT | 0x0004  |
| NEX_GAMEPAD_DPAD_RIGHT | 0x0008  |
| NEX_GAMEPAD_START | 0x0010  |
| NEX_GAMEPAD_BACK | 0x0020  |
| NEX_GAMEPAD_LEFT_THUMB | 0x0040  |
| NEX_GAMEPAD_RIGHT_THUMB | 0x0080  |
| NEX_GAMEPAD_LEFT_SHOULDER | 0x0100  |
| NEX_GAMEPAD_RIGHT_SHOULDER | 0x0200
| NEX_GAMEPAD_A | 0x1000  |
| NEX_GAMEPAD_B | 0x2000  |
| NEX_GAMEPAD_X | 0x4000  |
| NEX_GAMEPAD_Y | 0x8000  |

#### Return Value
If the controller is connected and the function succeeded, the return value is ERROR_SUCCESS - 0, otherwise ERROR_DEVICE_NOT_CONNECTED - 1 .