#include <LiquidCrystal.h>
 
 
 

 
LiquidCrystal lcd(A1, A2, A5, A6, A7, A8);// Call LiquidCrystal() function with reset, enable and data ports
 

 
 
 
 
int inPin = 2; // pushbutton connected to digital pin 13
 
int val = 0;
 
 
 
 
 
void setup()
 
{
 
  lcd.begin(20,2);//LCD display Size 16 colums and 2 rows
 
  
 
 
 
  pinMode(inPin, INPUT);        // sets the digital pin 13 as input
  attachInterrupt(digitalPinToInterrupt(inPin), pulse_interrupt,RISING);
  lcd.clear();
 
}
 
 
 
 
 
void loop()
 
{
 
      lcd.setCursor(4,0);
 
      lcd.print("Counter = ");
      lcd.print(val);
 
      lcd.clear();
   
      lcd.print("Counter = ");
      lcd.print(val);
  
        
      lcd.print("button is pressed");
      delay(200);
}
 
    void pulse_interrupt(void)
    {
      val++;
    }
  
