/////////////////////////////////////////////////////////////////////////
//
//
// Gets Temperature (From Probe), Converts to Binary
// David Robinson
// David@kerplunk.co.uk
// 04/04/2022
//
//
/////////////////////////////////////////////////////////////////////////
#include <Arduino.h>
#include <stdio.h>    
#include <stdlib.h>  

void ConvertTempToBinary(int Temperature)
{
    // Converts temp to Binary
    // 32,16,8,4,2,1  - Max 63 Degrees C anything Above that and we won't be really bothered
    int a[]={0,0,0,0,0,0}; 
    for(int i=0;Temperature>0;i++)    
      {    
        a[i]=Temperature % 2;    
        Temperature=Temperature / 2;    
      }

    for(int j=0; j < 6 ;j++)
      {   
        Serial.printf("%d",a[j]);
      }
    Serial.println(" Temperature in Binary");
}

void GetTemp()
{
    // Gets temperature from Digital temp probe
    // Max Temperature We want is 63 min is 0
    int Temperature = 4;
    if (Temperature > 63)
    {
        Temperature = 63;
    }
    ConvertTempToBinary(Temperature);
}