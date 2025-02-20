#include <Servo.h>
#include <LiquidCrystal_I2C.h>

const uint8_t I2C_ADDRESS = 0x27;
const uint8_t LCD_CHAR = 16;
const uint8_t LCD_LINE = 2;
char *TITLE_ANGLE1 = "X: ";
char *TITLE_ANGLE2 = "Y: ";

LiquidCrystal_I2C lcd(I2C_ADDRESS, LCD_CHAR, LCD_LINE);


Servo myservo1;  // servo 1
Servo myservo2;  // servo 2

int pot1pin = A0;  // X
int pot2pin = A1;  // Y

unsigned int servo1Pin = 3; // servo 1 pin
unsigned int servo2Pin = 5; // servo 2 pin

unsigned int servo1AngleMin = 0; // servo 1 min angle
unsigned int servo1AngleMax = 90; // servo 1 max angle
unsigned int servo2AngleMin = 0; // servo 2 min angle
unsigned int servo2AngleMax = 90; // servo 2 max angle

unsigned int servo1Val = 0; // variable to read potentiometer 1
unsigned int servo2Val = 0; // variable to read potentiometer 2

unsigned int angle1 = 0; // current angle for servo 1
unsigned int angle2 = 0; // current angle for servo 2

void setup() {
 
  pinMode(13, OUTPUT);
  
  myservo1.attach(servo1Pin);  // attach servo 1 to its pin
  myservo2.attach(servo2Pin);  // attach servo 2 to its pin

  lcd.init();
  lcd.clear();         
  lcd.backlight();
  lcd.print("Valori X si Y:");
  lcd.setCursor(0, 1);
  lcd.print("X: ");
  lcd.setCursor(8, 1);
  lcd.print("Y: ");
  delay(2000); 

}

void loop() {
  
  digitalWrite(13, HIGH);
  servo1Val = analogRead(pot1pin); // read potentiometer 1 value
  servo2Val = analogRead(pot2pin); // read potentiometer 2 value
  sendServos(servo1Val, servo2Val); // send servo values
  
  //delay(20);
}

void sendServos(int value1, int value2) {
  unsigned int newAngle1 = map(value1, 0, 1023, servo1AngleMin, servo1AngleMax);
  unsigned int newAngle2 = map(value2, 0, 1023, servo2AngleMin, servo2AngleMax);

  if (angle1 != newAngle1) {
    myservo1.write(newAngle1);  
    lcdDisplay(newAngle1, angle2); // display servo 1 angle
    angle1 = newAngle1;
    //delay(100);  
  }

  if (angle2 != newAngle2) {
    myservo2.write(newAngle2);  
    lcdDisplay(angle1, newAngle2); // display servo 2 angle
    angle2 = newAngle2;
    //delay(100);  
  }
}

 void lcdDisplay(int angle1, int angle2) {
  clearCharacters();
  lcd.setCursor((unsigned)strlen(TITLE_ANGLE1), 1);
  lcd.print(angle1); // display angle 1
  lcd.print((char)223);

  
 
  lcd.setCursor((unsigned)strlen(TITLE_ANGLE1) + String(angle1).length() + 2, 1);
  lcd.print(TITLE_ANGLE2);
  lcd.print(angle2); // display angle 2
  lcd.print((char)223);

  //delay(100);
}

void clearCharacters() {
  for (int i = (unsigned)strlen(TITLE_ANGLE1)  - 1; i <= LCD_CHAR - 1; i++) {
    lcd.setCursor(i, 1); 
    lcd.write(254);
  } 
}
