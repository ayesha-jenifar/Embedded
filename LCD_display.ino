#include <LiquidCrystal.h> 

//Initialize Ports to operate LCD

/////////////////////////------DATA-----

//Arduino Port    D8  D7 D6 D5 D4 D3 
//LCD             RS  E  D4 D5 D6 D7 
LiquidCrystal lcd(37, 36, 35, 34, 33, 32);// Call LiquidCrystal() function with reset, enable and data ports

 

void setup()
{
  lcd.begin(16,2);//LCD display Size 16 colums and 2 rows
  lcd.print("Hello World");
}

void loop()
{
  unsigned char i;//positive character data type
  for(i=0;i<10;i++){
    lcd.setCursor(1,1);
    lcd.print(i);
    
    delay(800);
  } 
}


  
