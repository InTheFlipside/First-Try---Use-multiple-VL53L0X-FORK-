#include <Wire.h>
#include <VL53L0X.h>


int debug = 1;  /// Add debug info



VL53L0X sensor;
VL53L0X sensor2;

void setup()
{
  debug = 0;


  
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
  if (debug = 1 && debug != 0) { Serial.println("Get adress of sensor 1"); }
  sensor.init(true);
  if (debug = 1 && debug != 0) { Serial.println("Init of the sensor 1 ");    }
  delay(100);
  sensor.setAddress((uint8_t)22);
  Serial.println("02");

  //SENSOR 2
  pinMode(10, INPUT);
  delay(150);
  sensor2.init(true);
 if (debug = 1 && debug != 0) { Serial.println("Get adress of sensor 2"); }
  delay(100);
  sensor2.setAddress((uint8_t)25);
 if (debug == 1 && debug != 0)  { Serial.println("Init of the sensor 2");

  Serial.println("");
  Serial.println("all addresses set !");
  Serial.println("");
  Serial.println("");

  Serial.println("-----------------CODE WILL START HERE-----------------------");
  delay(1000);
  Serial.println();
  Serial.print("3");
  delay(100);
  Serial.print(".");
  delay(100);
  Serial.print(".");
  delay(100);
  Serial.print(".");
  delay(700);
  Serial.print("2");
  delay(100);
  Serial.print(".");
  delay(100);
  Serial.print(".");
  delay(100);
  Serial.print(".");
  delay(700);
  Serial.print("1");
  delay(100);
  Serial.print(".");
  delay(100);
  Serial.print(".");
  delay(100);
  Serial.print(".");
  delay(700);
  Serial.println("0");
  
 }

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

            if (debug == 1 && debug != 0) {
Serial.write(27); 
Serial.print("[2J"); // clear screen 
Serial.write(27);  }  
 
  } // VOID LOOP
