////////////////////////////////////////////////////////////////////////////////////
//
//
// Displays the LED's
// David Robinson
// David@kerplunk.co.uk
// 04/04/2022
//
//                               LED OUTPUT
//Hour Spacer Minute Spacer Seconds Spacer Day     Spacer Month   Spacer Temperature
//RED  White  Green  White  Blue    White  Yellow  White  Orange  White  Pink
//5    1      6      1      6       1      6       1      4       1      6
// Total LED's 38
/////////////////////////////////////////////////////////////////////////////////

#include <FastLED.h>
#define NUMLEDS 38
#define HourLED 5
#define MinutesLED 6
#define SecondsLED 6
#define DayLED 6
#define MonthLED 4
#define TemperatureLED 6
#define SpacerLED 1
#define HourColour CRGB::Red
#define SpacerColour CRGB::White
#define MinuteColour CRGB::Green
#define SecondsColour CRGB::Blue
#define DayColour CRGB::Yellow
#define MonthColour CRGB::Orange
#define TemperatureColour CRGB::DeepPink
#define NightBrightness 10
#define DayBrightness 240
#define LED_PIN 5
CRGB g_LEDs[NUMLEDS] = {0};

void DisplayTime(int SecondsBinary[], int HoursBinary[], int MinutesBinary[])
{   

    for (int i = 0 ; i < HourLED; i++)
    {
        if (HoursBinary[i] == 1)
        {
                  g_LEDs[i] = HourColour;
        } else 
        {
          g_LEDs[i] = CRGB::Black;
        }
    }

    int MinStart = HourLED + SpacerLED; // Should be 6
    int MinEnd = MinutesLED + MinStart; // should be 12

    for (int j = MinStart ; j < MinEnd ; j++)
    {
      if ( MinutesBinary[j - MinStart] == 1)
      {
        g_LEDs[j] = MinuteColour;
      } else
      {
        g_LEDs[j] = CRGB::Black;
      }
        
    }

    int SecondsStart = MinStart + SpacerLED + MinutesLED; // Should be 6
    int SecondsEnd = SecondsLED + SecondsStart; // should be 12
    
    for (int j = SecondsStart ; j < SecondsEnd ; j++)
    {   
           if (SecondsBinary[j - SecondsStart] == 1)
           {
                 g_LEDs[j] = SecondsColour;
           } else 
           {
                g_LEDs[j] = CRGB::Black;
           }
        
    }

    int DayStart = SecondsStart + SpacerLED + SecondsLED; // Should be 6
    int DayEnd = DayLED + DayStart; // should be 12
    
    for (int j = DayStart ; j < DayEnd ; j++)
    {
        g_LEDs[j] = DayColour;
        
    }

    int MonthStart = DayStart + SpacerLED + DayLED; // Should be 6
    int MonthEnd = MonthLED + MonthStart; // should be 12
    
    for (int j = MonthStart ; j < MonthEnd ; j++)
    {
        g_LEDs[j] = MonthColour;
        
    }     

    int TemperatureStart = MonthStart + SpacerLED + MonthLED; // Should be 6
    int TemperatureEnd = TemperatureLED + TemperatureStart; // should be 12
    
    for (int j = TemperatureStart ; j < TemperatureEnd ; j++)
    {
        g_LEDs[j] = TemperatureColour;
        
    }  
    FastLED.show(10);
}

void StartLED()
{

    pinMode(LED_PIN, OUTPUT);
    FastLED.addLeds<WS2812B,LED_PIN,GRB>(g_LEDs,NUMLEDS);
    FastLED.setMaxPowerInMilliWatts(300);
    FastLED.setBrightness(10);
}

