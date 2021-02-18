#include <Servo.h>
#include <Adafruit_NeoPixel.h>

#define LED_PIN    6
#define LED_COUNT 12

//declare constants, variables and objects
const int LEDS = 10 ; // 6 LEDS en séries
const int BP = 13 ; // Pin pour le bouton poussoir
int BP_state = LOW ; //Capture de l'état du BP
const int Servo_open = 180 ; // Ouvrir casque
const int Servo_close = 0 ; // Fermer casque
int Read_Bp = 0 ; //Lecture de l'état du BP
Servo servo2 ; // servo sur pin 2
Servo servo3 ; // servo sur pin 3
Servo servo4 ; // servo sur pin 4

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  //Allumage des leds
  pinMode(LEDS, OUTPUT) ; //Pin13 en sortie
  pinMode(BP,INPUT) ; //Config en entrée du bouton poussoir  
  
  strip.begin();

  //Mets toutes les leds de l'anneau à rouge)
  for (int pix=0 ; pix<12 ; pix++)
  {
    strip.setPixelColor(pix, 255,0,0);  
  }
    strip.show();
  
  //Attribution des pin pour les servos
  servo2.attach(2,1000,3000) ;
  servo3.attach(3,1000,3000) ;
  servo4.attach(4,1000,3000) ;

  //fermeture du casque
  servo2.write(Servo_close) ;
  servo3.write(Servo_close) ;
  servo4.write(Servo_close) ;   
}

void OpenCasque()
{
  delay(500) ;
  for (int i = 0; i < 4 ; i++)
  {
    digitalWrite(LEDS,LOW) ;
    delay(500) ;
    digitalWrite(LEDS,HIGH) ;
    delay(500) ;
  }
  
  digitalWrite(LEDS,LOW) ;
  servo2.write(Servo_open) ;
  servo3.write(Servo_open) ;
  servo4.write(Servo_open) ;  
  do
  {   
     Read_Bp = digitalRead(BP) ; //Lecture du BP   
  }while (Read_Bp == LOW) ;

  CloseCasque();
  
  }


  void CloseCasque()
{
  delay(500) ;
  for (int i = 0; i < 4 ; i++)
  {
    digitalWrite(LEDS,LOW) ;
    delay(500) ;
    digitalWrite(LEDS,HIGH) ;
    delay(500) ;
  }
  
  digitalWrite(LEDS,HIGH) ;
  servo2.write(Servo_close) ;
  servo3.write(Servo_close) ;
  servo4.write(Servo_close) ;
  do
  {     
     Read_Bp = digitalRead(BP) ; //Lecture du BP   
  }while (Read_Bp == LOW) ;

  OpenCasque();
  
  }
  
void loop() {
  // Allumage permanent des leds
  digitalWrite(LEDS,HIGH) ;
  Read_Bp = digitalRead(BP) ; //Lecture du BP
  if (Read_Bp == HIGH)
  {
    OpenCasque() ;
  }

}
