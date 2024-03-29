/* This code allows a car to run on its own by using 2 modules. The car also works as a crash avoidance so that if
 *  it detects a obstical then the car will stop and move away from it.
 */
#include <SoftwareSerial.h>
#include <SD.h>
SoftwareSerial mySerial(2, 3);
int Sen1= A0;                    // First Analog Sensor
int Sen2= A1;                    // Second Analog Sensor
int MotorA= 8;                   
int MotorB= 9;
int frontright= 7;
int backright= 6;
int frontleft= 5;
int backleft= 4;
int CS_PIN= 10;
int leftsensor;
int rightsensor;
int turn_speed=100;               //MAX 255
int turn_delay=10;
int velocity= 15;
int turn_velocity= 100;
const int xpin= A5;                // Analog pin for y axis
const int ypin= A4;                // analog pin for x-axis
int timenow;
int xRawMin;
int xRawMax;
int xRaw;
int yRawMin;
int yRawMax;
int yRaw;
int trigPin= 13;                  // Sensor for trig pin
int echoPin= 12;                  // Sensor for Echo pin
char Movement;
long Receive, Distance;

void setup()
{
pinMode(backleft, OUTPUT);
pinMode(frontleft, OUTPUT);
pinMode(backright, OUTPUT);
pinMode(frontright, OUTPUT);
pinMode(CS_PIN, OUTPUT);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);


mySerial.begin(9600);
Serial.begin(9600);
void LineTracker();
void BT();
}
void loop()
{
digitalWrite(trigPin, LOW);        //Set trigger pin low
delayMicroseconds(2);              //Let signal settle
digitalWrite(trigPin, HIGH);       //Set trigPin high
delayMicroseconds(15);             //Delay in high state
Receive = pulseIn(echoPin, HIGH);  // Recieves data
Distance = Receive / 58.2;         // Converts data into distance
delay(15);

if (Distance >19)              // lINE TRACKER
  {
    LineTracker();
  }
else if(Distance <19)           //bt
  {
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);  
   BT;                          
  }

timenow = millis();                   // Measure acceleration in Gs
Serial.print(xRaw);     Serial.print(", ");
Serial.print(yRaw);     Serial.print(", ");
    
    // Convert raw values to 'milli-Gs"
long xScaled = map(xRaw, xRawMin, xRawMax, -1000, 1000);
long yScaled = map(yRaw, yRawMin, yRawMax, -1000, 1000);
  
    // re-scale to fractional Gs
float xAccel = xScaled / 1000.0;
float yAccel = yScaled / 1000.0;

Serial.print(" :: ");
Serial.print(xAccel);    Serial.print("Acceleration in G, ");
Serial.print(yAccel);    Serial.print("Acceleration in G, ");

File datafile= SD.open("Accel.csv",FILE_WRITE);        // Open file and Write
if (datafile)
 {
  datafile.println(xAccel);
  datafile.print("::");
  datafile.println(yAccel);
  datafile.close();
 }
else
 {
  Serial.println("Couldn't open Accel file");
 }
 
}
