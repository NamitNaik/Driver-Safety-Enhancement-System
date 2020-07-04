#define m11 11    // rear motor
#define m12 12
#define m21 10    // front motor
#define m22 9

char str[2],i;

void forward()
{
   digitalWrite(m11, LOW);
   digitalWrite(m12, LOW);
   digitalWrite(m21, HIGH);
   digitalWrite(m22, LOW);
}

void backward()
{
   digitalWrite(m11, LOW);
   digitalWrite(m12, LOW);
   digitalWrite(m21, LOW);
   digitalWrite(m22, HIGH); 
}

void left()
{
   digitalWrite(m11, HIGH);
   digitalWrite(m12, LOW);
   delay(100);
   digitalWrite(m21, HIGH);
   digitalWrite(m22, LOW);
}

void right()
{
   digitalWrite(m11, LOW);
   digitalWrite(m12, HIGH);
   delay(100);
   digitalWrite(m21, HIGH);
   digitalWrite(m22, LOW);
}

void Stop()
{
   digitalWrite(m11, LOW);
   digitalWrite(m12, LOW);
   digitalWrite(m21, LOW);
   digitalWrite(m22, LOW);
}
int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 8;      // select the pin for the LED
int sensorValue = 0;
long time1;
boolean flag=1;
void setup() 
{
  Serial.begin(9600);
  pinMode(m11, OUTPUT);
  pinMode(m12, OUTPUT);
  pinMode(m21, OUTPUT);
  pinMode(m22, OUTPUT);
pinMode(ledPin, OUTPUT);
//digitalWrite(ledPin,LOW);
}

void loop() 
{
  while(Serial.available())
  {
    char ch=Serial.read();
    str[i++]=ch;
    
    if(str[i-1]=='1')
    {
     Serial.println("Forward");
     forward();
     i=0;
    }

    else if(str[i-1]=='2')
    {
     Serial.println("Left");
     right();
     i=0;
    }

    else if(str[i-1]=='3')
    {
      Serial.println("Right");
      left();
      i=0;
    }
    
    else if(str[i-1]=='4')
    {
      Serial.println("Backward");
      backward();
      i=0;
    }

    else if(str[i-1]=='5')
    {
      Serial.println("Stop");
      Stop();
      i=0;
    }
    delay(100);
  }
sensorValue=analogRead(A0);
 Serial.print("POT:");
 Serial.println(sensorValue);
//isConstant();



//Serial.println(millis()-time1);
if(sensorValue>=460 && sensorValue<=560){
  if(flag==1){
  time1=millis();
  flag=0;
  }
if(millis()-time1>10000)
{
digitalWrite(ledPin,HIGH);
Stop();
}
}
else{

digitalWrite(ledPin,LOW);
flag=1;
}


//  if(analogRead(A0)>=460 || analogRead(A0)<=560){
//  digitalWrite(ledPin,HIGH); 
// }else{
//  digitalWrite(ledPin,LOW);
// }

}
void isConstant()
{
 time1=millis();

}
