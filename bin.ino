#include <Servo.h> 

int led_pin = 13;
int sensor_pin = 8;
int servoPin = 9; 
int servoPin2 = 10;
int tripin = 7;
int echopin = 6;
int IR_Sensor = 3;
int IR_Sensor2 = 4;
Servo Servo1, Servo2;

void setup() {
  
  Servo1.write(90);
  Servo2.write(30);
  
  pinMode(IR_Sensor, INPUT);
  pinMode(led_pin, OUTPUT);
  pinMode(sensor_pin, INPUT);
  Servo1.attach(servoPin); 
  Servo2.attach(servoPin2); 
  Serial.begin(9600);
  
  pinMode(tripin, OUTPUT);
  pinMode(echopin, INPUT);

}

void loop() {
	  
  if(digitalRead(IR_Sensor) == LOW ) {     // Check the sensor output
    digitalWrite(13, HIGH);   // set the LED on
  }
  else {
    digitalWrite(13, LOW);    // set the LED off
  }
    
  delay(1000);  // wait for a second

  if(digitalRead(led_pin) == LOW) {
    long duration, distance;
    digitalWrite(tripin, HIGH);
    
    delay(1000);
    
    digitalWrite(tripin, LOW);
    duration = pulseIn(echopin, HIGH);
    distance = (duration/2) / 29.1;
    

    if((distance<=30)) {
      if(digitalRead(sensor_pin) == HIGH) {
        Servo2.write(90); 
        delay(1000); 
        Servo2.write(30);
      } 
      else {
        Servo1.write(0); 
        delay(1000); 
        Servo1.write(90);
      }

    }
    else if(distance > 30) { 
      digitalWrite(led_pin, LOW);
    }
    else {
      digitalWrite(12, HIGH);
    }
  
  }

}
