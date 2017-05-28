
#include <AFMotor.h>      //Includes the Adafruit Motor Shield Library


AF_DCMotor motor1(1); // DC motor is hooked up to M1                                          
//AF_DCMotor motor2(2); // DC motor is hooked up to M2
//AF_DCMotor motor3(3); // DC motor is hooked up to M1                                          
AF_DCMotor motor4(4); // DC motor is hooked up to M2

//==================INSERT VALUES HERE \/ ====================================================================================================
int pin1 = 6; 
int pin2 = 3; 
//Make sure that pin1 is hooked up to the throttle port on the receiver (port 2 on 9x)
//and that pin2 is hooked up to the rudder port on the receiver (port 4 on 9x)


int neutralh = 1420;//PUT YOUR HIGH NEUTRAL VALUE HERE. REPLACE 1500  =~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~
int neutrall = 1400;//PUT YOUR LOW NEUTRAL VALUE HERE. REPLACE 1420  =~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~
//int maxval = 1685; //PUT YOUR MAX VALUE HERE   REPLACE 1870           =~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~==~=~==~=~==~=~==~=~==~=~==~=~=
//int minval = 1312; // PUT YOUR MIN VALUE HERE           REPLACE 1050  =~=~==~=~==~=~==~=~==~=~==~=~==~=~==~=~==~=~==~=~==~=~==~=~==~=~==~=~==~=~==~=~==~=~==~=~==~=~==~=~==~=~==~=~==~
//==================INSERT VALUES HERE /\ ====================================================================================================

void setup() {
  Serial.begin(9600);           // set up Serial monitor at 9600 bps

  motor1.run(RELEASE);          //This releases the motors via the motorshield
  //motor2.run(RELEASE);          //^ This is to make sure the motors dont start w/o control
  //motor3.run(RELEASE);
  motor4.run(RELEASE);

  pinMode(pin1, INPUT); //Setting up RC input pins
  pinMode(pin2, INPUT); //Setting up RC input pins
}

