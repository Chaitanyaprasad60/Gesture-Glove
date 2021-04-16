#include<Wire.h>                                  //header files
#include <SPI.h>
#include <RH_NRF24.h>


RH_NRF24 nrf24(8,7);                            //Variable assignment
const int flexpinl=A3;
const int flexpinr=A2;
const int buttonp=4;
const int MPU6050_addr=0x68;
int16_t AccX,AccY,AccZ;
const int trigpin = 3;                          // Trigger Pin of Ultrasonic Sensor
const int echopin = 5;   
long duration,dist;
char c,q;                                  /*a for AccX, b for AccY, c for Flexpinl, d for Flexpinr*/
int flexvaluel,flexvaluer;
boolean button = false; 
uint8_t data[]="aa",a[]="z",b[]="z",e[]="z",d[]="z";    


    
void setup()                                     //set up
{    
  Serial.begin(9600);                           //serial begin
  
  Wire.begin();                                  //setup MPU6050                             
  Wire.beginTransmission(MPU6050_addr);
  Wire.write(0x6B);
 Wire.write(0);
  Wire.endTransmission(true);
  
  pinMode(flexpinr,INPUT);                      //set up flex pins
  pinMode(flexpinl,INPUT);
  pinMode(buttonp,INPUT);
  
    while (!Serial)                             //set up NRF024L01
    ; 
  if (!nrf24.init())
    Serial.println("init failed");
  // Defaults after init are 2.402 GHz (channel 2), 2Mbps, 0dBm
  if (!nrf24.setChannel(1))
    Serial.println("setChannel failed");
  if (!nrf24.setRF(RH_NRF24::DataRate2Mbps, RH_NRF24::TransmitPower0dBm))
    Serial.println("setRF failed");    


  pinMode(trigpin,OUTPUT);    //US sensor 
  pinMode(echopin,INPUT);

}

void loop()
{ a[0]='z';
b[0]='z';
c='z';
d[0]='z';
 e[0]='z';
   
  readaccelero();   //sensors read start
  readflex();
 // readkey();
  
 

  if(digitalRead(buttonp)==HIGH)
  {
     d[0]='i';
     nrf24.send( d, sizeof(d));
     nrf24.waitPacketSent();
  }
  
  
  
  //if(digitalRead(buttonp)==HIGH)
 // button=!button;

 //if(button==true)
 //{ //readkey(); 
            //sensors read end
 //}

    
 //Serial.println(flexvaluel);
      
//Serial.println(flexvaluer);



delay(100);
}


 void readaccelero()
  {
    Wire.beginTransmission(MPU6050_addr);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050_addr,14,true);
  AccX=Wire.read()<<8|Wire.read();
  AccY=Wire.read()<<8|Wire.read();
  // Serial.print(AccX);
  
  if(AccX<-3000)
  a[0]='a';
  else if(AccX<-7000)
  a[0]='b';
  else if(AccX>3000)
  a[0]='c';
  else if(AccX>7000)
  a[0]='d';



  if(AccY<-3000)
  a[0]='e';
  else if(AccY<-7000)
  a[0]='f';
  else if(AccY>3000)
  a[0]='g';
  else if(AccY>7000)
   a[0]= 'h';

 // Serial.println(a);
 nrf24.send( a, sizeof(a));
 nrf24.waitPacketSent();

  
  
  }

void readflex()
  {
    flexvaluel = analogRead(flexpinl);
    flexvaluer = analogRead(flexpinr);
 //Serial.println(flexvaluer);
      if(flexvaluel>820)
      { b[0]='l';
      //delay(100);
      }
      else if(flexvaluer>782)
      { b[0]='r';
      //delay(100);
      }

     //Serial.println(b);
      nrf24.send(b, sizeof(b));
      nrf24.waitPacketSent();
      
  }

/*void readkey()
  {
  digitalWrite(trigpin,LOW);
   delayMicroseconds(2);
   digitalWrite(trigpin,HIGH);
   delayMicroseconds(10);
   digitalWrite(trigpin,LOW);
   duration = pulseIn(echopin,HIGH);
   dist=duration*0.034/2;
   
 e[0]=key(dist);
  
   
   nrf24.send(e, sizeof(e));
      nrf24.waitPacketSent();


 }

/*char key(int dist)
{ 

    if(dist>2000)
    c='i';
    if(dist>=5&&dist<=8)
    c='t';
    if(dist>8&&dist<=10)
    c='u';
    if(dist>10&&dist<=13)
    c='w';
    return c;
 
 }
*/

 
   
