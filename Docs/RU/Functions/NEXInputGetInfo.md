# NEXInputGetInfo
Получение типа контроллера, типа подключения и уровня заряда батареи.

С++
```c
NEXInputGetInfo(
	__in DWORD dwUserIndex,
	__out NEX_CONTROLLER_INFO *pControllerInfo
);
```

#### Параметры
dwUserIndex - Индекс контроллера пользователя, от 0 до 3.

NEX_CONTROLLER_INFO [out] - Указатель на структуру NEX_CONTROLLER_INFO, которая получает данные контроллера.

#### Структура NEX_CONTROLLER_INFO
C++
```c
typedef struct _NEX_CONTROLLER_INFO
{
	WORD								ControllerType;
	BYTE								ConnectType;
	BYTE								BatteryLevel;
} NEX_CONTROLLER_INFO, *PNEX_CONTROLLER_INFO;
```

| Тип | Описание | Значения |
| ------------- | ------------- | ------------- |
| ControllerType | Тип контроллера | Ниже |
| ConnectType | Тип подключения, проводное или беспроводное | NEX_CONTROLLER_WIRED - 0 или NEX_CONTROLLER_WIRELESS - 1 |
| BatteryLevel | Состояние заряда батареи | От 1 до 5 (где 1 это 0%, 3 - 50%, а 5 - 100% заряда), при отсутствии батареи - 0 |

#### ControllerType
Типы контроллеров. Необходимо для изменения отображения иконок кнопок. Список будет дополняться по мере появления новых контроллеров.

| Название константы | Значение |
| ------------- | ------------- |
| MICROSOFT_XBOX_360_CONTROLLER | 1 |
| MICROSOFT_XBOX_ONE_CONTROLLER | 2 |
| SONY_DUALSHOCK_3_CONTROLLER | 26 |
| SONY_DUALSHOCK_4_CONTROLLER | 27 |
| SONY_DUALSHOCK_5_CONTROLLER | 28 |
| NINTENDO_SWITCH_PRO_CONTROLLER | 51 |

#### Возвращаемое значение
Если контроллеры подключенены и функция успешно завершилась, возвращаемое значение равно ERROR_SUCCESS - 0, иначе ERROR_DEVICE_NOT_CONNECTED - 1.