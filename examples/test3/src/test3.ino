/*
 * Project test3
 * Description: one step towards a PxEPD2 library
 * Author: Jean-Marc Zingg
 * Date: 10.12.2018
 */

#include <GxEPD2_154.h>
#include <GxEPD2_750c.h>
#include "Bitmaps200x200.h" // 1.54" b/w
#include "Bitmaps640x384.h" // 7.5"  b/w

#include <Adafruit_GFX.h>
#include <FreeMonoBold9pt7b.h>

// A5 MOSI
// A4 MISO
// A3 SCK
// A2 SS
// mapping suggestion from Waveshare SPI e-Paper to Particle Photon
// BUSY -> D4, RST -> A0, DC -> A1, CS -> A2, CLK -> A3, DIN -> A5, GND -> GND, 3.3V -> 3.3V
// NOTE: it looks like MISO can't be used as general input pin for BUSY.

// set USE_BUFFERED_DRAWING 0 for minimal version without template class use
#define USE_BUFFERED_DRAWING 1

#if !USE_BUFFERED_DRAWING

//select one and adapt to your mapping, minimal version for direct drawing only
GxEPD2_154 display(/*CS=D5*/ SS, /*DC=*/ A1, /*RST=*/ A0, /*BUSY=*/ D4);
//GxEPD2_750c display(/*CS=D5*/ SS, /*DC=*/ A1, /*RST=*/ A0, /*BUSY=*/ D4);

#else

#include <PxEPD2_BW.h>
#include <PxEPD2_3C.h>

// select one and adapt to your mapping, for buffered drawing, can use full buffer size (full HEIGHT) for Photon
PxEPD2_BW<GxEPD2_154, GxEPD2_154::HEIGHT> display(GxEPD2_154(/*CS=D5*/ SS, /*DC=*/ A1, /*RST=*/ A0, /*BUSY=*/ D4));
//PxEPD2_3C<GxEPD2_750c, GxEPD2_750c::HEIGHT / 4> display(GxEPD2_750c(/*CS=D5*/ SS, /*DC=*/ A1, /*RST=*/ A0, /*BUSY=*/ D4));

#endif

void setup()
{
   pinMode(D7, OUTPUT);
   digitalWrite(D7, LOW);
   delay(10000);
   // time to connect serial monitor
   digitalWrite(D7, HIGH);
   delay(5000);
   digitalWrite(D7, LOW);
   Serial.begin(115200);
   Serial.println();
   Serial.println("setup");
   display.init(115200);
   Serial.println("init done");
   display.clearScreen();
   helloWorld();
   delay(2000);
   display.drawImage(logo200x200, 0, 0, 200, 200);
   delay(2000);
   display.drawImage(Bitmap640x384_1, 0, 0, 640, 384);
   delay(2000);
}

void loop()
{
  static bool first = false;
  if (first) Serial.println("loop entered");
  first = false;
  //Serial.println("HIGH");
  //digitalWrite(D7, HIGH);
  delay(1000);
  //Serial.println("LOW");
  //digitalWrite(D7, LOW);
  delay(2000);
}

#if USE_BUFFERED_DRAWING

void helloWorld()
{
  //Serial.println("helloWorld");
  display.setRotation(1);
  display.setFont(&FreeMonoBold9pt7b);
  display.setTextColor(GxEPD_BLACK);
  uint16_t x = (display.width() - 160) / 2;
  uint16_t y = display.height() / 2;
  display.setFullWindow();
  display.firstPage();
  do
  {
    display.fillScreen(GxEPD_WHITE);
    display.setCursor(x, y);
    display.println("Hello World!");
  }
  while (display.nextPage());
  //Serial.println("helloWorld done");
}

#endif
