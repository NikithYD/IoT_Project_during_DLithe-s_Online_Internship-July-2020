//Include Liquid Crystal library
#include <LiquidCrystal.h>
//The numbers of the Arduino pins that are connected to the corresponding data pins on the LCD.
LiquidCrystal lcd(2,A0,A1,A2,A3,A4);
float x;
//To read Ultrasonic distance using trigger and echo pins
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT); 
  // Clear the trigger
  digitalWrite(8, LOW);
  delayMicroseconds(2);
  //Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(8, HIGH);
  delayMicroseconds(10);
  digitalWrite(8, LOW);
  pinMode(9, INPUT);
  //Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(9, HIGH);
}
//Configures the specified pin to behave either as an input or an output. 
void setup()
{ //The Serial.begin() sets the baud rate for serial data communication
  Serial.begin(9600);
  //Initializes the interface to the LCD screen, and specifies the dimensions 
  lcd.begin(16,2);
  pinMode(A5, INPUT);
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
}

void loop()
{ //Distace is stored in 'x' in cm
  x=0.01723 * readUltrasonicDistance(8, 9);
 //Serial.print(x);
 //When distance is more than 10cm,this section is displayed in LCD
 if(x>10){
      lcd.setCursor(0,0);//Sts cursor for the dispaly
      lcd.print("Alcohol detector");//To display in LCD
      lcd.setCursor(0,1);
      lcd.print("Face distance should be 5cm");
      lcd.scrollDisplayLeft();//Scrolls the entire display left
      digitalWrite(3,0);//pins 3,4,6,7,10,11,12,13 are set low
      digitalWrite(4,0);
      digitalWrite(5,0);
      digitalWrite(6,0);
      digitalWrite(7,0);
      digitalWrite(10,0);
      digitalWrite(11,0);
      digitalWrite(12,0);
      digitalWrite(13,0);
 }
 //If distance(x) islesser or equal to 30 and less than 5cm
 //this section is executed,WHITE light is ON.
 if(x<=30&&x>5)
 {
   digitalWrite(3,1);//pin no. 3 is set to HIGH,approaching near
   digitalWrite(4,0);//pin no. 4 is set LOW
 }
  //If x is greater than 5 and less than or equal to 10, this section is executed
  //WHITE light is on
   if(x<10&&x>5.0)
   {digitalWrite(5,0);
    lcd.clear();//clears lcd display
    lcd.setCursor(4,0);//sets lcd cursor position
    lcd.print("WELCOME"); //displays content or value in the LCD display
    lcd.setCursor(2,1); //sets lcd cursor position
    lcd.print("Step closer"); //displays content or value in the LCD display
    delay(1000);//delay of 500 milliseconds to improve simulation
    lcd.clear();
    //clears lcd display
    lcd.setCursor(2,0);
    //sets lcd cursor position
    lcd.print("Wait for the");
    //displays content or value in the LCD display
    lcd.setCursor(3,1);
    lcd.print("GREEN LIGHT");
    delay(1000);//delay of 1 sec
    lcd.clear();//clears lcd display
    delay(500);//delay of 0.5sec
   }
 //Alcohol content detection
 //When distance of the face is equal 5cm, green light turns on
 //The person can blow and alcohol content is detected
 
  if(x<=5.0)
  {
   digitalWrite(5,1);//pin no. 5 is setHIGH
   digitalWrite(4,0);//pin no. 4is set LOW
   tone(4,900,10);// tone (pin no,frequency,duration) of beep
    delay(10);
  }
  
 if(x<=5.00)
 { 
   lcd.clear();//clears screen
   Serial.println(analogRead(A5));//prints alcohol content value in Serial monitor
   digitalWrite(4,0);//pin no. 4 is set LOW.
   lcd.setCursor(0,0);//sets cursor
   lcd.print(" Ready to blow");//Displays "Ready to Blow" on LCD
   delay(100);//delay of 100 milliseconds
//Alcohol content value>20 and <=25, this section executes 
   if(analogRead(A5)>=20&&analogRead(A5)<=25)
   { lcd.clear();
     noTone(4);
     lcd.setCursor(1,0);//set cursor for the dispaly
     lcd.print("Intensity LOW");
     lcd.setCursor(0,1);
     lcd.print("Alcohol level:1");
     delay(1500);//delay of 1000 milliseconds to improve simulation
     digitalWrite(6,1);//pin no.6 is HIGH
     digitalWrite(7,0);//pin no.7is LOW
     digitalWrite(10,0);//pin no.10 LOW
     digitalWrite(11,0);//pin no.11 LOW
     digitalWrite(12,0); //pin no.12is LOW
     digitalWrite(13,0);//pin no.13 is LOw
  }
 //Alcohol content value>25 and <=30,this section executes 
   if(analogRead(A5)>25&&analogRead(A5)<=30)
    {lcd.clear();
     noTone(4);
     lcd.begin(16,2);
     lcd.setCursor(0,0);
     lcd.print("Intensity LOW");
     lcd.setCursor(0,1);
     lcd.print("Alcohol level:2");
     delay(1500);//delay of 1500 milliseconds
     digitalWrite(6,1);//only pin no. 6&7 is HIGH, remaining are set low
     digitalWrite(7,1);
     digitalWrite(10,0);
     digitalWrite(11,0);
     digitalWrite(12,0);
     digitalWrite(13,0);
     }
   //Alcohol content value>30& <=40,this section executes    
     if(analogRead(A5)>30&&analogRead(A5)<=40)
    {lcd.clear();
     noTone(4);
     lcd.setCursor(0,0);
     lcd.print("Intensity LOW");
     lcd.setCursor(0,1);
     lcd.print("Alcohol level:3");
     delay(1500);//delay of 1500 milliseconds
     digitalWrite(7,1);//only pin no. 6&7 is HIGH, remaining are set low
     digitalWrite(6,1);
     digitalWrite(10,0);
     digitalWrite(11,0);
     digitalWrite(12,0);
     digitalWrite(13,0);
    }
  //Alcohol content value>40& <=50,this section executes 
   if(analogRead(A5)>40&&analogRead(A5)<=50)
   { lcd.clear();
     noTone(4);
     lcd.setCursor(0,0);
     lcd.print("Intensity MEDIUM");
     lcd.setCursor(0,1);
     lcd.print("Alcohol level:4");
     delay(1500);//delay of 1500 milliseconds
     digitalWrite(7,1);//pin no. 7,6,10 are set high, remaing are set low
     digitalWrite(6,1);
     digitalWrite(10,1);
     digitalWrite(11,0); 
     digitalWrite(12,0);
     digitalWrite(13,0);
     
    }
   //Alcohol content value>50& <=60,this section executes 
    if(analogRead(A5)>50&&analogRead(A5)<=60)
    {lcd.clear();
     noTone(4);
     lcd.setCursor(0,0);
     lcd.print("Intensity MEDIUM");
     lcd.setCursor(0,1);
     lcd.print("Alcohol level:5");
     delay(1500);//delay of 1500 milliseconds
     digitalWrite(6,1);//pin no. 7,6,10 are set high, remaing are set low
     digitalWrite(7,1);
     digitalWrite(10,1);
     digitalWrite(11,0);
     digitalWrite(12,0);
     digitalWrite(13,0);
     
    }
   //Alcohol content value>60 and less than 70
   if(analogRead(A5)>60&&analogRead(A5)<=70)
    {lcd.clear();
     noTone(4);
     lcd.setCursor(0,0);
     lcd.print("Intensity MEDIUM");
     lcd.setCursor(0,1);
     lcd.print("Alcohol level:6");
     delay(1500);//delay of 1500 milliseconds
     digitalWrite(6,1);//pin no. 6,7,10,11 are set high, remaining are set low
     digitalWrite(7,1);
     digitalWrite(10,1);
     digitalWrite(11,1);
     digitalWrite(12,0);
     digitalWrite(13,0);
     
    }
   //Alcohol content value>70 and less than 80
   if(analogRead(A5)>70&&analogRead(A5)<=80)
    {lcd.clear();
     noTone(4);
     lcd.setCursor(1,0);
     lcd.print("Intensity HIGH");
     lcd.setCursor(0,1);
     lcd.print("Alcohol level:7");
     delay(1500);//delay of 1500 milliseconds
     digitalWrite(6,1);//pin no. 6,7,10,11 are set high, remaining are set low
     digitalWrite(7,1);
     digitalWrite(10,1);
     digitalWrite(11,1);
     digitalWrite(12,0);
     digitalWrite(13,0);
     
    }
    //Alcohol content value>80 and less than or equal to 90
   if(analogRead(A5)>80&&analogRead(A5)<=90)
    {lcd.clear();
     noTone(4);
     lcd.setCursor(1,0);
     lcd.print("Intensity HIGH");
     lcd.setCursor(0,1);
     lcd.print("Alcohol level:8");
     delay(1500);//delay of 1500 milliseconds
     digitalWrite(6,1);//pin no. 6,7,10,11,12 are set high, remaining are set low
     digitalWrite(7,1);
     digitalWrite(10,1);
     digitalWrite(11,1);
     digitalWrite(12,1);
     digitalWrite(13,0);
     
    }
   //Alcohol content value>90 and less than or equal to 100
   if(analogRead(A5)>90&&analogRead(A5)<=100)
    {lcd.clear();
     noTone(4);
     lcd.setCursor(1,0);
     lcd.print("Intensity HIGH");
     lcd.setCursor(0,1);
     lcd.print("Alcohol level:9");
     delay(1500);//delay of 1500 milliseconds
     digitalWrite(6,1);//pin no. 6,7,10,11,12 are set high, remaining are set low
     digitalWrite(7,1);
     digitalWrite(10,1);
     digitalWrite(11,1);
     digitalWrite(12,1);
     digitalWrite(13,0);
     
    }
   //Alcohol content value greater than 100
  if(analogRead(A5)>100)
    {lcd.clear();
     noTone(4);
     lcd.setCursor(0,0);
     lcd.print("ALERT!!!ALERT!!!");
     lcd.setCursor(0,1);
     lcd.print("Alcohol level:10");
     delay(1500);//delay of 1500 milliseconds
     digitalWrite(7,1);//All digital(led) pins are set high,all the 6 are ON
     digitalWrite(6,1);
     digitalWrite(10,1);
     digitalWrite(11,1);
     digitalWrite(12,1);
     digitalWrite(13,1);
     
      
    }
 }
}
