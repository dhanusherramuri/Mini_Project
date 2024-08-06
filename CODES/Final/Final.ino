#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11);
LiquidCrystal_I2C lcd(0x27, 16, 2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
const int trig_1 = 2;
const int echo_1 = 3;
const int trig_2 = 4;
const int echo_2 = 5;
const int trig_3 = 6;
const int echo_3 = 7;
float distanceCM_1 = 0, resultCM_1 = 0;
float distanceCM_2 = 0, resultCM_2 = 0;
float distanceCM_3 = 0, resultCM_3 = 0;
long Time_1, Time_2, Time_3;
float car_1, car_2, car_3;
float Dist_1 = 8.0, Dist_2 = 8.0, Dist_3 = 8.0;
int total = 0, timer_cnt = 0;
void setup() {
  mySerial.listen();
  Serial.begin(2400);
  mySerial.begin(9600);
  pinMode(trig_1, OUTPUT);
  pinMode(trig_2, OUTPUT);
  pinMode(trig_3, OUTPUT);
  pinMode(echo_1, INPUT);
  pinMode(echo_2, INPUT);
  pinMode(echo_3, INPUT);
  digitalWrite(trig_1, LOW);
  digitalWrite(trig_2, LOW);
  digitalWrite(trig_3, LOW);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("  IoT CAR PARK");
  lcd.setCursor(0, 1);
  lcd.print(" MONITOR SYSTEM");
  delay(2000);
  lcd.clear();
}

void loop() {
  int analogValue = analogRead(A0);
  mySerial.print(analogValue);
  // Serial.println(mySerial.isListening());
  mySerial.print("Sent you");
  mySerial.write("Sent you");
  total = 0;
  car_1 = sensor_1();
  car_2 = sensor_2();
  car_3 = sensor_3();
  lcd.setCursor(0, 0);
  lcd.print("CAR1:");
  if (car_1 <= Dist_1) {
    lcd.print("OK ");
  } else {
    total += 1;
  }
  if (car_1 > Dist_1) lcd.print("NO ");
  lcd.print("CAR2:");
  if (car_2 <= Dist_2) {
    lcd.print("OK ");
  } else {
    total += 1;
  }
  if (car_2 > Dist_2) lcd.print("NO ");
  lcd.setCursor(0, 1);
  lcd.print("CAR3:");
  if (car_3 <= Dist_3) {
    lcd.print("OK ");
  } else {
    total += 1;
  }
  if (car_3 > Dist_3) lcd.print("NO ");
  lcd.print("FREE:");
  lcd.print(total);
  if (timer_cnt >= 50) {
    mySerial.print('*');
    mySerial.print(total);
    mySerial.println('#');
    timer_cnt = 0;
  }
  timer_cnt += 1;
  delay(200);
}

float sensor_1(void) {
  digitalWrite(trig_1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_1, LOW);
  Time_1 = pulseIn(echo_1, HIGH);
  distanceCM_1 = Time_1 * 0.034;
  return resultCM_1 = distanceCM_1 / 2;
}

float sensor_2(void) {
  digitalWrite(trig_2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_2, LOW);
  Time_2 = pulseIn(echo_2, HIGH);
  distanceCM_2 = Time_2 * 0.034;
  return resultCM_2 = distanceCM_2 / 2;
}

float sensor_3(void) {
  digitalWrite(trig_3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_3, LOW);
  Time_3 = pulseIn(echo_3, HIGH);
  distanceCM_3 = Time_3 * 0.034;
  return resultCM_3 = distanceCM_3 / 2;
}
//---------- Electronics-Project-Hub.com-----------------//
