#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Address 0x27, 16 columns and 2 rows

#define trigPin1 2
#define echoPin1 3
#define trigPin2 4
#define echoPin2 5
#define trigPin3 6
#define echoPin3 7

long duration;
int distance1, distance2, distance3;

void setup() {
  Serial.begin(9600);
  
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);

  lcd.init(); // initialize the lcd 
  lcd.backlight(); // turn on backlight
}

void loop() {
  // Read the first ultrasonic sensor
  distance1 = getDistance(trigPin1, echoPin1);
  // Read the remaining ultrasonic sensors and display readings in Serial Monitor
  distance2 = getDistance(trigPin2, echoPin2);
  distance3 = getDistance(trigPin3, echoPin3);
  
  // Display the first reading on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("D1:");
  lcd.print(distance1);
  lcd.print("cm");
  
  lcd.setCursor(9,0);
  lcd.print("D2:");
  lcd.print(distance2);
  lcd.print("cm");
    lcd.setCursor(0, 1);
  lcd.print("D3:");
  lcd.print(distance3);
  lcd.print("cm");
  Serial.print("Distance 2: ");
  Serial.print(distance2);
  Serial.println(" cm");
  Serial.print("Distance 3: ");
  Serial.print(distance3);
  Serial.println(" cm");

  delay(1000);
}

int getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;
  return distance;
}
