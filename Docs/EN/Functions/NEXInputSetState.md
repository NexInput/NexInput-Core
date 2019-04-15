# NEXInputSetState
Sends data to a controller. Function is used to activate the feedback (vibration) and enable RGB-LED of a controller.

С++
```c
DWORD NEXInputSetState(
	__in DWORD dwUserIndex,
	__in NEX_OUTPUT_STATE *pOutputState
);
```

#### Parameters
dwIndex - Index of the user's controller. Can be a value from 0 to 3.

NEX_OUTPUT_STATE - Pointer to an NEX_OUTPUT_STATE structure that receives the current state of the controller.


#### NEX_OUTPUT_STATE structure
C++
```c
typedef struct _NEX_OUTPUT_STATE
{
	WORD					LeftMotorSpeed;
	WORD					RightMotorSpeed;
	BYTE					LEDBrightness;
	BYTE					LEDRed;
	BYTE					LEDGreen;
	BYTE					LEDBlue;
} NEX_OUTPUT_STATE, *PNEX_OUTPUT_STATE;
```

| Type | Description | Value |
| ------------- | ------------- | ------------- |
| LeftMotorSpeed, RightMotorSpeed | Speed of the left or right motor. | Range 0 to 65535 |
| UseLed | RGB-LED Brightness | Range 0 to 255 |
| LEDRed, LEDGreen, LEDBlue | Color for RGB-LED | Range 0 to 255 |


#### Return Value
If the controller is connected and the function succeeded, the return value is ERROR_SUCCESS - 0, otherwise ERROR_DEVICE_NOT_CONNECTED - 1 .