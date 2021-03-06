#include <Keyboard.h>

// Special keys.
#define KEY_LEFT_CTRL   0x80
#define KEY_LEFT_SHIFT  0x81
#define KEY_LEFT_ALT    0x82
#define KEY_LEFT_GUI    0x83
#define KEY_RIGHT_CTRL  0x84
#define KEY_RIGHT_SHIFT 0x85
#define KEY_RIGHT_ALT   0x86
#define KEY_RIGHT_GUI   0x87
#define KEY_UP_ARROW    0xDA
#define KEY_DOWN_ARROW  0xD9
#define KEY_LEFT_ARROW  0xD8
#define KEY_RIGHT_ARROW 0xD7
#define KEY_BACKSPACE   0xB2
#define KEY_TAB         0xB3
#define KEY_RETURN      0xB0
#define KEY_ESC         0xB1
#define KEY_INSERT      0xD1
#define KEY_DELETE      0xD4
#define KEY_PAGE_UP     0xD3
#define KEY_PAGE_DOWN   0xD6
#define KEY_HOME        0xD2
#define KEY_END         0xD5
#define KEY_CAPS_LOCK   0xC1
#define KEY_F1          0xC2
#define KEY_F2          0xC3
#define KEY_F3          0xC4
#define KEY_F4          0xC5
#define KEY_F5          0xC6
#define KEY_F6          0xC7
#define KEY_F7          0xC8
#define KEY_F8          0xC9
#define KEY_F9          0xCA
#define KEY_F10         0xCB
#define KEY_F11         0xCC
#define KEY_F12         0xCD

struct Button {
  int Pin;
  char Char;
  bool Pressed;
};

// Input pins.
Button buttons[] =
{
  {2, 'a', false},
  {3, 'b', false},
  {4, KEY_UP_ARROW, false},
  {5, KEY_DOWN_ARROW, false},
  {6, KEY_LEFT_ARROW, false},
  {7, KEY_RIGHT_ARROW, false},
  {8, KEY_F1, false},
  {9, KEY_F12, false}
};

int buttonCount = sizeof(buttons) / sizeof(Button);

void setup() {

  // Set the buttons as an input and pull high
  for (int i = 0; i < buttonCount; i++)
  {
    pinMode(buttons[i].Pin, INPUT_PULLUP);
  }

  Keyboard.begin();
}

void loop() {
  for (int i = 0; i < buttonCount; i++)
  {
    Button* currentButton = &buttons[i];
    bool pinLow = digitalRead(currentButton->Pin) == LOW;

    if (!currentButton->Pressed && pinLow)
    {
      Keyboard.press(currentButton->Char);
      currentButton->Pressed = true;
      delay(50);
    }
    else if (currentButton->Pressed && !pinLow)
    {
      Keyboard.release(currentButton->Char);
      currentButton->Pressed = false;
      delay(50);
    }
  }
}
