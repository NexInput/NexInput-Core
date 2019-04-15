# NEXInputGetState
Получение состояния кнопок, вращения, стиков и триггеров контроллера.

С++
```c
DWORD NEXInputGetState(
	__in DWORD dwUserIndex,
	__out NEX_INPUT_STATE *pInputState
);
```

#### Параметры
dwUserIndex - Индекс контроллера пользователя, от 0 до 3.
NEX_INPUT_STATE [out] - Указатель на структуру NEX_INPUT_STATE, которая получает текущее состояние контроллера.

#### Структура NEX_INPUT_STATE
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
	bool			SupportRotation;
	float			Yaw;
	float			Pitch;
	float			Roll;
} NEX_INPUT_STATE, *PNEX_INPUT_STATE;
```

| Тип | Описание | Значения |
| ------------- | ------------- | ------------- |
| LeftTrigger, RightTrigger | Триггеры контроллера | От 0 до 255 |
| AxisLX, AxisRX | Оси стиков по X | От -32768 до 32767 |
| AxisLY, AxisRY | Оси стиков по Y | От -32768 до 32767 |
| SupportRotation | Поддержка датчиков вращения (гироскоп) | True или False |
| Yaw, Pitch, Roll | Отслеживание вращения | От -180 до 180 (в градусах) |

Если вы предпочитаете использовать кватернион, вы можете получить его из Yaw, Pitch, Roll.
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
Битовая маска кнопок контроллеров. Установленный бит указывает, что нажата соответствующая кнопка. 

| Кнопка | Битовая маска |
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

#### Возвращаемое значение
Если контроллеры подключенены и функция успешно завершилась, возвращаемое значение равно ERROR_SUCCESS - 0, иначе ERROR_DEVICE_NOT_CONNECTED - 1.