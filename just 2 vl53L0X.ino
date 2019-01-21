#include <Wire.h>
#include <VL53L0X.h>


int debug = 0;  /// Mettre des informations de débugage 


VL53L0X sensor;
VL53L0X sensor2;

void setup()
{

  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);

  delay(500);
  Wire.begin();


  Serial.begin (9600);

  //SENSOR
  pinMode(9, INPUT);
  delay(150);
  Serial.println("00");
  sensor.init(true);
  Serial.println("01");
  delay(100);
  sensor.setAddress((uint8_t)22);
  Serial.println("02");

  //SENSOR 2
  pinMode(10, INPUT);
  delay(150);
  sensor2.init(true);
  Serial.println("03");
  delay(100);
  sensor2.setAddress((uint8_t)25);
  Serial.println("04");

  Serial.println("");
  Serial.println("addresses set");
  Serial.println("");
  Serial.println("");



  sensor.setTimeout(500);
  sensor2.setTimeout(500);


}

void loop()
{


 
  //CHECK DISTANCES
  long DISTANCE_FWD = (sensor.readRangeSingleMillimeters()/25.4001);
  long DISTANCE_FLT = (sensor2.readRangeSingleMillimeters()/25.4001);
  
  //FWD OR SENSOR
  if (sensor.timeoutOccurred())
  {
//    Serial.println("_________________________________");
    Serial.print("Distance 1 (READING): ");
    Serial.println(" TIMEOUT");
//    Serial.println("_________________________________");
    Serial.println("");
  }
  else
  {
//    Serial.println("_________________________________");
    Serial.print("Distance 1   (mm):     ");
    Serial.print( sensor.readRangeSingleMillimeters() );
//    Serial.println("_________________________________");
//    Serial.println("");
  }

  //FLT OR SENSOR2
  if (sensor2.timeoutOccurred())
  {
    Serial.println("_________________________________");
    Serial.print("Distance 2 (READING): ");
    Serial.println(" TIMEOUT");
    Serial.println("_________________________________");
    Serial.println("");
  }
  else
  {
   Serial.print("      ");
    Serial.print("Distance 2   (mm): ");
    Serial.print(sensor2.readRangeSingleMillimeters());
//    Serial.print("_________________________________");
    Serial.print("");
  }

 delay(100); 
  Serial.println();
  Serial.println("__________________________________________________________________");

  
  }
