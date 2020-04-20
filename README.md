# Keyboard simulation with a Pro Micro

What?
--------
Make a Pro Micro with ATmega32U4 send key strokes using push buttons.

Uses `Keyboard.press` and `Keyboard.release` to support holding a button.

Why?
----
I needed a few buttons to use things like push to talk when using my turbo trainer.

Simplest solution: Put a keyboard next to the trainer.

Programmer solution: Use a Pro Micro with a ATmega32U4 chip to act as a simple keyboard and velcro push buttons to the handle bars.

How?
----
1. Download and install the Arduino software
2. Connect the Pro Micro via USB
3. Select Arduino Micro or Leonardo as Board
4. Open the *.ino code file
5. Customize the buttons array
6. Upload it
7. Connect buttons to GND and a numbered pin
8. Press the buttons!
