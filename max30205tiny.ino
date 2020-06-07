/**************************************************************************************
Body Temp Monitoring Wirst Band (Simple LED Version)

Libs Used:
ClosedCube's MAX30205 lib
TinyWire by brohogan

Brad Hutson Jr

This Code is based on a hardware config as follows:
ATtiny85 + Max30205

**************************************************************************************/

#include <TinyWireM.h> // Wire lib for ATtiny devices and compatibles
#include "ClosedCube_MAX30205.h" // Included lib is a modified version of ClosedCube's lib which has been changed to use the TinyWireM instead of Wire for i2c comms.

ClosedCube_MAX30205 max30205; // Init


// ATTINY85 Pin assigments for LEDs
int RedLed = 4;
int GreenLed = 3;


void setup()
{
 // Serial.begin(9600); // Disabled because this needs softserial to (barely) work or device hard locks.
 // Serial.println("Body Temp Monitor Band Debug");  // Disabled because this needs softserial to work.
 
  pinMode(GreenLed, OUTPUT); // Set Green LED State
  pinMode(RedLed, OUTPUT); // Set Red LED State
  max30205.begin(0x48); // Use ClosedCube lib to init i2c device at this address.
}

void loop()
{

float temp = max30205.readTemperature(); // Assign a float value to the reading from MAX30205 in Celsius


///
// The following if statments are sloppy and a rush job for testing, please forgive. 
// Also the MAX30205 although being clinicly rated for body temp, doesnt read temps. 
// exactly because of body placment and the placment of the chip itself on the pcb its mounted to. 
// This is why the temp in C for the code below doesnt match up with actual body temp thresholds for normal/fever. 
// Needs tweaking/expermination on placment.
///


if (temp > 36) // Body temp (in c) for our fever Threshold (Needs tweaking)
  {
    
 // Illumnate Green RED LED Only (Fever reading)
 
   digitalWrite(RedLed, HIGH);
   digitalWrite(GreenLed, LOW);
  }



if (temp < 31) // Body temp (in c) is outside normal body temp metrics, probally means the device is not actually being worn. (This needs tweaking based on placment/implementation))

  {

 // Illuminate both LEDs to make orange and blink. (Reading is in progress, outside human body temp. This needs tweaking based on placment/implementation))
   digitalWrite(RedLed, HIGH);
   digitalWrite(GreenLed, HIGH);
   
   delay(300);
   
   digitalWrite(RedLed, LOW);
   digitalWrite(GreenLed, LOW);
  }



if(temp > 32 && temp <36) // Body temp (in c) is inside normal metrics (Normal body temp is approx 37c. This needs tweaking based on placment/implementation)

  {
    
  // Illumnate Green LED Only (Normal body temp)

   digitalWrite(GreenLed, HIGH);
   digitalWrite(RedLed, LOW);
   

  }

  delay(300);

 // Serial.print("T="); // Disabled because this needs softserial to work or device hard locks.
 // Serial.print(max30205.readTemperature()); // Disabled because this needs softserial to work or device hard locks.
 // Serial.println("C"); // Disabled because this needs softserial to work or device hard locks.

}
