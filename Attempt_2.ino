int En_A = 3;
int in1 = 4;
int in2 = 5;
int En_B = 9;
int in3 = 6;
int in4 = 7;
int motor_Speed = 90;

int const trigPin = 1;  //input for the ultrasonic sensor (Middle) trigger pin
int const echoPin = 2; // input for the ultrasonic sensor (Middle) echo pin

int const trigPin1 = 8; //input for the ultrasonic sensor (left) trigger pin
int const echoPin1 = 10; // input for the unltasonic sensor (left) echo pin

int const trigPin2 = 8; // input for the ultrasonic sensor (right) trigger pin
int const echoPin2 = 10; //input for the ultrasonic sensor(right) echo pin

int duration, distance;    // variables to measure the time and distance between object and device for ultrasonic sensor Middle
int durationL, distanceL;  // variables to measure the time and distance between object and device for ultrasonic sensor Left
int durationR, distanceR;   // variables to measure the time and distance between object and device for ultrasonic sensor Right

void setup()
{
pinMode(trigPin, OUTPUT); // trigger pin will send the pulse out, hence output
pinMode(echoPin, INPUT);  // echo pin will receive the pulse, hence input

pinMode(trigPin1, OUTPUT); // for Left ultrasonic sensor
pinMode(echoPin1, INPUT);

pinMode(trigPin2, OUTPUT); // for Right untrasonic sensor
pinMode(echoPin2, INPUT);

Serial.begin(9600);
  pinMode(En_A, OUTPUT);     For motor control
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(En_A, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  pinMode(distance,INPUT);
  pinMode(distanceL,INPUT);
  pinMode(distanceR,INPUT);
}

void loop(){
  
  /* the code below is for the middle ultrasonic sensor to measure the distance from the object in front*/
digitalWrite(trigPin, HIGH);
delay(10);
digitalWrite(trigPin, LOW);                                                                              // Measure the pulse input in echo pin
duration = pulseIn(echoPin, HIGH);                                                                              // Distance is half the duration devided by 29.1 (from datasheet)
distance = (duration/2) / 29.1;
                                                                               // if distance less than 0.5 meter and more than 0 (0 or less means over range)
 Serial.print(distance);
 Serial.println("middle sensor,  ");

 
if (distance >=40 && distance <= 150)    // maintains distance of 40 and 150. the sensor value is not stable and keeps changing rapidly. This code will send maintain distance of 40 to 150 just in striaght line.
{
  forward();      
  }
  
  else if(distance <=20 && distance >= 0) // if the robot is less than 20 and greater than 0, since there cannot be negative distance, the robot will move backward
  {         
  backward();
  }
  
  else // if nothing happens, the robot will stop
  {
    Stall();    
  }


  

 digitalWrite(trigPin2, HIGH);              // this line of code is for the left ultrasonic sensor to detect object in the left if that object moves towards left
delay(10);
digitalWrite(trigPin2, LOW);                                                                        // Measure the pulse input in echo pin
durationR = pulseIn(echoPin2, HIGH);                                                                // Distance is half the duration devided by 29.1 (from datasheet)
distanceR = (durationR/2) / 29.1;
                                                                                                     // if distance less than 0.5 meter and more than 0 (0 or less means over range)
 Serial.print(distanceR);
 Serial.println("right sensor,  ");

 if (distanceR <=40 && distanceR  >=20)                         
 {
 right();
      if (distance >= 20 && distance <= 40){
             forward();
              }
 }
 else{
 Stall();
 }



 digitalWrite(trigPin1, HIGH);
delay(10);
digitalWrite(trigPin1, LOW);                                                                              // Measure the pulse input in echo pin
durationL = pulseIn(echoPin1, HIGH);                                                                              // Distance is half the duration devided by 29.1 (from datasheet)
distanceL = (durationL/2) / 29.1;
                                                                               // if distance less than 0.5 meter and more than 0 (0 or less means over range)
 Serial.print(distanceL);
 Serial.println("left sensor,  ");

 if (distanceL >=40 && distanceL <150)
 {
 
 left();
        if (distance >=20 && distance <= 40){
          forward();
          }
 
 }
 else{
 Stall();
 }

}


void backward()
{ digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);  
    analogWrite(En_A, 200);  
    
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(En_B, 200);  
  }

  
void forward(){
   digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH); 
    analogWrite(En_A, 200);   
    
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH); 
    analogWrite(En_B, 200); 
    }
    
 void Stall()
 {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);   
    digitalWrite(in3, HIGH);
    digitalWrite(in4, HIGH);
  }
  void right()
  {digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);  
    analogWrite(En_A, 200);  
    
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(En_B, 200);
    
    }
    void left()
  {digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);  
    analogWrite(En_A, 200);  
    
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(En_B, 200);
    
    }
