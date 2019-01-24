#include <Wire.h>
#include <VL53L0X.h>


int debug = 1;  /// Activer le debuggage
int timetostart = 500;


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
  if (debug != 0) { Serial.println("Get adress of sensor 1"); }  /// Récupérer l'adresse du capteur 1 en I2C
  sensor.init(true);
  if (debug != 0) { Serial.println("Init of the sensor 1 ");    }
  delay(100);
  sensor.setAddress((uint8_t)22);
if (debug != 0)  {  Serial.println("Sensor 1 WORKING ! "); }

  //SENSOR 2
  pinMode(10, INPUT);
  delay(150);
  sensor2.init(true);
 if (debug != 0) {Serial.println("Get adress of sensor 2");}  /// Récupérer l'adresse du capteur 2 en I2C
  delay(100);
  sensor2.setAddress((uint8_t)25);
 if (debug != 0){ Serial.println("Init of the sensor 2"); 

  Serial.println("");
  Serial.println("all addresses set !");                     /// les capteurs (les adresses sont configurées) marchent tous -> le code démarre maintenant
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

 
  //Si le capteur ne fonctionne pas (voir sensor.setTimeout) -> Afficher un code d'erreur
  if (sensor.timeoutOccurred())
  {
    Serial.println("_________________________________");
    Serial.print("Sensor 1: ");
    Serial.println(" TIMEOUT");
    Serial.println("_________________________________");
    Serial.println("");
  }
  else
  {
    Serial.print("Distance 1   (mm):  ");
    Serial.print( sensor.readRangeSingleMillimeters() );
  }

  ////Si le capteur ne fonctionne pas (voir sensor2.setTimeout) -> Afficher un code d'erreur
  if (sensor2.timeoutOccurred())
  {
    Serial.println("_________________________________");
    Serial.print("Sensor 2: ");
    Serial.println(" TIMEOUT");
    Serial.println("_________________________________");
    Serial.println("");
  }
  else
  {
   Serial.print("      "); // Pour mettre de l'espace entre les 2 affichages de distance sans toucher au serial.print "Distance 2..."
    Serial.print("Distance 2   (mm): ");
    Serial.print(sensor2.readRangeSingleMillimeters());
    Serial.print("");
  }


  Serial.println();
  Serial.println("__________________________________________________________________");   // Fin de la captation de la distance
  

            if (debug != 0) {
           for (int i=0; i<100; i++) {Serial.print("\n"); }     
                              }  
  delay(timetostart); 
  } // VOID LOOP
