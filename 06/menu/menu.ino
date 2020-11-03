/*Los botones que se ocupan para seleccionar son:
 * simulacion     Teclado fisico
 *    7                 1
 *    8                 2
 *    9                 3
 *    4                 4    
 *Regresar
 *    ON/C              *
 *Iniciar
 *    X
*/
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
//#include <dht.h>

#define DHT_PIN 12

// dht DHT;
 int LED=6;
 int LED2 = 7; ////////////////////////////////////////////////////
 volatile byte state1 = HIGH; ////////////////////////////////////
 
 float temp;

 float LDR=A0;
 int val;
 int ilum;

 boolean casa=true;
 boolean sub1=false;
 
 int conta;

const byte ROWS = 4; 
const byte COLS = 4; 

char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {11, 10, 9, 8}; 
byte colPins[COLS] = {2, 3, 4, 5};

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
LiquidCrystal_I2C lcd(0x27,20,4);


//Función menú principal
void menu0()
{
    lcd.clear();
    lcd.setCursor(5,0);
    lcd.print("*Equipo 2*");////////////////////////////////////////////////7
    lcd.setCursor(3,2);
    lcd.print("Menu Opciones");
      
}

//Funcion submenus
void menu1()
{
  
    
    lcd.clear();  
    lcd.setCursor(0,0);
    lcd.print("1)LED 1"); ///////////////////////77
    lcd.setCursor(0,1);
    lcd.print("2)LED 2"); /////////////////////////////////7
    lcd.setCursor(0,2);
    lcd.print("3)Temperatura");
    lcd.setCursor(0,3);
    lcd.print("4)Sensor Luz");  
}

byte grados[8]=
{
  0b01110,
  0b01010,
  0b01110,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
};

void setup() 
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(LED2, OUTPUT);//////////////////////////////////////
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  conta=4;
  menu0(); 
  
}



void loop() 
{
 
  char Key = customKeypad.getKey();
    
  
  if(Key=='B' && conta==4)
    {
      conta=0;  
      menu1();    
    }       

  
    if(Key=='1' && conta == 0)  
  {
    led1ONOFF();
    digitalWrite(LED, state1);
    lcd.clear();
    lcd.setCursor(5,0);
    lcd.print("LED Verde");
    lcd.setCursor(6,1);
    lcd.print("ON-OFF");
    lcd.setCursor(8,3);
    lcd.print("* para salir");
    conta=1;
  }
   

  if(Key=='2' && conta==0)
  {
    //----------------------------------//
    led1ONOFF();                        //
    digitalWrite(LED2, state1);         //
    lcd.clear();                        //
    lcd.setCursor(5,0);                 //
    lcd.print("LED Yellow");            //
    lcd.setCursor(6,1);                 //
    lcd.print("ON-OFF");                 //
    lcd.setCursor(8,3);
    lcd.print("* para salir");    
    conta=1;                             //
    //-----------------------------------
  }

  if(Key=='3' && conta==0)
  {
    lcd.clear();
//    temp=DHT.read(DHT_PIN);
    lcd.setCursor(0,0);
    lcd.print("Temperatura");
    lcd.setCursor(12,1);
  //  lcd.print(DHT.temperature);
    lcd.print("C");
    lcd.createChar(1, grados);
    lcd.setCursor(15,1);
    lcd.write(1);
    conta=1;
    lcd.setCursor(8,3);
    lcd.print("* para salir");
  }

  if(Key=='4' && conta==0)
  {
    conta=2;
  }
  if(conta==2)
  {
    lcd.clear();
    val=analogRead(LDR);
    ilum=((long)val * 1000 * 10)/((long)15 * 10 * (1024-val));
    lcd.setCursor(0,0);
    lcd.print("Luz");
    lcd.setCursor(14,1);
    lcd.print(ilum);
    lcd.setCursor(8,3);
    lcd.print("* para salir");
    delay(100);
  }

  if((Key=='*')&&(conta==0||conta==1||conta==2))
  {
    menu1();
    conta=0;
  }  
}

//Función LED
//--------------------//
void led1ONOFF(){     //
  state1 = !state1;   //
  return state1;      //
  }                   //  
 //-------------------//
