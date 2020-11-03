#include <Mouse.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);   // inicializa la interfaz I2C del LCD 16x2


int potenciometro=14;           //Asignamos el numero 14 para declarar el pin
int voltage=0;                  //Guardaremos el valor de resgistro
String Voltage2;                //Cadena de Caracteres
int leds[4] = {10, 11, 12, 13};
volatile int velocidad = 0;


void setup() {

  pinMode(potenciometro, OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  
  Serial.begin(9600);             //Comunicacion

  lcd.init();                         // Se inicializa el LCD 16x2
  lcd.backlight();                           
  lcd.clear(); 

}

void loop() {



  //if(dato=='I'){

   // while(int a=true){
      voltage=analogRead(potenciometro);        //Cargamos el voltage el valor leido en el pin 14
      Voltage2=String(voltage);                 //Convertimos el entero enuna cadena de caracteres
      Serial.println(Voltage2);                 //Lo amndamos al puerto serial
      delay(100);

//////////////////////////LCD////////////////////////////////


if(Serial.available()){       //Comprueba si hay caracer en el puerto serial
int dato=Serial.read();       //Guardara el caracter leido
 
  
  
 ////////////////////////////////// ENDENDIDOS DE LEDS////////////////////////////////
 
  //if(Serial.available()){       //Comprueba si hay caracer en el puerto serial
    
  //int dato=Serial.read();       //Guardara el caracter leido
  
  if(dato=='A'){                //Condicion para verificar si el dato es A
  digitalWrite(10,HIGH);        //Encender led
  delay(10);
  
  }
   
  if(dato=='B'){                //Condicion para verificar si el dato es B
  digitalWrite(10,LOW);         //Apagar el led 
  delay(10);

  }

  if(dato=='C'){                //Condicion para verificar si el dato es C
  digitalWrite(11,HIGH);        //Encender led
  delay(10);

  }
   
  if(dato=='D'){                //Condicion para verificar si el dato es D
  digitalWrite(11,LOW);         //Apagar el led 
  delay(10);
  }

  if(dato=='E'){                //Condicion para verificar si el dato es E
  digitalWrite(12,HIGH);        //Encender led
  delay(10);
  }
   
  if(dato=='F'){                //Condicion para verificar si el dato es F
  digitalWrite(12,LOW);         //Apagar el led 
  delay(10);
  }

  if(dato=='G'){                //Condicion para verificar si el dato es G
  digitalWrite(13,HIGH);        //Encender led
  delay(10);
  }
   
  if(dato=='H'){                //Condicion para verificar si el dato es H      
  digitalWrite(13,LOW);         //Apagar el led 
  delay(10);
  }

  if(dato=='K'){ 

  for (int i = 0; i < 4; i++) {       // Corrimiento de Izquierda a Derecha

    if (i > 0) {                      // Límite, precaución de no alcanzarlo
      digitalWrite(leds[i - 1], LOW); // Apagado del LED izquierdo
    }
    digitalWrite(leds[i], HIGH);      // Encendido del LED actual
    delay(1000);                 // Espera por el tiempo establecido
  }
  digitalWrite(leds[3], LOW);         //  Apagado del último LED
  //- - - - - - - - - - - - - - -
  for (int i = 4; i >= 0; i--) {      // Ahora, corrimiento de derecha a izquierda
    if (i < 4) {                      // Cuidado de no salirse del rango.
      digitalWrite(leds[i + 1], LOW); // Apagado del LED de la dercha
    }
    digitalWrite(leds[i], HIGH);      // Encendido del LED actual
    delay(1000);                 // Espera por el tiempo establecido
  }
  digitalWrite(leds[0], LOW);         //  Apagado del último LED
  
  }

//////////////////LCD//////////////////

if(dato=='I'){
  
   lcd.setCursor(1,0);                   //Muestra en el LCD el valor de BPM 
   lcd.print("Hola, Bienvenido");

   lcd.setCursor(1,2); 
   lcd.print("Sistemas embebidos");
   }


if(dato=='J'){
  lcd.clear(); 
  }

  
  }

}
