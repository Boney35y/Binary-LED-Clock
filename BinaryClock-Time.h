/////////////////////////////////////////////////////////////////////////
//
//
// Gets Time, Converts to Binary
// David Robinson
// David@kerplunk.co.uk
// 04/04/2022
//
//
/////////////////////////////////////////////////////////////////////////



#include <Arduino.h>
#include <stdio.h>
#include <time.h>
#include <LedDisplayClock.h>


void ConvertHoursToBinary(int hour)
{

}

void ConvertMinutesToBinary(int minute)
{

}

void ConvertMonthToBinary(int month)
{
    // 8,4,2,1
    int a[]={0,0,0,0}; 
    for(int i=0;month>0;i++)    
      {    
        a[i]= month % 2;    
        month=month / 2;    
      }

    for(int j=0; j < 4 ;j++)
      {   
        Serial.printf("%d",a[j]);
      }
    Serial.println(" Month in Binary");
}

void ConvertDayToBinary(int day)
{
    // 32,16,8,4,2,1
    int a[]={0,0,0,0,0,0}; 
    for(int i=0;day>0;i++)    
      {    
        a[i]= day % 2;    
        day=day / 2;    
      }

    for(int j=0; j < 6 ;j++)
      {   
        Serial.printf("%d",a[j]);
      }
    Serial.println(" day in Binary");
}

void ConvertTimeToBinary(int Seconds, int Hours, int Minutes)
{
    // Binary Hours will in 12 AM/PM Format
    // 16,8,4,2,1 Saves LED Space
    int HoursBinary[]={0,0,0,0,0}; 
    for(int i=0;Hours>0;i++)    
      {    
        HoursBinary[i]= Hours % 2;    
        Hours=Hours / 2;    
      }

    for(int j=0; j < 5 ;j++)
      {   
        Serial.printf("%d",HoursBinary[j]);
      }
    Serial.println(" Hour in Binary");

 // 32,16,8,4,2,1 - Minutes
    int MinutesBinary[]={0,0,0,0,0,0}; 
    for(int i=0;Minutes>0;i++)    
      {    
        MinutesBinary[i]= Minutes % 2;    
        Minutes=Minutes / 2;    
      }

    for(int j=0; j < 6 ;j++)
      {   
        Serial.printf("%d",MinutesBinary[j]);
      }
    Serial.println(" Minute in Binary");

 
 
 // 32,16,8,4,2,1 Seconds
    int SecondsBinary[]={0,0,0,0,0,0}; 
    for(int i=0;Seconds>0;i++)    
      {    
        SecondsBinary[i]= Seconds % 2;    
        Seconds=Seconds / 2;    
      }
 
    for(int j=0; j < 6 ;j++)
      {   
        Serial.printf("%d",SecondsBinary[j]);
      }
    Serial.println(" seconds in Binary");
    DisplayTime(SecondsBinary,MinutesBinary,HoursBinary);

}

void SetTime()
{
   struct tm timeinfo;
   const int daylightOffset_sec = 3600;
   const long gmtOffset_sec = 0;
   Serial.println("Setting up time");
   configTime(gmtOffset_sec, daylightOffset_sec, "pool.ntp.org");    // First connect to NTP server, with 0 TZ offset
   if(!getLocalTime(&timeinfo)){
   Serial.println("Failed to obtain time");
   return;
  }
  Serial.println("Got the time from NTP");
  
}

void GetTime()
{

// Gets Time From Time Source
time_t t = time(NULL);
struct tm tm = *localtime(&t);
Serial.printf("now: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
ConvertHoursToBinary(tm.tm_hour);
ConvertMinutesToBinary(tm.tm_min);
//ConvertSecondsToBinary(tm.tm_sec);
ConvertMonthToBinary(tm.tm_mon + 1);
ConvertDayToBinary(tm.tm_mday);
ConvertTimeToBinary(tm.tm_sec,tm.tm_min,tm.tm_hour);
}