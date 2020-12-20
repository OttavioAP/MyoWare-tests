/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogReadSerial
*/
  #include <Servo.h> 

  
Servo myservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
 
int pos = 0;    // variable to store the servo position 


// the setup routine runs once when you press reset:
void setup() {

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
     myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
}


// the loop routine runs over and over again forever:
void loop() {
 int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  delay(1);        // delay in between reads for stability

  
  // read the input on analog pin 0:

pos =0;
while(pos <180){
sensorValue = analogRead(A0);
Serial.println(sensorValue);
if(sensorValue >150){
pos +=1;
 myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(10);                       // waits 15ms for the servo to reach the position 
}
}
pos =180;

while(pos >=0){
sensorValue = analogRead(A0);
Serial.println(sensorValue);
if(sensorValue >150){
pos -=1;
 myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(10);                       // waits 15ms for the servo to reach the position 
}
  
}


  
}
