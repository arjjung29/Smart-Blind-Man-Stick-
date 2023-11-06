#include <SoftwareSerial.h>

int front_sensor = D5;
int left_sensor = D6;
int right_sensor = D7;
int bottom_sensor = D2;
int front_val = 0;
int left_val =0;
int right_val =0;
int bottom_val=0;
int power_IR = D0;
SoftwareSerial mySerial (D3, D4, false);


void setup() {
  pinMode(front_sensor, INPUT);
  pinMode(left_sensor, INPUT);
  pinMode(right_sensor, INPUT);
  pinMode(bottom_sensor, INPUT);
  pinMode(power_IR, OUTPUT);
  

  digitalWrite(power_IR, HIGH);
  Serial.begin(9600);
  mySerial.begin(9600);

}

void loop() {
  front_val = digitalRead(front_sensor);
  left_val = digitalRead(left_sensor);
  right_val = digitalRead(right_sensor);
  delay(100);
  bottom_val = digitalRead(bottom_sensor);
  delay(100);
  if (front_val == LOW){
    Serial.println("OBSTACLE DETECTED @ FRONT !");
    mySerial.println('1');
    
    delay(1000);
  }
  if (left_val == LOW){
    Serial.println("OBSTACLE DETECTED @ LEFT !");
    mySerial.println('2');
    
    delay(1000);
  }
  if (right_val == LOW){
    Serial.println("OBSTACLE DETECTED @ RIGHT !");
    mySerial.println('3');
    
    delay(1000);
  }
  if (bottom_val == HIGH){
    Serial.println("PIT !");
    mySerial.println('4');
    
    delay(1000);
  }

}