#include <TinyGPS++.h>
#include <SoftwareSerial.h>
/*
This sample sketch demonstrates the normal use of a TinyGPS++ (TinyGPSPlus) object.
It requires the use of SoftwareSerial, and assumes that you have a
4800-baud serial GPS device hooked up on pins 4(rx) and 3(tx).
*/
static const int RXPin = D5, TXPin = D6;
static const uint32_t GPSBaud = 9600; //Default baud rate of Neo6M is 9600

// The TinyGPS++ object
TinyGPSPlus gps;

// The serial connection to the GPS device
SoftwareSerial ss(RXPin, TXPin);
SoftwareSerial GSM(D2,D3, false);

float latitude;
float longitude;
int vib_sensor = D1;
int light_sensor = D7;
int vib_val =1;
int light_val = 0;
char phone_no[]= "+916369727213";

void setup()
{
Serial.begin(9600);
ss.begin(GPSBaud);
pinMode(vib_sensor, INPUT);
GSM.begin(9600);
Serial.println("Initializing....");
//initModule("AT", "OK", 1000);

}

void loop()
{
// This sketch displays information every time a new sentence is correctly encoded.

while (ss.available() > 0)
if (gps.encode(ss.read()))
displayInfo();

if (millis() > 5000 && gps.charsProcessed() < 10)
{
Serial.println(F("No GPS detected: check wiring."));
while(true);
}

vib_val = digitalRead(vib_sensor);
if (vib_val == 0){
  //displayInfo();
  Serial.print(latitude, 6);
  Serial.print(F(","));
  Serial.print(longitude, 6);
  delay(1000);
  sms();
  callUp(phone_no);
  delay(1000);    
}

light_val = digitalRead(light_sensor);
if (light_val == 1){
  Serial.println("Light Detected !!!");
  delay(100);
}

}

void displayInfo()
{
//Serial.print(F("Location: "));
if (gps.location.isValid())
{
latitude = gps.location.lat();
longitude = gps.location.lng();
//Serial.print(gps.location.lat(), 6);
//Serial.print(F(","));
//Serial.print(gps.location.lng(), 6);
}
//else
//{
//Serial.print(F("INVALID"));
//Serial.print("\n");
//}


//Serial.print(F(" Date/Time: "));
//if (gps.date.isValid())
//{
//Serial.print(gps.date.month());
//Serial.print(F("/"));
//Serial.print(gps.date.day());
//Serial.print(F("/"));
//Serial.print(gps.date.year());
//}
//else
//{
//Serial.print(F("INVALID"));
//}

/*
Serial.print(F(" "));
if (gps.time.isValid())
{
if (gps.time.hour() < 10) Serial.print(F("0"));
Serial.print(gps.time.hour());
Serial.print(F(":"));
if (gps.time.minute() < 10) Serial.print(F("0"));
Serial.print(gps.time.minute());
Serial.print(F(":"));
if (gps.time.second() < 10) Serial.print(F("0"));
Serial.print(gps.time.second());
Serial.print(F("."));
if (gps.time.centisecond() < 10) Serial.print(F("0"));
Serial.print(gps.time.centisecond());
}
else
{
Serial.print(F("INVALID"));
}

Serial.println();


*/
}

void callUp(char *number){
  Serial.println("Calling....");
  GSM.print("ATD + "); GSM.print(number); GSM.println(";");
  delay(20000);
  GSM.println("ATH");
  delay(100);
}

void initModule(String cmd, char *res, int t){
  while(1){
    Serial.println(cmd);
    GSM.println(cmd);
    delay(100);
    while (GSM.available() > 0){
      if (GSM.find(res)){
        Serial.println(res);
        delay(t);
        return;
      } else {
        Serial.println("ERROR");
      }
    }
  }
}

void sms(){
  Serial.println("Sending SMS....");
  GSM.print("AT+CMGF=1\r");
  delay(100);
  GSM.print("AT+CMGS=\"+916369727213\"\r");
  delay(500);
  //GSM.print(latitude,longitude);
  GSM.print("This is a Test Message !");
  delay(100);
  Serial.println("SMS Sent....");
  delay(500);

}  