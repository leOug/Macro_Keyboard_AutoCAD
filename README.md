# Macro_Keyboard_AutoCAD
This is a shortcuts/macro keyboard intended for AutoCAD.


It can be expanded in order to be used with other programs.
I use an Arduino Leonardo Pro Micro ATmega32U4 5V 16MHz with the Keyboard.h library,
in order to send phrases (AutoCAD commands) and press Enter (KEY_RETURN) after a few miliseconds.

Also there is an RGB LED for indicating purposes. The LED can be substitcuted for three extra buttons or potentiometers although
it is rather usefull as it is.

The buttons were chosen for aesthetic and practical purposes. The Arcade button and the Microswitch were chosen for their clickiness
while the toggle switch (selector) is a three terminal one so that is has two modes of operation.

Each Button is connected to GND through a 10K Resistor and to a numbered PIN of the arduino
The toggle switch has three terminals, the left is connected to GND of the Arduino directly, the middle one is connected to a 
numbered arduino PIN and the right one is connected to VCC of the Arduino.

Materials Used:

* 1 x Arduino Leonardo Pro Micro ATmega32U4 5V 16MHz

* 1 x Toggle Switch SPDT ON-ON Mini

* 1 x Arcade Push Button Mini 27mm

* 1 x Microswitch Mini SPDT ON-(ON) - with Roller Simulation (the ones used in 3D printers and CNC machines)

* 2 x Tactile Switch 6x6mm 5mm 4pins

* 7 x Tactile Switch 12x12mm 4.3mm

* 1 x B100K Potentiometer

* 12 x 10KΩhm Resistors for the buttons

* 3 x 220Ωhm Resistors for the LED

* 1 x male micro USB header

* 1 x Female USB type B header

* 1 x perf board

* 4 x M.2 screws

* Super Glue

* Nail Polish for basic water resistance

* Some length of wire

I designed the casing according to the dimensions of the buttons and a vague notion of ergonomics.

You are free to use the design and the code for personal non-commercial usage.

