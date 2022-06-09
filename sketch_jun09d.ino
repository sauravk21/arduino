#include <Keypad.h> 

const byte ROWS = 4;  

const byte COLS = 4;  

int led = 13; 

char hexaKeys[ROWS][COLS] = { 

  {'1', '2', '3', 'A'}, 

  {'4', '5', '6', 'B'}, 

  {'7', '8', '9', 'C'}, 

  {'*', '0', '#', 'D'} 

}; 

  

byte rowPins[ROWS] = {9, 8, 7, 6};  

byte colPins[COLS] = {5, 4, 3, 2};  

Keypad keypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);  

  

//enter the desired high time of wave and press any non-number to enter. 

// The intensity will depend upon the work cycle of the wave generated 

void setup() 

{ 

  Serial.begin(9600); 

  pinMode(led , OUTPUT); 

} 

  

  

long getKeypadIntegerMulti() 

{ 

   

  long value = 0;                                 

  long keyvalue;                                      

  int isnum; 

   

  do{ 

    keyvalue = keypad.getKey();                           

    isnum = (keyvalue >= '0' && keyvalue <= '9');          

    if (isnum==1) 

    { 

      Serial.print(keyvalue - '0'); 

      value = value * 10 + keyvalue - '0';                

    } 

  

  } while (isnum || !keyvalue!=0);                           

   

  return value;} 

  

void loop() 

{ 

  char customKey = getKeypadIntegerMulti(); 

  for(int i =0; i<100000; i++) 

  {digitalWrite(led, HIGH); 

  delay(customKey);  

  digitalWrite(led, LOW); 

   delay(10); } 

} 

 
