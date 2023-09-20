#include <Arduino.h>

const int threshold = 80;
int abstop = 600;
int absbottom = 300;

void setup() 
{
    pinMode(A0, INPUT);
    Serial.begin(9600);
}

void loop() 
{
    int var1 = 0;
    int var2 = 0;
    int val = analogRead(A0);

    if(abstop - val < threshold)
    {
      var1 = abstop - val;
      if(var1 < 0)
      {
        var1 *= -1;
      }
    }
    if(val - absbottom < threshold)
    {
      var2 = val - absbottom;
      if(var2 < 0)
      {
        var2 *= -1;
      }
    }
    int mappedValue = map(val, absbottom - var2, abstop + var1, 0, 255);

    //Serial.print(0);
    //Serial.print(" ");
    //Serial.print(255);
    //Serial.print(" ");
    //Serial.println(mappedValue);

    Serial.print(var1);
    Serial.print(" ");
    Serial.print(var2);
    Serial.print(" ");
    Serial.print(val);
    Serial.print(" ");
    Serial.println(mappedValue);




    delay(10); 
}
