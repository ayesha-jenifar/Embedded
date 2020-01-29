#include <LiquidCrystal.h> 
LiquidCrystal lcd(A1, A2, A5, A6, A7, A8);

int motor1 = 9;  
int motor2=10;               // LED connected to digital pin 9
int analogPin = A9;

int js;



                     // potentiometer connected to analog pin 3
int pwmmode ;
int pwm1;  
                  // variable to store the read value

unsigned long start;

// Counters for milliseconds during interval
long previousMillis = 0;
long currentMillis = 0;

volatile long pulse = 0;
volatile bool pinA, pinB, pinC,pinD,  dir;
const byte ppr = 25, upDatesPerSec = 2;
const int fin = 1000 / upDatesPerSec;
const float konstant = 60.0 * upDatesPerSec / (ppr * 2);
int rpm;

//Left
const byte encoderPinA = 23;//B pin -> digital pin 4
const byte encoderPinB = 22;//B pin -> digital pin 4
//Right
const byte encoderPinC = 25;//C=A pin -> digital pin 4
const byte encoderPinD = 24;//D=B pin -> digital pin 4


void setup() {
   lcd.begin(20,4);
  pinMode(motor1, OUTPUT);  // sets the pin as output
 lcd.setCursor(0,0); 
  lcd.print("Embedded"); 

  attachInterrupt(1, readEncoder, CHANGE);
  pinMode(encoderPinA,INPUT);
  pinMode(encoderPinB,INPUT);
  pinMode(encoderPinC,INPUT);
  pinMode(encoderPinD,INPUT);
}

void loop() {
  
  js = analogRead(analogPin);
 
  pwm1=(js-512)/3;
  if(pwm1<0) {pwm1=pwm1*(-1);};
  //else pwm1=(512-pwmmode);
  //if (pwm1>511) pwm1=511;
  //if(pwm1<0) pwm1=0;
 //pwmmode = analogRead(analogPin);  // read the input pin
  analogWrite(motor1, pwm1 );
  lcd.clear();
lcd.setCursor(2,1);
  lcd.print("     ");
 
  lcd.setCursor(2,1);
  lcd.print(pwm1);
  
 // analogRead values go from 0 to 1023, analogWrite values from 0 to 255

 lcd.setCursor(3,2); 
      lcd.print("      "); 

 lcd.setCursor(3,2); 
      lcd.print(js); 
      delay(500);
 lcd.clear();
 
 // Update RPM value every second
  currentMillis = millis();
  if (currentMillis - previousMillis > 1000) {
    previousMillis = currentMillis;
    readEncoder();

    rpm = (pulse*60)/ppr;

    lcd.clear();
    lcd.setCursor(0,1); 
    lcd.print(" PULSES: ");
    lcd.setCursor(8,1);
    lcd.print(pulse);
    
    
    lcd.setCursor(0,2); 
    lcd.print(" SPD: ");
    lcd.setCursor(6,2);
    lcd.print(rpm);
    lcd.setCursor(8,2);
    lcd.print(" RPM");
    pulse = 0;
    
}

}
void readEncoder()
{
 // pinA = bitRead(PIND,encoderPinA);
  /*pinA = bitRead(encoderPinA,1);
  Serial.print("pinA: ");
  Serial.println(pinA);
  pinB = bitRead(encoderPinB,1);
  Serial.print("pinB: ");
  Serial.println(pinB);
  pinC = bitRead(encoderPinC,1);
  Serial.print("pinC: ");
  Serial.println(pinC);
  pinD = bitRead(encoderPinD,1);
  Serial.print("pinD: ");
  Serial.println(pinD);
  *///dir = pinA ^ pinB;          // if pinA & pinB are the same
  pulse++;    // dir is CW, else CCW
}
