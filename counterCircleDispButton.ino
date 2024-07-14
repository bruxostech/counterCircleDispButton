/*
 *  This sketch demonstrates how to scan WiFi networks.
 *  The API is based on the Arduino WiFi Shield library, but has significant changes as newer WiFi functions are supported.
 *  E.g. the return value of `encryptionType()` different because more modern encryption is supported.
 *  
 */
#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 16
#define DATA_PIN 12
#define BUTTON_PIN 14

// Define the array of leds
CRGB leds[NUM_LEDS];
CRGB color;
bool buttonState = false; 

bool Request;
bool Start = false;

void IRAM_ATTR isr() {
 Request = true;
 buttonState = !(buttonState);
}

void initLeds()
{
  for (int ii=0; ii < 16; ii++)
   {
      leds[ii] = CRGB::Black;
   }  
}

void setup() {
  //Serial.begin(115200);
  //delay(100);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // GRB ordering is assumed
  pinMode(BUTTON_PIN, INPUT);
  attachInterrupt(BUTTON_PIN, isr, RISING);
}
int ii = 0;
int jj = 0;

void loop() {
  if (Request){
   Request = false;
   initLeds();
   ii = 0;
 }

 if (ii <= NUM_LEDS)
 {
    ii++;
 }

 switch(ii)
 {
    case 0:
    case 1:
    case 2:
      leds[ii] = CRGB::Lime;
      break;
    case 3:
    case 4:
    case 5: 
      leds[ii] = CRGB::Green;
      break; 
    case 6:
    case 7:
    case 8: 
      leds[ii] = CRGB::Yellow;
      break; 
    case 9:
    case 10:
    case 11: 
      leds[ii] = CRGB::Yellow;
      break; 
    case 12:
    case 13:
    case 14: 
      leds[ii] = CRGB::MediumVioletRed;
      break; 
    case 15:
      for (int ii=0; ii < 16; ii++)
      {
        leds[ii] = CRGB::Red;
      }
      break;  
    case 16:
      for (int ii=0; ii < 16; ii++)
      {
        leds[ii] = CRGB::Black;
        jj = 6;
      }
      break;  
          
 }
  FastLED.show(); 
  if (jj == 0)
    delay(625); 
  else
  {
    int rr = jj % 2;
    if (rr ==0)
    {
      color = CRGB::Red;
    }
    else
    {
      color = CRGB::Black;
    }
    for (int ii=0; ii < 16; ii++)
    {
      
        leds[ii] = color;     
    }
    jj--;
    delay(100);
    
  }

}
