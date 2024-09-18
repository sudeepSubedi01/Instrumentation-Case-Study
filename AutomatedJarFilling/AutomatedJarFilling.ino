#include <LiquidCrystal.h>

// Initialize the LCD with the pins used for the connection
LiquidCrystal lcd(2, 3, 4, 5, 6, 7); 

const int trigPin = 12; 
const int echoPin = 13; 
const int ledPin = 8; 

void setup() { 
  // Initialize the LCD
  lcd.begin(16, 2); 
  
  // Set up the sensor pins
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  
  // Set up the LED pin
  pinMode(ledPin, OUTPUT); 
  digitalWrite(ledPin, HIGH); // Turn on the LED initially (nozzle on)
  
  lcd.print("Water Level:"); 
}

void loop() { 
  long duration; 
  int distance; 
  int maxDistance = 200; // Maximum distance for the water level measurement
  int waterLevel; 

  // Clear the trigPin by setting it LOW
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);

  // Trigger the sensor by setting the trigPin HIGH for 10 microseconds
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW); 

  // Read the echoPin, which returns the signal duration in microseconds
  duration = pulseIn(echoPin, HIGH); 

  // Calculate the distance in centimeters
  distance = duration * 0.034 / 2;

  // Map the distance to water level (1 to 5 or full)
  if (distance < maxDistance) { 
    waterLevel = map(distance, 0, maxDistance, 5, 0); 
  } else { 
    waterLevel = 0; // No water detected
  } 

  // Clear the LCD and display the water level
  lcd.setCursor(0, 1); 
  if (waterLevel == 5) { 
    lcd.print("Full "); 
    digitalWrite(ledPin, LOW); // Turn off the LED (nozzle off)
  } else if (waterLevel == 0) { 
    lcd.print("Empty "); 
    digitalWrite(ledPin, HIGH); // Turn on the LED (nozzle on)
  } else { 
    lcd.print("Level: "); 
    lcd.print(waterLevel); 
    lcd.print(" "); 
    digitalWrite(ledPin, HIGH); // Turn on the LED (nozzle on)
  } 
  // Delay before taking the next measurement
  delay(1000); 
}
