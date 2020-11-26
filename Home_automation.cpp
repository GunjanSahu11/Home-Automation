#include <SoftwareSerial.h>
//#include<LiquidCrystal.h>
  SoftwareSerial BTSerial(10, 11); // RX | TX
    int LED = 6; // IR out put 
    int isObstaclePin = 7;  // This is our input pin
    int isObstacle = HIGH;  // HIGH MEANS NO OBSTACLE
      // buzzer
      int LED2 = 5;  // IR out put buzzer 
      int isObstaclePin2 = 4;  // This is our input pin
      int isObstacle2 = HIGH;  // HIGH MEANS NO OBSTACLE

    const int ledPin = 13;     // ldr output
    const int ldrPin = A0;

//#include<LiquidCrystal.h>
  int relay=12;
 // LiquidCrystal lcd(8,9,4,5,6,7); 
  const int sensor=A1; // Assigning analog pin A1 to variable 'sensor'
  float tempc;  //variable to store temperature in degree Celsius
  float vout;  //temporary variable to hold sensor reading

void setup()
{
myservo.attach(9);
Serial.begin(9600);
Serial.println("Enter AT commands:");
BTSerial.begin(9600);  // HC-05 default speed in AT command more//

 pinMode(LED2, OUTPUT);
  pinMode(isObstaclePin2, INPUT);
  Serial.begin(9600);
  
  pinMode(LED, OUTPUT);
  pinMode(isObstaclePin, INPUT);
  Serial.begin(9600);
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(ldrPin, INPUT);

pinMode(sensor,INPUT); // Configuring pin A1 as input
  Serial.begin(9600);
//  lcd.begin(16,2);  
  pinMode(relay,OUTPUT);
}
void loop()
{
{
// Keep reading from HC-05 and send to Arduino Serial Monitor
if (BTSerial.available())
Serial.write(BTSerial.read());
// Keep reading from Arduino Serial Monitor and send to HC-05
if (Serial.available())
  {
    BTSerial.write(Serial.read());
    int servopos = BTSerial.read(); // save the received number to servopos
    Serial.println(servopos); // serial print servopos current number received from bluetooth
    myservo.write(servopos);
  }
}
{
isObstacle2 = digitalRead(isObstaclePin2);
  if (isObstacle2 == LOW)
  {
    Serial.println("OBSTACLE!!, OBSTACLE!!");
    digitalWrite(LED2, HIGH);
  }
  else
  {
    //Serial.println("clear");
    digitalWrite(LED2, LOW);
  }
  delay(200);
  }
  {
  int ldrStatus = analogRead(ldrPin);
if (ldrStatus <=300)
 {
digitalWrite(ledPin, LOW);
Serial.println("LDR is DARK, LED is ON");
}
else 
{
digitalWrite(ledPin, HIGH);
Serial.println("---------------");
}
  isObstacle = digitalRead(isObstaclePin);
  if (isObstacle == LOW)
  {
    Serial.println("OBSTACLE!!, OBSTACLE!!");
    digitalWrite(LED, HIGH);
  }
  else
  {
   Serial.println("clear");
    digitalWrite(LED, LOW);
  }
  delay(200);
}

//
{
vout=analogRead(sensor);
vout=(vout*500)/1024;
delay(1000);
tempc=vout/10; // Storing value in Degree Celsius
 
//lcd.setCursor(0,0);
//lcd.print("Celsius");
//lcd.setCursor(0,1);
Serial.print("\ncelsius   :  ");
Serial.print(tempc);
//lcd.print(tempc);
//delay(100);
if (tempc>15)
{
  digitalWrite(12,HIGH);
}
else
{
  digitalWrite(12,LOW);
}
}
}

