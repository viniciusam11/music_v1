      int ldr = A3;//Atribui A0 a variável ldr
      int valorldr = 0;//Declara a variável valorldr como inteiro
      int speaker = 3;
      int numNotas = 0;
      
      #include "pitches.h"
      #define SILENCE  0

      void setup() {
        pinMode(ldr, INPUT);
        pinMode(13, OUTPUT);
        Serial.begin(115200);
        pinMode(3, OUTPUT);
        pinMode(7, INPUT);
      }
      void loop() {
          led();
          music();
        }   
      
        void led() {
           valorldr=analogRead(ldr);
         Serial.print("Valor lido pelo LDR = ");
           Serial.println(valorldr);
           Serial.print("ON/OFF = ");
           Serial.println(digitalRead(13));
           delay(100);          
         if(valorldr > 507    ) {
            digitalWrite(13, HIGH);
         } else {
           digitalWrite(13, LOW);
         }
        }
      void music(){
         if (digitalRead(7) == HIGH) {
      int imperialMarch[] = {NOTE_A3, NOTE_A3, NOTE_A3, NOTE_F3, NOTE_C4, NOTE_A3, NOTE_F3, NOTE_C4, NOTE_A3, NOTE_E4, 
  NOTE_E4, NOTE_E4, NOTE_F4, NOTE_C4, NOTE_GS3, NOTE_F3, NOTE_C4, NOTE_A3, NOTE_A4, NOTE_A3, NOTE_A3, NOTE_A4, NOTE_GS4, 
  NOTE_G4, NOTE_FS4, NOTE_E4, NOTE_F4, SILENCE, NOTE_AS3, NOTE_DS4, NOTE_D4, NOTE_CS4, NOTE_C4, NOTE_B3, NOTE_C4, SILENCE, 
  NOTE_F3, NOTE_GS3, NOTE_F3, NOTE_A3, NOTE_C4, NOTE_A3, NOTE_C4, NOTE_E4, NOTE_A4, NOTE_A3, NOTE_A3, NOTE_A4, NOTE_GS4, 
  NOTE_G4, NOTE_FS4, NOTE_E4, NOTE_F4, SILENCE, NOTE_AS3, NOTE_DS4, NOTE_D4, NOTE_CS4, NOTE_C4, NOTE_B3, NOTE_C4, SILENCE, 
  NOTE_F3, NOTE_GS3, NOTE_F3, NOTE_C4, NOTE_A3, NOTE_F3, NOTE_C4, NOTE_A3};
  
  int duracao[] = {500, 500, 500, 375, 125, 500, 375, 125, 1000, 500, 500, 500, 375, 125, 500, 375, 125, 1000, 500, 375, 
  125, 500, 375, 125, 125, 125, 250, 250, 250, 500, 375, 125, 125, 125, 250, 250, 250, 500, 375, 125, 500, 375, 125, 1000, 
  500, 375, 125, 500, 375, 125, 125, 125, 250, 250, 250, 500, 375, 125, 125, 125, 250, 250, 250, 500, 375, 125, 500, 375, 125, 1000};
 
  numNotas = sizeof(imperialMarch)/sizeof(int);
  
  for(int nota = 0; nota < numNotas; nota++){
    if(imperialMarch[nota] == SILENCE){
      delay(duracao[nota]);
    }  
    else{
      tone(speaker, imperialMarch[nota]);
      delay(duracao[nota]);
      noTone(speaker);
  }} 
   }   else {
    noTone(3);
    delay(100);
    } 
      }
