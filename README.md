# Nodemcu-ESP8266-OLED-DevBoard-Joystick
This all-in-one board form factor had very limited documentation at the time this repo as created.
So I researched widely and came up with a template for responding to the joystick movements.
The RIGHT movement on the joystick is reserver as a Reset operation.
The LEFT is usually reserved for flashing mode.   
However I was reflashing directly via USB connector from the Arduino IDE so I also mapped that too.

This template shows how UP, DOWN, IN (pressing the joystick) and LEFT can be mapped to action functions.
The template also shows how to configure the onboard OLED.
