#include <SoftwareSerial.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

SoftwareSerial voiceSerial(2, 3); 
LiquidCrystal_I2C lcd(0x27, 16, 2); 

#define RED_PIN 4
#define GREEN_PIN 5
#define BLUE_PIN 6
#define FAN_PIN 7

void setup() {
  
  Serial.begin(9600);
  

  voiceSerial.begin(9600);

  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(FAN_PIN, OUTPUT);
  

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("System Ready");
  
  Serial.println("--- SYSTEM STARTED ---");
  Serial.println("Waiting for data from Voice Module...");
}

void loop() {
  
  if (voiceSerial.available()) {
    
    
    byte receivedValue = voiceSerial.read();
    
    
    Serial.println("Data From Module");
    Serial.print("Received HEX value: 0x");
    Serial.println(receivedValue, HEX);
    
    /
    if (receivedValue == 0x11) {
       digitalWrite(RED_PIN, HIGH);
       Serial.println("Action: Red ON");
       updateLCD("Red Light ON");
    }
    else if (receivedValue == 0x10) {
       digitalWrite(RED_PIN, LOW);
       Serial.println("Action: Red OFF");
       updateLCD("Red Light OFF");
    }
    
    
    else if (receivedValue == 0x21) {
       digitalWrite(GREEN_PIN, HIGH);
       Serial.println("Action: Green ON");
       updateLCD("Green Light ON");
    }
    else if (receivedValue == 0x20) {
       digitalWrite(GREEN_PIN, LOW);
       Serial.println("Action: Green OFF");
       updateLCD("Green Light OFF");
    }
    
    
    else if (receivedValue == 0x31) {
       digitalWrite(BLUE_PIN, HIGH);
       Serial.println("Action: Blue ON");
       updateLCD("Blue Light ON");
    }
    else if (receivedValue == 0x30) {
       digitalWrite(BLUE_PIN, LOW);
       Serial.println("Action: Blue OFF");
       updateLCD("Blue Light OFF");
    }
    
    
    else if (receivedValue == 0x41) {
       digitalWrite(FAN_PIN, HIGH);
       Serial.println("Action: Fan ON");
       updateLCD("Fan STARTED");
    }
    else if (receivedValue == 0x40) {
       digitalWrite(FAN_PIN, LOW);
       Serial.println("Action: Fan OFF");
       updateLCD("Fan STOPPED");
    }
    
    
    else if (receivedValue == 0x51) {
       lcd.backlight();
       Serial.println("Action: LCD Backlight ON");
    }
    else if (receivedValue == 0x50) {
       lcd.noBacklight();
       Serial.println("Action: LCD Backlight OFF");
    }

    
    else if (receivedValue == 0x60) {
       digitalWrite(RED_PIN, LOW);
       digitalWrite(GREEN_PIN, LOW);
       digitalWrite(BLUE_PIN, LOW);
       Serial.println("Action: All Lights OFF");
       updateLCD("All Lights OFF");
    }

    
    else if (receivedValue == 0x70) {
       digitalWrite(RED_PIN, LOW);
       digitalWrite(GREEN_PIN, LOW);
       digitalWrite(BLUE_PIN, LOW);
       digitalWrite(FAN_PIN, LOW);
       lcd.clear(); 
       Serial.println("Action: System Shutdown");
    }

    
    else if (receivedValue == 0x80) {
       lcd.clear(); 
       Serial.println("Action: LCD Cleared");
    }
  }
}

// THe function which is used to display text on screen 
void updateLCD(String text) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Voice Command:");
  lcd.setCursor(0, 1);
  lcd.print(text);
}
