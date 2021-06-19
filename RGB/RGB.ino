 #define echoPin 9 
#define trigPin 10 
#define r 11
#define g 12
#define b 13
#include <math.h> // not needed
const int buzzer = 5;
long duration; 
int distance; 

void setup() {
  pinMode(r,OUTPUT);
   pinMode(g,OUTPUT);
     pinMode(b,OUTPUT);
 // pinMode(buzzer,OUTPUT); // Optional buzzer
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  Serial.begin(9600); 
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); 
  Serial.println("with Arduino UNO R3");
}
void loop() {
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  
  distance = duration * 0.0343 / 2; // physics baby distance = time*speed (in this case speed of sound which is 343 m / s , or 0.0343 in cm/ms) 
  
 
  analogWrite(r,distance); // based on distance brightness will change
  /* another way to implement is 
   *  int intensity = -(distance^2);
   *  RGB_color(255*intensity,0,0);
   */
  if (distance <=3){ // just to turn it off
      analogWrite(r,0);
  }

  
  //RGB_color(0,0,255*intensityB); // figure this out
    /* 
 if(distance>=18)
 {
  RGB_color(255, 0, 0);
 // tone(buzzer, 2000);
 }
  else if(distance==12|| distance==11|| distance==10)
  {
  RGB_color(179, 0, 0);
 //tone(buzzer, 500);
  }
   else if(distance==15 || distance==14|| distance==16|| distance==17){
     RGB_color(128,0, 0);
    // tone(buzzer, 1000);
   }
   else if(distance==8 || distance==7 || distance==6 || distance==5 ||distance==4 || distance==3)
  {
    RGB_color(51, 0,0);
    noTone(buzzer);
    ----------------------------
    For different distance turn on different colors with the RGB and make a noise ranging from 0-2000khz
  }
*/
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
}
/* void RGB_color(int redValue, int greenValue, int blueValue) {
  analogWrite(r, redValue);
  analogWrite(g, greenValue);
  analogWrite(b, blueValue);
}
--------------------------------------
your RGB_color function where you read the value of r,g,b mainly to make it in one line( long live functions)
RGB_color(255,0,0) R 100%
RGB_color(0,255,0) G 100%
RGB_color(0,0,255) B 100%
much easier to mix colors



*/
