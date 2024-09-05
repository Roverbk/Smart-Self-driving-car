#include "NewPing.h"

int trig_pin = 12;
int echo_pin = 13;
const int dist = 20;
int duration=0;
NewPing sonar(trig_pin, echo_pin, dist);


void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT); // Wheel Left 
  pinMode(3, OUTPUT);
  pinMode(9, OUTPUT);
  analogWrite(9, 0);

  pinMode(4, OUTPUT); // Wheel Right
  pinMode(5, OUTPUT);
  pinMode(10, OUTPUT);
  analogWrite(10,0);

  pinMode(12, OUTPUT); // Sonar Trig
  pinMode(13, INPUT);  // Sonar Echo

  Serial.begin(9600);
}

int getdis(){
  long duration;
  int distance;
digitalWrite(trig_pin, HIGH);
delayMicroseconds(10);
digitalWrite(trig_pin, LOW);
  duration=pulseIn(echo_pin,HIGH);
  distance = ((duration*340)/(20000));
  Serial.println(distance);
  return distance;
}

void loop() {
  // put your main code here, to run repeatedly:


  digitalWrite(2, HIGH); // Forward
  digitalWrite(3, LOW);
  analogWrite(9,250);
  
  digitalWrite(4, LOW); // Forward
  digitalWrite(5, HIGH);
  analogWrite(10,45);

  int dis = getdis();

  if(dis<dist){
    motorStop();

    motorBack();

    motorStop();

    motorRight();

    motorFront();
  }

}

void motorStop(){
    digitalWrite(2, LOW); //Right Stop
    digitalWrite(3, LOW);
    digitalWrite(4, LOW); // Left Stop
    digitalWrite(5, LOW);
    
    delay(1000);
    return;
}

void motorBack(){
  digitalWrite(2, LOW); //Right Back
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH); // Left Back
    digitalWrite(5, LOW);
    
  analogWrite(10,49);
    analogWrite(9,220);

    delay(1000);
    return;
}

void motorRight(){
  digitalWrite(2, HIGH); //Right Stop
    digitalWrite(3, LOW);
    digitalWrite(4, LOW); // Left Stop
    digitalWrite(5, LOW);
    delay(1000);
    return;
}

void motorFront(){
  digitalWrite(2, HIGH); // Forward
  digitalWrite(3, LOW);
  analogWrite(9,250);
  
  digitalWrite(4, LOW); // Forward
  digitalWrite(5, HIGH);
  analogWrite(10,45);
  delay(1000);
  return;
}

