
int valeur = 0;
int lissage = 0;
int action = 0;
void setup() { Serial.begin(9600); }

void loop() {
valeur = Serial.parseInt();

while(valeur>10 && valeur<50) {
  Serial.println("Entre 10 et 50"); 
       Serial.println(lissage);
       if(lissage=3)
       {action = 1;}
       else {lissage++;}     
       
       
       
                           }
       
if(valeur > 50) {
  lissage = 0;  }


if(action != 0) { Serial.println("COOOOOOOOOOOOOOOOOOOOOOOOOOOODE LAAAAAAAAAAAAAAAAUUUUUUUUUUNNNNNNNNNCH"); }


delay(100);
}
