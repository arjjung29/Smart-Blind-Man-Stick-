#include <SoftwareSerial.h>
SoftwareSerial mySerial1 (D5, D6); // LEFT RIGHT FRONT AND BOTTOM  
SoftwareSerial mySerial2 (D1, D4); // LEFT RIGHT
char a;
char b;

int left_vib = D2;
int right_vib = D3;
int front_bottom_vib = D7;

void setup() {


  Serial.begin(9600);
  pinMode(left_vib, OUTPUT);
  pinMode(right_vib, OUTPUT);
  pinMode(front_bottom_vib, OUTPUT);
  
  
  mySerial1.begin(9600);
  mySerial2.begin(9600);
}

void loop() {
  
  
  a = mySerial1.read();
  b = mySerial2.read();
  //Serial.println(b);
  //if (mySerial.available()){
    if (a=='1'){
      Serial.println("OBSTACLE DETECTED @ FRONT !");
      digitalWrite(front_bottom_vib, HIGH);
      delay(1000);
      digitalWrite(front_bottom_vib, LOW);
      delay(100);
    }
    if (a=='2' || b=='2'){
      Serial.println("OBSTACLE DETECTED @ LEFT !");
      digitalWrite(left_vib, HIGH);
      delay(1000);
      digitalWrite(left_vib, LOW);      
      delay(100);
    }
    if (a=='3' || b=='3'){
      Serial.println("OBSTACLE DETECTED @ RIGHT !");
      digitalWrite(right_vib, HIGH);
      delay(1000);
      digitalWrite(right_vib, LOW);      
      delay(100);
    }
    if (a=='4'){
      Serial.println("PIT !");
      digitalWrite(front_bottom_vib, HIGH);
      delay(1000);
      digitalWrite(front_bottom_vib, LOW);
      delay(100);
    }
 // }

}