void loop() {
  int sV1;    //These are all different speed values that will be mapped
  int sV2;
  int sV3;
  int sV4;
  //int sV5;
  //int sV6;

  int speedValue = pulseIn(pin1, HIGH); //Getting the pulse in value from pin 1 and defining pin1 as speed
  
  int directionValue = pulseIn(pin2, HIGH); //Getting the pulse in value from pin 2 and defining pin1 as turning

  //Serial.println(speedValue);
  //Serial.println(directionValue);
  //These can be printed for debugging


  

   if (speedValue >= 1400 && speedValue <= 1420) {     //If the sticks are Neutral, then stay still

      motor1.setSpeed(0); // Sets the speed of motor1 to the speedValue
      //motor2.setSpeed(0); // Sets the speed of motor2 to the 
      //motor3.setSpeed(0); // Sets the speed of motor1 to the speedValue
      motor4.setSpeed(0); // Sets the speed of motor2 to the
      
      motor1.run(RELEASE);    //releases motors
      //motor2.run(RELEASE);   // releases motors
      //motor3.run(RELEASE);    //releases motors
      motor4.run(RELEASE);   // releases motors
      
        Serial.print("neutral  ");
         Serial.println(speedValue);
      delay(50);            //checks again every 50 micro Seconds
    }



  if (directionValue >= 1880 && directionValue <= 1920) {     //If the sticks are Neutral, then stay still

   //sV1 = map(speedValue, 1860, 1880, 140, 255);      //Maps the pulseIn speedvalue to numbers the motors can read 
                                                      //map(value, fromLow, fromHigh, toLow, toHigh)
                                                   //Motor is set to 140-255 instead of 0-255 so that the motor doesnt stall if 
                                                   //it is powered at too low of a level
                                                   
     // if(sV1 > 255){ //If the speed value is over 255 then set it to 255.                             .
     //   sV1 = 255;    //This prevents overpowering the motor if there is a pulsein glitch                          
     // }
      motor1.setSpeed(255); // Sets the speed of motor1 to the speedValue
      //motor2.setSpeed(sV1); // Sets the speed of motor2 to the 
      //motor3.setSpeed(sV1); // Sets the speed of motor1 to the speedValue
      motor4.setSpeed(255); // Sets the speed of motor2 to the 
      
      motor1.run(BACKWARD);    //releases motors
      //motor2.run(BACKWARD);   // releases motors
      //motor3.run(FORWARD);    //releases motors
      motor4.run(FORWARD);   // releases motors
      
        Serial.print("left  ");
        Serial.println(speedValue);
    
        
      delay(50);            //checks again every 50 micro Seconds
    }




    
 if (speedValue >= 1710 && speedValue <= 1740) {     //If the sticks are Neutral, then stay still

 //sV2 = map(speedValue, 1815, 1835, 140, 255);      //Maps the pulseIn speedvalue to numbers the motors can read
                                                   //Motor is set to 140-255 instead of 0-255 so that the motor doesnt stall if 
                                                   //it is powered at too low of a level
                                                   
   //   if(sV2 > 255){ //If the speed value is over 255 then set it to 255.                             .
     //   sV2 = 255;    //This prevents overpowering the motor if there is a pulsein glitch                          
      //}
      motor1.setSpeed(500); // Sets the speed of motor1 to the speedValue
      //motor2.setSpeed(sV2); // Sets the speed of motor2 to the 
      //motor3.setSpeed(sV2); // Sets the speed of motor1 to the speedValue
      motor4.setSpeed(500); // Sets the speed of motor2 to the 

      motor1.run(FORWARD);    //releases motors
      //motor2.run(FORWARD);   // releases motors
      //motor3.run(FORWARD);    //releases motors
      motor4.run(FORWARD);   // releases motors
      Serial.print("forward  ");
      Serial.println(speedValue);
      delay(50);            //checks again every 50 micro Seconds
    }



    
if (directionValue >= 1110 && directionValue <= 1130) {     //If the sticks are Neutral, then stay still

 //sV3 = map(speedValue, 990, 1110, 140, 255);      //Maps the pulseIn speedvalue to numbers the motors can read
                                                   //Motor is set to 140-255 instead of 0-255 so that the motor doesnt stall if 
                                                   //it is powered at too low of a level
                                                   
   //   if(sV3 > 255){ //If the speed value is over 255 then set it to 255.                             .
     //   sV3 = 255;    //This prevents overpowering the motor if there is a pulsein glitch                          
      //}
      motor1.setSpeed(255); // Sets the speed of motor1 to the speedValue
      //motor2.setSpeed(sV3); // Sets the speed of motor2 to the 
      //motor3.setSpeed(sV3); // Sets the speed of motor1 to the speedValue
      motor4.setSpeed(255); // Sets the speed of motor2 to the 

      motor1.run(FORWARD);    //releases motors
      //motor2.run(FORWARD);   // releases motors


      //motor3.run(BACKWARD);    //releases motors
      motor4.run(BACKWARD);   // releases motors
        Serial.print("right");
        Serial.println(speedValue);
      delay(50);            //checks again every 50 micro Seconds
    }



    
 if (speedValue >= 1070 && speedValue <= 1099) {     //If the sticks are Neutral, then stay still

 //sV4 = map(speedValue, 1235, 1250, 140, 255);      //Maps the pulseIn speedvalue to numbers the motors can read
                                                   //Motor is set to 140-255 instead of 0-255 so that the motor doesnt stall if 
                                                   //it is powered at too low of a level
                                                   
   //   if(sV4 > 255){ //If the speed value is over 255 then set it to 255.                             .
     //   sV4 = 255;    //This prevents overpowering the motor if there is a pulsein glitch                          
      //}
      motor1.setSpeed(255); // Sets the speed of motor1 to the speedValue
      //motor2.setSpeed(sV4); // Sets the speed of motor2 to the 
      //motor3.setSpeed(sV4); // Sets the speed of motor1 to the speedValue
      motor4.setSpeed(255); // Sets the speed of motor2 to the 

      motor1.run(BACKWARD);    //releases motors
      //motor2.run(BACKWARD);   // releases motors
      //motor3.run(BACKWARD);    //releases motors
      motor4.run(BACKWARD);   // releases motors
      
        Serial.print("back  ");
         Serial.println(speedValue);
      delay(50);            //checks again every 50 micro Seconds
    }


  /*  if (directionValue >= 1515 && directionValue <= 1500) { //if the throttle is up and turning is neutral

      sV1 = map(speedValue, 1500, 1870, 140, 255);      //Maps the pulseIn speedvalue to numbers the motors can read
                                                   //Motor is set to 140-255 instead of 0-255 so that the motor doesnt stall if 
                                                   //it is powered at too low of a level
                                                   
      if(sV1 > 255){ //If the speed value is over 255 then set it to 255.                             .
        sV1 = 255;    //This prevents overpowering the motor if there is a pulsein glitch                          
      }
     
      motor1.setSpeed(sV1); // Sets the speed of motor1 to the speedValue
      motor2.setSpeed(sV1); // Sets the speed of motor2 to the speedValue
      motor1.run(FORWARD);  //Makes the motor go forward at the speed defined above
      motor2.run(FORWARD);  //Makes the motor go forward at the speed defined above
      delay(50);            //Repeat every 50 micro seconds
      
   }


    if (directionValue > neutralh && speedValue > neutralh) {     //Speed value is forward, direction is right

      sV2 = map(speedValue, neutralh, maxval, 140, 255);    //RIGHT FORWARD

      if(sV2 > 255){
        sV2 = 255;
      }

      motor1.setSpeed(0);
      motor2.setSpeed(sV2);
      motor1.run(FORWARD);
      motor2.run(FORWARD);
      Serial.println("Right");
      delay(50);
    }

 /*   if (directionValue < neutrall && speedValue > neutralh) { //Speed is forward, Direction is left

      sV3 = map(speedValue, neutralh, maxval, 140, 255);    //LEFT FORWARD

      if(sV3 > 255){
        sV3 = 255;
      }

      motor1.setSpeed(sV3);
      motor2.setSpeed(0);
      motor1.run(FORWARD);
      motor2.run(FORWARD);
     Serial.println("Forward");

      delay(50);
    }

    if (speedValue < neutrall && directionValue >= neutrall && directionValue <= neutralh) {      //Speed is reverse and direction value is centered

      sV4 = map(speedValue, neutrall, minval, 140, 255);      //REVERSE

      if(sV4 > 255){
        sV4 = 255;
      }

      motor1.setSpeed(sV4);
      motor2.setSpeed(sV4);
      motor1.run(BACKWARD);
      motor2.run(BACKWARD);
      Serial.println("Riverse");

      delay(50);
    }

    if (directionValue > neutralh && speedValue < neutrall) {

      sV5 = map(speedValue, neutralh, minval, 140, 255);  //BACK RIGHT

      if(sV5 > 255){
        sV5 = 255;
      }

      motor1.setSpeed(sV5);
      motor2.setSpeed(0);
      motor1.run(BACKWARD);
      motor2.run(BACKWARD);
      Serial.println("Right");

      delay(50);
    }

    if (directionValue < neutrall && speedValue < neutrall) {

      sV6 = map(speedValue, neutralh, minval, 140, 255);    //BACK LEFT

      if(sV6 > 255){
        sV6 = 255;
      }

      motor1.setSpeed(0);
      motor2.setSpeed(sV6);
      motor1.run(BACKWARD);
      motor2.run(BACKWARD);
     Serial.println("Back");

      delay(50);
    
  }*/
}

