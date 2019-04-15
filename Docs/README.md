[![EN](https://user-images.githubusercontent.com/9499881/33184537-7be87e86-d096-11e7-89bb-f3286f752bc6.png)](https://github.com/NexInput/NexInput-Core/blob/master/Docs/README.md) 
[![RU](https://user-images.githubusercontent.com/9499881/27683795-5b0fbac6-5cd8-11e7-929c-057833e01fb1.png)](https://github.com/NexInput/NexInput-Core/blob/master/Docs/README.RU.md) 
[![CN](https://user-images.githubusercontent.com/9499881/31012373-978ce414-a522-11e7-9936-387b1c530e2f.png)](https://github.com/NexInput/NexInput-Core/blob/master/Docs/README.CN.md) 
[![ES](https://user-images.githubusercontent.com/9499881/31012379-9d8f7764-a522-11e7-8bf4-739077369e8b.png)](https://github.com/NexInput/NexInput-Core/blob/master/Docs/README.ES.md) 
[![FR](https://user-images.githubusercontent.com/9499881/31012387-a7b4aaac-a522-11e7-8485-36ce58dc2d4a.png)](https://github.com/NexInput/NexInput-Core/blob/master/Docs/README.FR.md) 
[![DE](https://user-images.githubusercontent.com/9499881/31012392-ac051326-a522-11e7-9c8c-2186ddf553d0.png)](https://github.com/NexInput/NexInput-Core/blob/master/Docs/README.DE.md) 
[![PT](https://user-images.githubusercontent.com/9499881/31012384-a1d1b544-a522-11e7-8a13-3cb53450d55c.png)](https://github.com/NexInput/NexInput-Core/blob/master/Docs/README.PT.md)
# Functions NexInput
All functions are imported directly from the library "NexInput_1.0_32.dll" for 32-bit and "NexInput_1.0_64.dll" for 64-bit. The library path can be obtained from the registry.

| Name | Description |
| ------------- | ------------- |
| [NEXInputGetState](https://github.com/NexInput/NexInput-Core/blob/master/Docs/EN/Functions/NEXInputGetState.md) | Retrieves the state of the rotation, buttons, sticks and triggers of the controller. |
| [NEXInputSetState](https://github.com/NexInput/NexInput-Core/blob/master/Docs/EN/Functions/NEXInputSetState.md) | Sends data to a controller. Function is used to activate the feedback (vibration) and enable RGB-LED of a controller. |
| [NEXInputGetInfo](https://github.com/NexInput/NexInput-Core/blob/master/Docs/EN/Functions/NEXInputGetInfo.md) | Retrieves the controller type, connection type and battery level. |
| [NEXInputPowerOff](https://github.com/NexInput/NexInput-Core/blob/master/Docs/EN/Functions/NEXInputPowerOff.md) | Turning off the controller. |

# Parameters NexInput
The registry settings are in the branch `HKEY_CURRENT_USER\Software\NexInput`.

| Name | Description |
| ------------- | ------------- |
| `NexInput_v1.0_32` | The path to the 32-bit library with functions. |
| `NexInput_v1.0_64` | The path to the 64-bit library with functions. |
| `Drivers32` | Path to the folder with 32-bit drivers. |
| `Drivers64` | Path to the folder with 64-bit drivers. |
