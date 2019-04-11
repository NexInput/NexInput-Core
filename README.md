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
Nex Input is an new modern standard for gamepads which makes it possible to use a gyroscope and RGB-LED. The standard has a simple API that allows to access all popular gamepads.

- For developers games: [samples demo](https://github.com/NexInput/Samples), [docs](https://github.com/NexInput/Core/tree/master/Docs) and recommendations for [using a gyroscope and an RGB LED](https://github.com/NexInput/Core/blob/master/Docs/EN/Recommendations/Games.md) in games.
- For developers drivers for gamepad: [sample driver](https://github.com/NexInput/Sample-driver).
- Send your fixes, improvements, samples, demos, translations or etc.
- Write your offers and feature requests through "Issue" or email.
- Become the developer of the standard.


## Principle of operation:
If the user does not have the "Nex Input" package installed, then the integrated library is used, which translates calls into the standard "XInput".

If the user uses an outdated gamepad, without a gyroscope, then the API returns the status without a gyroscope.

## Supported hardware
- ~~Microsoft Xbox 360 gamepad~~
- ~~Microsoft Xbox One gamepad~~
- ~~Sony DualShok 3 gamepad~~
- ~~Sony DualShok 4 gamepad~~
- ~~Nintendo Switch gamepad~~

## Using the gyroscope
Gyroscope is a modern feature that can enhance the gaming experience.


Gyroscope can be used:
- For more accurate aiming in shooters;
- To drive a car;
- To control a stationary machine gun;

and so on.

## Using RGB LED
RGB LED can add more atmosphere to the game.


RGB LED can be used:
- To display the level of life (red danger, yellow attention and green all ok);
- For Ambilight. For example, you go in the game through the tunnel, and then the alarm is turned on, the game turns red and the gamepad LED lights up and Ambilight happens. At night, it definitely adds to the atmosphere.

## Future plans:
- Plugins for Unreal Engine 4 and Unity.


## Download
>Version for Windows 7, 8.1, 10

**[Download](https://github.com/NexInput/Core/releases)**