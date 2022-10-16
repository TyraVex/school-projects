#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include <MeOrion.h>

// Default variables (required by the microcontroller)
double angle_rad = PI/180.0;
double angle_deg = 180.0/PI;
MeRGBLed rgbled_4(4, 4);
MeUltrasonicSensor ultrasonic_6(6);
Me7SegmentDisplay seg7_3(3);
MeDCMotor motor_9(9);

// My variables
double historique[50], distance, distanceMoyenne, total, totalVide;
int i, j, k;

// Initialize array
void setup(){
    for(i = 0; i < 50; i++) { historique[i]=0; }
}

// My program
void loop(){

    // Average distance value calculation
    i++; if (i == 50) { i = 0; }
    distance=ultrasonic_6.distanceCm();
    if (distance > 100) { distance = 100; }
    historique[i] = distance;
    total = 0; totalVide = 0;
    for (j = 0; j < 50; j++)
    {
      if (historique[j] == 0)
      {
        totalVide += 1;
      }
      total += historique[j];
    }
    distanceMoyenne = total/(50-totalVide);
    seg7_3.display(distanceMoyenne);

    // Send motor instructions and custom color shades between red and green depending on the average distance value
    // Note : the motor part was not yet tested, because it was implemented after getting hands on the robot

    // Stop the motor and flash a red light every 0.05 second if the hand is around 5cm close
    if (distanceMoyenne < 9)
    {
      motor_9.run(0);
      rgbled_4.setColor(0,(-2.5*distanceMoyenne+255),2.5*distanceMoyenne,0);
      rgbled_4.show();
      _delay(0.05);
      rgbled_4.setColor(0,0,0,0);
      rgbled_4.show();
      _delay(0.05);
    }
    // Stop the motor and flash a red light every 0.1 second if the hand is around 10cm close
    else if (distanceMoyenne < 10)
    {
      motor_9.run(0);
      rgbled_4.setColor(0,(-2.5*distanceMoyenne+255),2.5*distanceMoyenne,0);
      rgbled_4.show();
      _delay(0.1);
      rgbled_4.setColor(0,0,0,0);
      rgbled_4.show();
      _delay(0.1);
    }
    // Start the motor and send a custom color shade if the hand is further than 10cm
    else
    {
      motor_9.run(distanceMoyenne*2.5);
      rgbled_4.setColor(0,(-2.5*distanceMoyenne+255),2.5*distanceMoyenne,0);
      rgbled_4.show();
    }

    _loop();

}

// Timer (required by the microcontroller)
void _delay(float seconds){
    long endTime = millis() + seconds * 1000;
    while(millis() < endTime)_loop();
}
