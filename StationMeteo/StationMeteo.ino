#include <math.h>

int analogPin = A0; 

int valTemp = 0;  // variable to store the value of temperature
float valTemp2 = 0.0 ;

void setup() {
  Serial.begin(9600);           //  setup serial
}

void loop() {
  valTemp = analogRead(analogPin);  // read the input pin
  
  valTemp2 = (((5.0*valTemp)/1023)/5)*100 ;
  Serial.println(valTemp2);          // debug value
  delay(10000) ;
  
}
