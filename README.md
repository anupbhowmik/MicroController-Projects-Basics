# MicroController-Projects-Basics-CSE-316

# Contents
- `C` Codes that can be compiled in `Mircrochip Studio` to generate `hex files`. The hex files can be burned into any `ATMega32`
-  Simulation projects that can be simulated in `Proteus`

## Simple Counter
This counter automatically counts from 0 to 15 and then resets. Shows the binary equivalent in the form of LEDs

## Analog Input
Takes analog input from `LM35` and converts it into temperature. When the temperature is above or equal to 20 degree celcius, it turns on PB0 as an alarm


## A Universal Image Creator and Shifter for `8x8 LED Matrix`

I have tried to make the code reusable for any purpose (any image can be created simply by adjusting two arrays: one for rows and another for column configurations). The image can be shifted left-right-up-down by passing a parameter while calling the function.
Hope it helps. Thank you.

The C code can be used in `ATMEGA32` or similar Microcontroller.
