/**************************************************************************************
Body Temp Monitoring Wirst Band (Simple LED Version)

Libs Used:
ClosedCube's MAX30205 lib
TinyWire by brohogan

-Brad Hutson Jr

This Code is based on hardware config as follows:
ATtiny85 + Max30205 Config

**************************************************************************************/

#include <TinyWireM.h> // Wire lib for ATtiny devices and compatibles
#include "ClosedCube_MAX30205.h" // Included lib is a modified version of ClosedCube's lib which has been changed to use the TinyWireM instead of Wire for i2c comms.

ClosedCube_MAX30205 max30205; // Init


// ATTINY85 Pin assigments for LEDs
int RedLed = 4;
int GreenLed = 3;


void setup()
{
 // Serial.begin(115200); // Disabled because this needs softserial to (barely) work or device hard locks
 // Serial.println("Body Temp Monitor Band Debug");  // Disabled because this needs softserial to (barely) work or device hard locks
 
  pinMode(GreenLed, OUTPUT); // Set Green LED State
  pinMode(RedLed, OUTPUT); // Set Red LED State
  max30205.begin(0x48); // Use ClosedCube lib to init i2c device at this address.
}

void loop()
{

float temp = max30205.readTemperature(); // Assign a float value to the reading from MAX30205 in Celsius


if (temp > 36) // Body temp (in c) fever Threshold (Needs tweaking)
  {

   digitalWrite(RedLed, HIGH);
   digitalWrite(GreenLed, LOW);
  }


if (temp < 31) // Body temp (in c) is outside normal metrics, means the device is not actually worn. (Needs tweaking)

  {

 // Illuminate both LEDs to make orange
   digitalWrite(RedLed, HIGH);
   digitalWrite(GreenLed, HIGH);
   
   delay(300);
   
   digitalWrite(RedLed, LOW);
   digitalWrite(GreenLed, LOW);
  }



if(temp > 32 && temp <36) // Body temp (in c) is inside normal metrics (Needs tweaking)

  {
    
  // Illumnate Greed LED Only

   digitalWrite(GreenLed, HIGH);
   digitalWrite(RedLed, LOW);
   

  }

  delay(300);

 // Serial.print("T="); // Disabled because this needs softserial to work or device hard locks
 // Serial.print(max30205.readTemperature()); // Disabled because this needs softserial to work or device hard locks
 // Serial.println("C"); // Disabled because this needs softserial to work or device hard locks

}
