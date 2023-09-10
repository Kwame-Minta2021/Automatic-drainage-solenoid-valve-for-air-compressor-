#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// define pin for relay
#define RELAY_PIN 2

// define pins for buttons
#define BUTTON1_PIN 3
#define BUTTON2_PIN 6
#define BUTTON3_PIN 5

// define pins for LEDs
#define RED_LED_PIN 7
#define GREEN_LED_PIN 8

// initialize LCD display with I2C address and size
LiquidCrystal_I2C lcd(0x27,20,4);

// variable for valve open time
int valveOpenTime = 3000; // default value (3 seconds)

void setup() {
  // set up relay pin as output
  pinMode(RELAY_PIN, OUTPUT);

  // set up button pins as inputs with internal pull-up resistors
  pinMode(BUTTON1_PIN, INPUT_PULLUP);
  pinMode(BUTTON2_PIN, INPUT_PULLUP);
  pinMode(BUTTON3_PIN, INPUT_PULLUP);

  // set up LED pins as outputs
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);

  // set up LCD display
  lcd.begin();
}

void loop() {
  // check button states and update valve open time accordingly
  if (digitalRead(BUTTON1_PIN) == LOW) {
    valveOpenTime = 3000; // set valve open time to 3 seconds when button1 is pressed
    lcd.setCursor(0,0);
    lcd.print("Selected time: ");
    lcd.print(valveOpenTime/1000);
    lcd.print(" sec ");
    delay(1000);
    
    // update LCD display with countdown timer
    for (int i = valveOpenTime/1000; i > 0; i--) {
      lcd.setCursor(0,1);
      lcd.print("Countdown: ");
      lcd.print(i);
      lcd.print(" sec ");
      delay(1000);
    }
    
    // open solenoid valve for selected time
    digitalWrite(RELAY_PIN, HIGH);
    digitalWrite(RED_LED_PIN, HIGH); // turn on red LED to indicate valve is open
    digitalWrite(GREEN_LED_PIN, LOW); // turn off green LED
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Valve open");
    delay(valveOpenTime);
    digitalWrite(RELAY_PIN, LOW);
    digitalWrite(RED_LED_PIN, LOW); // turn off red LED
    digitalWrite(GREEN_LED_PIN, HIGH); // turn on green LED to indicate valve is closed
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Valve closed");
    
  } 
  
  if (digitalRead(BUTTON2_PIN) == LOW) {
    valveOpenTime = 5000; // set valve open time to 5 seconds when button2 is pressed
    lcd.setCursor(0,0);
    lcd.print("Selected time: ");
    lcd.print(valveOpenTime/1000);
    lcd.print(" sec ");
    delay(1000);
    
     // update LCD display with countdown timer
     for (int i = valveOpenTime/1000; i > 0; i--) {
       lcd.setCursor(0,1);
       lcd.print("Countdown: ");
       lcd.print(i);
       lcd.print(" sec ");
       delay(1000);
     }
     
     // open solenoid valve for selected time
     digitalWrite(RELAY_PIN, HIGH);
     digitalWrite(RED_LED_PIN, HIGH); // turn on red LED to indicate valve is open
     digitalWrite(GREEN_LED_PIN, LOW); // turn off green LED
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("Valve open");
     delay(valveOpenTime);
     digitalWrite(RELAY_PIN, LOW);
     digitalWrite(RED_LED_PIN, LOW); // turn off red LED
     digitalWrite(GREEN_LED_PIN, HIGH); // turn on green LED to indicate valve is closed
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("Valve closed");
     
   }
   
   if (digitalRead(BUTTON3_PIN) == LOW) {
     valveOpenTime = 10000; // set valve open time to 10 seconds when button3 is pressed
     lcd.setCursor(0,0);
     lcd.print("Selected time: ");
     lcd.print(valveOpenTime/1000);
     lcd.print("sec ");
     
    // update LCD display with countdown timer
    for (int i = valveOpenTime/1000; i > 0; i--) {
      lcd.setCursor(0,1);
      lcd.print("Countdown: ");
      lcd.print(i);
      lcd.print(" sec ");
      delay(1000);
    }
    
    // open solenoid valve for selected time
    digitalWrite(RELAY_PIN, HIGH);
    digitalWrite(RED_LED_PIN, HIGH); // turn on red LED to indicate valve is open
    digitalWrite(GREEN_LED_PIN, LOW); // turn off green LED
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Valve open");
    delay(valveOpenTime);
    digitalWrite(RELAY_PIN, LOW);
    digitalWrite(RED_LED_PIN, LOW); // turn off red LED
    digitalWrite(GREEN_LED_PIN, HIGH); // turn on green LED to indicate valve is closed
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Valve closed");
   }
}
