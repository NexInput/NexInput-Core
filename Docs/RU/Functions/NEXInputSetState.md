# NEXInputSetState
Отправка данных контролеру. Функция используется для активации обратной отдачи (вибрации) и включения RGB-светодиода на контроллере.

С++
```c
DWORD NEXInputSetState(
	__in DWORD dwUserIndex,
	__in NEX_OUTPUT_STATE *pOutputState
);
```

#### Параметры
dwUserIndex - Индекс контроллера пользователя, от 0 до 3.
NEX_OUTPUT_STATE - Указатель на структуру NEX_OUTPUT_STATE, которая содержит необходимое состояние контроллера.


#### Структура NEX_OUTPUT_STATE
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

| Тип | Описание | Значения |
| ------------- | ------------- | ------------- |
| LeftMotorSpeed, RightMotorSpeed | Сила вибрации левого и правого мотора | От 0 до 65535 |
| LEDBrightness | Яркость RGB-светодиода | От 0 до 255 |
| LEDRed, LEDGreen, LEDBlue | Цвет для RGB-светодиода | От 0 до 255 |


#### Возвращаемое значение
Если контроллеры подключенены и функция успешно завершилась, возвращаемое значение равно ERROR_SUCCESS - 0, иначе ERROR_DEVICE_NOT_CONNECTED - 1.