[![EN](https://user-images.githubusercontent.com/9499881/33184537-7be87e86-d096-11e7-89bb-f3286f752bc6.png)](https://github.com/NexInput/Core/blob/master/README.md) 
[![RU](https://user-images.githubusercontent.com/9499881/27683795-5b0fbac6-5cd8-11e7-929c-057833e01fb1.png)](https://github.com/NexInput/Core/blob/master/README.RU.md) 
[![JP](https://user-images.githubusercontent.com/9499881/45507863-48e09f00-b7a4-11e8-9750-f5778e187ad6.png)](https://github.com/NexInput/Core/blob/master/README.JP.md)
[![DE](https://user-images.githubusercontent.com/9499881/31012392-ac051326-a522-11e7-9c8c-2186ddf553d0.png)](https://github.com/NexInput/Core/blob/master/README.DE.md) 
[![ES](https://user-images.githubusercontent.com/9499881/31012379-9d8f7764-a522-11e7-8bf4-739077369e8b.png)](https://github.com/NexInput/Core/blob/master/README.ES.md) 
[![FR](https://user-images.githubusercontent.com/9499881/31012387-a7b4aaac-a522-11e7-8485-36ce58dc2d4a.png)](https://github.com/NexInput/Core/blob/master/README.FR.md) 
[![PT](https://user-images.githubusercontent.com/9499881/31012384-a1d1b544-a522-11e7-8a13-3cb53450d55c.png)](https://github.com/NexInput/Core/blob/master/README.PT.md)
[![IT](https://user-images.githubusercontent.com/9499881/50381884-97f37580-06ab-11e9-8ca8-e8ec7a1b8594.png)](https://github.com/NexInput/Core/blob/master/README.IT.md)
[![CN](https://user-images.githubusercontent.com/9499881/31012373-978ce414-a522-11e7-9936-387b1c530e2f.png)](https://github.com/NexInput/Core/blob/master/README.CN.md) 
# Nex Input
Nex Input - это новый современный стандарт, который дает возможность использовать гироскоп и RGB-светодиод. Стандарт имеет простой API, который позволяет получить доступ ко всем популярным геймпадам.

- Для разработчиков игр: [демонстрационные примеры](https://github.com/NexInput/Samples), [документация](https://github.com/NexInput/Core/blob/master/Docs/README.RU.md) и рекомендации по [использованию гироскопа и RGB-светодиода](https://github.com/NexInput/Core/blob/master/Docs/RU/Recommendations/Games.md) в играх.
- Для разработчиков драйверов геймпадов: [демонстрационный драйвер](https://github.com/NexInput/Sample-driver).
- Присылайте ваши исправления, улучшения, демонстрационные примеры, переводы и так далее.
- Пишите ваши предложения и запросы новой функциональности через "Issue" или почту.
- Становитесь разработчиком стандарта.

## Особенности стандарта:
- Поддержка популярных геймпадов.
- Поддержка современных фишек, таких как гироскоп и RGB-светодиод.

## Принцип работы:
Если у пользователя не установлен пакет "Nex Input", то используется интегрированная библиотека, которая транслирует вызовы в стандартный "XInput".

Если пользователь использует устаревший геймпад, без гироскопа, то API отдает статус отсуствия гироскопа.

## Поддерживаемое оборудование
- Microsoft Xbox 360 gamepad
- ~~Microsoft Xbox One gamepad~~
- ~~Sony DualShok 3 gamepad~~
- ~~Sony DualShok 4 gamepad~~
- ~~Nintendo Switch gamepad~~

## Использование гироскопа
Гироскоп это современная фишка, которая может расширить игровой опыт.


Гироскоп может использоваться:
- Для более точного прицеливания в шутерах;
- Для управления автомобилем;
- Для управления стационарным пулеметом;

и так далее.

## Использование RGB-светодиода
RGB светодиод может добавить больше атмосферы игре. 


RGB-светодиод может использоваться:
- Для отображения уровня жизни (расный опасность, желтый внимание и зеленый все ок);
- Для Ambilight-а. Например, идете вы в игре по тунелю, а там включается сигнализация, в игре все красное и тут загорается светодиод геймпада и происходит Ambilight. В ночное время суток это точно прибавит атмосферы.

## Планы на будущее:
- Плагины для Unreal Engine 4 и Unity.

## Загрузка
>Версия для Windows 7, 8.1, 10

**[Загрузить](https://github.com/NexInput/Core/releases)**