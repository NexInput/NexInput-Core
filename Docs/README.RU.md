[![EN](https://user-images.githubusercontent.com/9499881/33184537-7be87e86-d096-11e7-89bb-f3286f752bc6.png)](https://github.com/NexInput/NexInput-Core/blob/master/Docs/README.md) 
[![RU](https://user-images.githubusercontent.com/9499881/27683795-5b0fbac6-5cd8-11e7-929c-057833e01fb1.png)](https://github.com/NexInput/NexInput-Core/blob/master/Docs/README.RU.md) 
[![CN](https://user-images.githubusercontent.com/9499881/31012373-978ce414-a522-11e7-9936-387b1c530e2f.png)](https://github.com/NexInput/NexInput-Core/blob/master/Docs/README.CN.md) 
[![ES](https://user-images.githubusercontent.com/9499881/31012379-9d8f7764-a522-11e7-8bf4-739077369e8b.png)](https://github.com/NexInput/NexInput-Core/blob/master/Docs/README.ES.md) 
[![FR](https://user-images.githubusercontent.com/9499881/31012387-a7b4aaac-a522-11e7-8485-36ce58dc2d4a.png)](https://github.com/NexInput/NexInput-Core/blob/master/Docs/README.FR.md) 
[![DE](https://user-images.githubusercontent.com/9499881/31012392-ac051326-a522-11e7-9c8c-2186ddf553d0.png)](https://github.com/NexInput/NexInput-Core/blob/master/Docs/README.DE.md) 
[![PT](https://user-images.githubusercontent.com/9499881/31012384-a1d1b544-a522-11e7-8a13-3cb53450d55c.png)](https://github.com/NexInput/NexInput-Core/blob/master/Docs/README.PT.md)
# Функции NexInput
Все функции импортируются напрямую из библиотеки "NexInput_1.0_32.dll" для 32-битной версии и "NexInput_1.0_64.dll" для 64-битной версии. Путь библиотеки можно получить из реестра Windows. 

| Название | Описание |
| ------------- | ------------- |
| [NEXInputGetState](https://github.com/NexInput/NexInput-Core/blob/master/Docs/RU/Functions/NEXInputGetState.md) | Получение состояния кнопок, вращения, стиков и триггеров контроллера. |
| [NEXInputSetState](https://github.com/NexInput/NexInput-Core/blob/master/Docs/RU/Functions/NEXInputSetState.md) | Отправка данных контролеру. Функция используется для активации обратной отдачи (вибрации) и включения RGB-светоидиода на контроллере. |
| [NEXInputGetInfo](https://github.com/NexInput/NexInput-Core/blob/master/Docs/RU/Functions/NEXInputGetInfo.md) | Получение типа контроллера, типа подключения и уровня заряда батареи. |
| [NEXInputPowerOff](https://github.com/NexInput/NexInput-Core/blob/master/Docs/RU/Functions/NEXInputPowerOff.md) | Выключение контроллера. |

# Параметры NexInput
Параметры реестра находятся в ветке `HKEY_CURRENT_USER\Software\NexInput`.

| Название  | Описание |
| ------------- | ------------- |
| `NexInput_v1.0_32` | Путь до 32-битной библиотеки с функциями. |
| `NexInput_v1.0_64` | Путь до 64-битной библиотеки с функциями. |
| `Drivers32` | Путь до папки с 32-битными драйверами. |
| `Drivers64` | Путь до папки с 64-битными драйверами. |

