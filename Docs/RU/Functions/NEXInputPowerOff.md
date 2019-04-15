# NEXInputPowerOff
Выключение контроллера.

С++
```c
DWORD NEXInputPowerOff(
	__in DWORD dwUserIndex
);
```

#### Параметры
dwUserIndex - Индекс контроллера пользователя, от 0 до 3.

#### Возвращаемое значение
Если контроллеры подключенены и функция успешно завершилась, возвращаемое значение равно ERROR_SUCCESS - 0, иначе ERROR_DEVICE_NOT_CONNECTED - 1.
