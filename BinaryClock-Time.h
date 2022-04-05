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

void ConvertTimeToBinary(int Seconds, int Minutes,int Hours, int Days, int Months)
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

    // 32,16,8,4,2,1
    int DaysBinary[]={0,0,0,0,0,0}; 
    for(int i=0;Days>0;i++)    
      {    
        DaysBinary[i]= Days % 2;    
        Days=Days / 2;    
      }

    for(int j=0; j < 6 ;j++)
      {   
        Serial.printf("%d",DaysBinary[j]);
      }
    Serial.println(" day in Binary");

    // 8,4,2,1
    int MonthBinary[]={0,0,0,0}; 
    for(int i=0;Months>0;i++)    
      {    
        MonthBinary[i]= Months % 2;    
        Months=Months / 2;    
      }

    for(int j=0; j < 4 ;j++)
      {   
        Serial.printf("%d",MonthBinary[j]);
      }
    Serial.println(" Month in Binary");
    DisplayTime(SecondsBinary,MinutesBinary,HoursBinary,DaysBinary,MonthBinary);

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
ConvertTimeToBinary(tm.tm_sec,tm.tm_min,tm.tm_hour,tm.tm_mday,tm.tm_mon + 1);
}