

void setup() {
pinMode(7, OUTPUT); //set direction pin as output
pinMode(9, OUTPUT); //set enable pin as output
//pinMode(8, OUTPUT); //set direction pin as output
//pinMode(10, OUTPUT);//set direction pin as output
}

void loop() {

//start off going forward at 50% throttle
digitalWrite(7, HIGH); //forward
//digitalWrite(8, HIGH); //forward
analogWrite(9,64); //25% PWM
//analogWrite(10,128); //50% PWM
delay(1000);



//and stop for a while
//digitalWrite(7, LOW); //turn enable pin off
//digitalWrite(8, LOW);
//delay(1000);

//now lets go backwards
digitalWrite(7, LOW); //backward
//digitalWrite(10, LOW); //backward
analogWrite(9,127); //50% PWM
//analogWrite(10,128); //50% PWM
delay(2000);


} 
