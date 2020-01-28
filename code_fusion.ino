
#include <SoftwareSerial.h>
#define PINNUMBER "1234"
SoftwareSerial mySerial(11, 10);
#include <Keypad.h> 
#include <Wire.h> 
#include "rgb_lcd.h"
#include "DS1307.h"
#include <RTClib.h>
#define DS1307_ADDRESS 0x68
rgb_lcd lcd;
RTC_DS1307 RTC;
int hour ;
byte zero = 0x00;

int colorR = 0;
int colorG = 0;
int colorB = 0;


const byte numRows= 4;
const byte numCols= 3;

float sinVal;
int toneVal;

const int C4=3;
const int C3=7;
const int C2=6; 
const int L1=9; 
const int L2=8; 
const int L3=5; 
const int L4=4; 

char keypressed;
char keymap[numRows][numCols]=
{
  
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'},

};

byte rowPins[numRows] = {L1, L2, L3, L4};
byte colPins[numCols] = {C2, C3, C4,};           
Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);

const int buzzer = A1;        
const int lock = 0;       
String password="2580";
String disable="1234";
String tempPassword="";
int doublecheck;
int test=0;
boolean armed = false;
boolean input_pass;
boolean storedPassword = true;
boolean changedPassword = false;
boolean checkPassword = false;
int i = 1;

void setup(){
  Wire.begin();
  pinMode(lock,OUTPUT);
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Arduino Security");
  lcd.setCursor(0,1);
  lcd.print("Electric Door  ");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Safe opening  ");
  lcd.setCursor(0,1);
  lcd.print("With passsword  ");
  delay(1000);
  lcd.clear();
}

void loop() {
  unlockTheDoor();
    
}

void unlockTheDoor(){
  DateTime now = RTC.now();
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print(now.hour());
  lcd.print(":");
  if (now.minute() < 10) {
    lcd.print("0");
  }
  lcd.print(now.minute());
  lcd.print(":");
  if (now.second() < 10) {
    lcd.print("0");
  }
  lcd.print(now.second());
    

  }
    
  lockAgain:
  
  if(test==5){
    
    block();
  }
  lcd.clear();
  tempPassword="";
  i=6;
  noTone(buzzer);
  digitalWrite(lock, LOW);
  while(!checkPassword){
    lcd.setCursor(0,0);
    lcd.print("Enter the password:");
    lcd.setCursor(0,1);
    lcd.print("Password>>");
    lcd.setCursor(10,1);
    lcd.print(test);
    lcd.print("failure");
    keypressed = myKeypad.getKey();   
    if (keypressed != NO_KEY){   
      if (keypressed == '0' || keypressed == '1' || keypressed == '2' || keypressed == '3' ||
      keypressed == '4' || keypressed == '5' || keypressed == '6' || keypressed == '7' ||
      keypressed == '8' || keypressed == '9' ){
        tempPassword += keypressed;
        lcd.setCursor(i,1);
        lcd.print("*");      
        i++;
        tone(buzzer,800,200);  
      }
     
      else if (keypressed=='#'){
        break;
      }
      else if (keypressed == '*'){
        if (password==tempPassword){
          lcd.clear();      
          lcd.setCursor(0,0);
          lcd.print("Correct Password");
          lcd.setCursor(0,1);
          lcd.print("Door open");
          tone(buzzer,100);
          digitalWrite(lock, HIGH);
          delay(1500);
          test=0;
          goto lockAgain;
        }
        else{
          tempPassword="";
          tone(buzzer,500,200);
          delay(300);
          tone(buzzer,500,200);
          delay(300);
          lcd.clear();
          lcd.setCursor(6,0);
          lcd.print("password");
          lcd.setCursor(3,1);
          lcd.print("wrong");
          delay(500);
          test=test+1;
          goto lockAgain;
        }
      }
    }
  }
}
  

  
void block() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("alarm");
  test=0;
if ("password">5)                                                         //if there are more than 5 attempts
{
  void updateSerial()
{
  delay(2000);
  while (Serial.available()) {
    mySerial.write(Serial.read());
  }
  while(mySerial.available()) {
    Serial.write(mySerial.read());
  }
  
}   

void setup()
{
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop()
{ 
  mySerial.println("AT");         
  updateSerial();
    
  mySerial.println("AT+CPIN=1234");     
  updateSerial();

   mySerial.println("AT+CMGF=1");
   updateSerial();
   
   mySerial.println("AT+CMGS=\"+00XXXXXXXXX\"");       //+00XXXXXXXXX is the phone number for the GSM module
   updateSerial();
   
   mySerial.print("Attempted intrusion into the premises!");
   updateSerial();
   
   mySerial.write(26);
  
  while(1)
  { 
    if(mySerial.available()) 
    {
      Serial.write(mySerial.read());
    if(Serial.available())
    {
      mySerial.write(Serial.read());
    }   
  }
}
}
}
   boucle:
   tone(buzzer,500,200);
   delay(175);
   lcd.setRGB(255, 0, 0);
   tone(buzzer,900,200);
   delay(175);
   lcd.setRGB(0, 0, 255);
   goto boucle;
  }
    
String firstpass;
