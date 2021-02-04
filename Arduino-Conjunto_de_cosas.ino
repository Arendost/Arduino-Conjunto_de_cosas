#include <LiquidCrystal.h>


const int rs = 12, en = 11, d4 = 15, d5 = 16, d6 = 17, d7 = 18;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int led= 9;
int sensor= A0;
int val;
int R=10;
int B=6;
int G=3;

int g=2;
int b=4;
int r=7;
int off=8;

int sa;
int sb;
int sc;
int sd;


int d=0;
int e=0;
int f=0;

void setup() {
Serial.begin(9800);

lcd.begin(16, 2); 
lcd.print("Color");

pinMode(led,OUTPUT);
pinMode(b, INPUT);
pinMode(g, INPUT);
pinMode(r, INPUT);


}

void loop() {

 lcd.setCursor(0, 1);
 lcd.print("azul:");
 lcd.setCursor(5, 1);
 lcd.print(d);

 lcd.setCursor(8, 1);
 lcd.print("rojo:");
 lcd.setCursor(13,1);
 lcd.print(f);
 
 lcd.setCursor(7, 0);
 lcd.print("verde:");
 lcd.setCursor(13,0);
 lcd.print(e);


int sa = digitalRead(b);
delay(1);

 if(sa==HIGH)
 {
  
  d=d+1;
  if(d>255)
  {
    d=0;
    lcd.setCursor(5, 1);
 lcd.print("   ");
  }
  analogWrite(B,d);  
 }


int sb = digitalRead(g);
delay(1);
 if(sb==HIGH)
 {
  
  e=e+1;
  if(e>255)
  {
    e=0;
    lcd.setCursor(13, 0);
 lcd.print("   ");
  }
  analogWrite(G,e);  
 }

 int sc = digitalRead(r);
delay(1);

 if(sc==HIGH)
 {
  
  f=f+1;
  if(f>255)
  {
    f=0;
    lcd.setCursor(13, 1);
 lcd.print("   ");
  }
  analogWrite(R,f);  
 }


 int sd = digitalRead(off);
delay(1);

 if(sd==HIGH)
 {
  

 d=0;
 e=0;
 f=0;
 lcd.setCursor(13, 0);
 lcd.print("   ");
 lcd.setCursor(5, 1);
 lcd.print("   "); 
 lcd.setCursor(13, 1);
 lcd.print("   ");
  analogWrite(R,0);
  analogWrite(G,0);
  analogWrite(B,0);
  
 }

 
  val = analogRead(sensor);
  
  if(val<450)
  {
    digitalWrite(led,HIGH);
  }
    else
    {
    digitalWrite(led,LOW);
  }

}
