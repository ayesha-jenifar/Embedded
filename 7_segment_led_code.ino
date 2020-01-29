//Initializing the ports

int ledA = 0;
int ledB = 1;
int ledC = 2;
int ledD = 3;
int ledE = 4;
int ledF = 5;
int ledG = 6;
int ledDp= 7;
int led = 8;


// Setup Port as output
void setup()
{
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledC, OUTPUT);
  pinMode(ledD, OUTPUT);
  pinMode(ledE, OUTPUT);
  pinMode(ledF, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledDp, OUTPUT);
  pinMode(led, OUTPUT);
}

// function sevenseg(int num) takes integer num as input parameter 
// and print the corresponding number in the seven segment display.
void sevenseg(int display_number){
  if(display_number == 0)
  { 
             //a b c d e f g dp
     printvalue(1,1,1,1,1,1,0,1); // call printvalue function to print 0
  }
  else if(display_number == 1)
  {
         //a b c d e f g dp
    printvalue(0,1,1,0,0,0,0,1); // call printvalue function to print 1
  }
  else if (display_number == 2)
  {
         //a b c d e f g dp
    printvalue(1,1,0,1,1,0,1,1); // call printvalue function to print 2
  }
  else if (display_number == 3)
  {
         //a b c d e f g dp
    printvalue(1,1,1,1,0,0,1,1); // call printvalue function to print 3
  }
  else if (display_number == 4)
  {
         //a b c d e f g dp
    printvalue(0,1,1,0,0,1,1,1); // call printvalue function to print 4
  }
  else if (display_number == 5)
  {
         //a b c d e f g dp
    printvalue(1,0,1,1,0,1,1,1);// call printvalue function to print 5
  }
  else if (display_number == 6)
  {
         //a b c d e f g dp
    printvalue(1,0,1,1,1,1,1,1);// call printvalue function to print 6
  }
  else if (display_number == 7)
  {
         //a b c d e f g dp
    printvalue(1,1,1,0,0,0,0,0); // call printvalue function to print 7
  }
  else if (display_number == 8)
  {
         //a b c d e f g dp
    printvalue(1,1,1,1,1,1,1,1);// call printvalue function to print 8
  }
  else if (display_number == 9)
  {
         //a b c d e f g dp
    printvalue(1,1,1,1,0,1,1,1); // call printvalue function to print 9
  }
  else
  {
         //a b c d e f g dp
    printvalue(0,0,0,0,0,0,0,0); // call printvalue function with 0 to stop Led
  }
}


// printvalue function takes bolean value as input parameter to write
// corresponding number on the seven segment display
void printvalue(boolean a, boolean b, boolean c, boolean d, boolean e, boolean f, boolean g, boolean dp)
{
  digitalWrite(ledA,a);  //digitalWrite funtion writes a(High/low) to ledA(0) pin
  digitalWrite(ledB,b);  //digitalWrite funtion writes b(High/low) to ledB(1) pin
  digitalWrite(ledC,c);  //digitalWrite funtion writes c(High/low) to ledC(2) pin
  digitalWrite(ledD,d);  //digitalWrite funtion writes d(High/low) to ledD(3) pin
  digitalWrite(ledE,e);  //digitalWrite funtion writes e(High/low) to ledE(4) pin
  digitalWrite(ledF,f);  //digitalWrite funtion writes f(High/low) to ledF(5) pin
  digitalWrite(ledG,g);  //digitalWrite funtion writes g(High/low) to ledG(6) pin
  digitalWrite(ledDp,dp);  //digitalWrite funtion writes dp(High/low) to ledDp(7) pin
}  

void loop()
{
  // initialize two numbers 
  int number1 = 0;
  int number2 = 8;
  
  //print number 0-9 in sequence
  for(int index = 0; index <10; index++)
  {
    sevenseg(number1);//call sevenseg with number1 variable
    number1 = number1+1;
    delay(500);
  }
  
  //print number in sequence from 8,6,4,2,0 
  for(int index1 = 0;index1 < 5; index1++)
  {
    sevenseg(number2);//call sevenseg with number2 variable
    number2 = number2 -2;
    delay(500);
  }
  
  digitalWrite(led,HIGH);
             //a b c d e f g dp
    printvalue(0,0,0,0,0,0,0,0);// call printvalue function with 0 to stop Led
  delay(1000);
  digitalWrite(led,LOW);
  
}
