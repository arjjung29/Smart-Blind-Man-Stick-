#include <SoftwareSerial.h>

int right1_sensor = D5;
int right2_sensor = D6;
int left1_sensor = D7;
int left2_sensor = D2;
int right1_val = 0;
int right2_val =0;
int left1_val =0;
int left2_val=0;
int power_IR = D0;
SoftwareSerial mySerial (D3, D4, false);


void setup() {
  pinMode(right1_sensor, INPUT);
  pinMode(right2_sensor, INPUT);
  pinMode(left1_sensor, INPUT);
  pinMode(left2_sensor, INPUT);
  pinMode(power_IR, OUTPUT);
  digitalWrite(power_IR, HIGH);
  Serial.begin(9600);
  mySerial.begin(9600);

}

void loop() {
  right1_val = digitalRead(right1_sensor);
  right2_val = digitalRead(right2_sensor);
  left1_val = digitalRead(left1_sensor);
  delay(100);
  left2_val = digitalRead(left2_sensor);
  delay(100);
  if (right1_val == LOW){
    Serial.println("OBSTACLE DETECTED @ RIGHT !");
    mySerial.println('3');
    delay(1000);
    delay(100);
  }
  if (right2_val == LOW){
    Serial.println("OBSTACLE DETECTED @ RIGHT !");
    mySerial.println('3');
    delay(1000);
    delay(100);
  }
  if (left1_val == LOW){
    Serial.println("OBSTACLE DETECTED @ LEFT !");
    mySerial.println('2');
    delay(1000);
    delay(100);
  }
  if (left2_val == LOW){
    Serial.println("OBJECT DETECTEC @ LEFT !");
    mySerial.println('2');
    delay(1000);
    delay(100);
  }

}