#include <Arduino.h>

const int led = D0;
const int led1 = D1;
const int led2 = D2;
const int led3 = D3;


void setup() {

  pinMode(led, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {

  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);

  digitalWrite(D1, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(D1, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);

  digitalWrite(D2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(D2, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);

   digitalWrite(D3, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(D3, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);

}
