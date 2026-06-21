#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;
int reply;

void setup() {
  lcd.begin(16, 2);
  pinMode(switchPin, INPUT);
  lcd.print("Ask the");
  lcd.setCursor(0,1);
  lcd.print("Crystal Ball!");
}

void loop() {
  switchState = digitalRead(switchPin);
  if (switchState != prevSwitchState){
    if(switchState == LOW){
        reply = random(8);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Balls verdict:");
        lcd.setCursor(0, 1);
        switch(reply){
          case 0:
          lcd.print("Yes");
          break;
          case 1:
          lcd.print("Probably");
          break;
          case 2:
          lcd.print("For sure");
          break;
          case 3:
          lcd.print("Slim chances");
          break;
          case 4:
          lcd.print("Unsure");
          break;
          case 5:
          lcd.print("Ask again");
          break;
          case 6:
          lcd.print("Probably not");
          break;
          case 7:
          lcd.print("No");
          break;
        }
    }
  }
  prevSwitchState = switchState;
}
