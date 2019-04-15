# NEXInputPowerOff
Turning off the controller.

С++
```c
DWORD NEXInputPowerOff(
	__in DWORD dwUserIndex
);
```

#### Parameters
dwUserIndex - Index of the user's controller. Can be a value from 0 to 3.

#### Return Value
If the controller is connected and the function succeeded, the return value is ERROR_SUCCESS - 0, otherwise ERROR_DEVICE_NOT_CONNECTED - 1.
