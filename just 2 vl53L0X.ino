#include <Wire.h>
#include <VL53L0X.h>

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
    Serial.println("_________________________________");
    Serial.print("Distance FWD (READING): ");
    Serial.println(" TIMEOUT");
    Serial.println("_________________________________");
    Serial.println("");
  }
  else
  {
    Serial.println("_________________________________");
    Serial.print("Distance FWD   (feet): ");
    Serial.println(DISTANCE_FWD/12);
    Serial.print("Distance FWD (inches): ");
    Serial.println(DISTANCE_FWD);
    Serial.println("_________________________________");
    Serial.println("");
  }

  //FLT OR SENSOR2
  if (sensor2.timeoutOccurred())
  {
    Serial.println("_________________________________");
    Serial.print("Distance FLT (READING): ");
    Serial.println(" TIMEOUT");
    Serial.println("_________________________________");
    Serial.println("");
  }
  else
  {
    Serial.println("_________________________________");
    Serial.print("Distance FLT   (feet): ");
    Serial.println(DISTANCE_FLT/12);
    Serial.print("Distance FLT (inches): ");
    Serial.println(DISTANCE_FLT);
    Serial.println("_________________________________");
    Serial.println("");
  }
  
  Serial.println("__________________________________________________________________");
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println();


  
  delay(2000);//can change to a lower time like 100
}
