# ZapperGamepad

Project to use an NES Zapper as a usb gamepad.
--

Using an arduino leonardo board to interpret zapper input, display to a tv, and emulate a gamepad

## The TV

Usually arduino sends the below 9 button display to a crt television through component video, using the TVout arduino library.

|A       |&#8593;  |B        |
|--------|---------|---------|
|&#8592; |&#99999; |&#8594;  |
|**C**   |&#8595;  |**D**    |

The display will beed to be modified for hit detection, and to display to the player, which buttons are set or reset.

This is acheived by combining the sync from pin 9 (in series with a 1k ohm resistor) and the signal from pin 8 (in sereis with a 470 ohm resistor).

## The Zapper

### Sensing light
The nintendo zapper will send trigger input and light sensor input to the arduino.

The zappper's light sensor will go high for 1 ms when it detects light. If the light detection lasts longer than 1ms then the pin will be set high for 1ms on both edges of the detection.
(The sensor has some more interaction that is more complicated but likely will not be relevant for this project).

### Hit detection

The the hit detection system used on the NES with this zapper is quite simple and will be the system that I try to reproduce in this project.

When the trigger of the zapper is pulled, the NES will clear the screen, and then, for each target on the screen, the NES will send a single frame with a white rectangle where the target would be and the rest of the screen is blank. If the zapper is pointed at a target the light sensor will sense light and send that information to the NES. The NES can factor in the constant delay of displaying a frame to a CRT and decide which target, if any, the zapper was pointed at based on when the light sensor first goes high after the trigger is set high.

This project will have a constant 9 targets (one for each button) that the system will check for when the trigger is pulled. Delays and time needed to be spent on each target will be determined experimentally.

## Gamepad

The gamepad emulation will be set using the ArduinoJoystickLibrary.

### Behavior

Currently I am considering three options for behavior of the gamepad buttons.

#### Option 1 (Toggles with universal release)

In this option each button will set or reset when shot. (EX. If "A" is currently reset, if the player shoots it, it will be set until it is shot again)

In this option the middle button would be used as a universal reset, to reset all 8 exterior buttons when shot.

#### Option 2 (Momentary Switches)

In this option each button will always be reset until shot.

When a button is shot it will be set for as long as the zapper pointed at it.
Alternativley the button will be maintained for as long as the trigger remained pulled.

Both of these options present some complexity.

In the case of "pointing to mainatin" the behavior of the light sensor may make the process very simple. For a long light duration, the detection signal will be set high on both the rising and falling edge of the light durration. This means that we can simply set the button on the first instance of the detect pin going hihg, and reset it on the second instance.

In the case of "holding the trigger to maintain" the behavior of the physical trigger will present a problem. On the original Zapper, the trigger is only set high partway through the pull, when the player completes the trigger pull, the trigger signal is reset to low. This means it may be impossible to use this method.


#### Option 3 (Temporary latch)

In this option each button is normally reset. When a button is shot it will be set high for some amount of time before it goes low again.
This reset timer will reset if the button is shot again while it is already set.
