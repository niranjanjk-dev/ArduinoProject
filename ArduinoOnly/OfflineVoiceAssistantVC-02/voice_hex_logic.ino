#include <SoftwareSerial.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// --- HARDWARE CONFIGURATION ---
SoftwareSerial voiceSerial(2, 3); // RX (Pin 2), TX (Pin 3)
LiquidCrystal_I2C lcd(0x27, 16, 2); 

// --- PINS ---
#define RED_PIN 4
#define GREEN_PIN 5
#define BLUE_PIN 6
#define FAN_PIN 7

void setup() {
  // 1. Initialize Serial for PC Monitor (Debugging)
  Serial.begin(9600);
  
  // 2. Initialize Voice Module
  voiceSerial.begin(9600);
  
  // 3. Initialize Output Pins
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(FAN_PIN, OUTPUT);
  
  // 4. Initialize LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("System Ready");
  
  Serial.println("--- SYSTEM STARTED ---");
  Serial.println("Waiting for data from Voice Module...");
}

void loop() {
  // Check if data is coming from the Voice Module
  if (voiceSerial.available()) {
    
    // Read the incoming byte (Since your codes are 11, 21, etc., we only need 1 byte)
    byte receivedValue = voiceSerial.read();
    
    // --- PRINT DEBUG INFO (Like your screenshot) ---
    Serial.println("Data From Module");
    Serial.print("Received HEX value: 0x");
    Serial.println(receivedValue, HEX);
    
    // --- LOGIC FOR YOUR COMMANDS ---
    
    // 1. RED LIGHT (11 = ON, 10 = OFF)
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
    
    // 2. GREEN LIGHT (21 = ON, 20 = OFF)
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
    
    // 3. BLUE LIGHT (31 = ON, 30 = OFF)
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
    
    // 4. FAN (41 = ON, 40 = OFF)
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
    
    // 5. LCD BACKLIGHT (51 = ON, 50 = OFF)
    else if (receivedValue == 0x51) {
       lcd.backlight();
       Serial.println("Action: LCD Backlight ON");
    }
    else if (receivedValue == 0x50) {
       lcd.noBacklight();
       Serial.println("Action: LCD Backlight OFF");
    }

    // 6. ALL LIGHTS OFF (60)
    else if (receivedValue == 0x60) {
       digitalWrite(RED_PIN, LOW);
       digitalWrite(GREEN_PIN, LOW);
       digitalWrite(BLUE_PIN, LOW);
       Serial.println("Action: All Lights OFF");
       updateLCD("All Lights OFF");
    }

    // 7. SYSTEM SHUTDOWN (70)
    // Turns off Lights, Fan, and Clears Screen (keeps backlight on per request)
    else if (receivedValue == 0x70) {
       digitalWrite(RED_PIN, LOW);
       digitalWrite(GREEN_PIN, LOW);
       digitalWrite(BLUE_PIN, LOW);
       digitalWrite(FAN_PIN, LOW);
       lcd.clear(); // Clear the text
       Serial.println("Action: System Shutdown");
    }

    // 8. LCD SHUTDOWN (80)
    // Just clears the screen text
    else if (receivedValue == 0x80) {
       lcd.clear(); 
       Serial.println("Action: LCD Cleared");
    }
  }
}

// Helper function to update the screen text
void updateLCD(String text) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Voice Command:");
  lcd.setCursor(0, 1);
  lcd.print(text);
}