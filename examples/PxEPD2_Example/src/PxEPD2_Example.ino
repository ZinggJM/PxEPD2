// Display Library example for SPI e-paper panels from Dalian Good Display and boards from Waveshare.
// Requires HW SPI and Adafruit_GFX. Caution: these e-papers require 3.3V supply AND data lines!
//
// Display Library based on Demo Example from Good Display: http://www.good-display.com/download_list/downloadcategoryid=34&isMode=false.html
//
// Author: Jean-Marc Zingg
//
// Version: see library.properties
//
// Library: https://github.com/ZinggJM/GxEPD2_PP
//
// NOTE: the following #include needs to be placed here or higher up; comment out to see issue with Desktop IDE (strange error reported)
#include <Adafruit_GFX_RK.h>

// Supporting Arduino Forum Topics:
// Waveshare e-paper displays with SPI: http://forum.arduino.cc/index.php?topic=487007.0
// Good Dispay ePaper for Arduino : https://forum.arduino.cc/index.php?topic=436411.0

// mapping suggestion from Waveshare SPI e-Paper to Particle Photon
// A5 MOSI
// A4 MISO
// A3 SCK
// A2 SS
// BUSY -> D4, RST -> A0, DC -> A1, CS -> A2, CLK -> A3, DIN -> A5, GND -> GND, 3.3V -> 3.3V
// NOTE: it looks like MISO can't be used as general input pin for BUSY.

// base class GxEPD2_GFX can be used to pass references or pointers to the display instance as parameter, uses ~1.2k more code
// enable or disable GxEPD2_GFX base class
#define ENABLE_GxEPD2_GFX 0

#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <FreeMonoBold9pt7b.h>

#include <GxEPD2_BW.h>
#include <GxEPD2_3C.h>

#if defined(PARTICLE)
// select one and adapt to your mapping, for buffered drawing, can use full buffer size (full HEIGHT) for Photon
GxEPD2_BW<GxEPD2_154, GxEPD2_154::HEIGHT> display(GxEPD2_154(/*CS=D5*/ SS, /*DC=*/ A1, /*RST=*/ A0, /*BUSY=*/ D4));
//GxEPD2_BW<GxEPD2_213, GxEPD2_213::HEIGHT> display(GxEPD2_213(/*CS=D5*/ SS, /*DC=*/ A1, /*RST=*/ A0, /*BUSY=*/ D4));
//GxEPD2_BW<GxEPD2_213_flex, GxEPD2_213_flex::HEIGHT> display(GxEPD2_213_flex(/*CS=D5*/ SS, /*DC=*/ A1, /*RST=*/ A0, /*BUSY=*/ D4));
//GxEPD2_BW<GxEPD2_290, GxEPD2_290::HEIGHT> display(GxEPD2_290(/*CS=D5*/ SS, /*DC=*/ A1, /*RST=*/ A0, /*BUSY=*/ D4));
//GxEPD2_BW<GxEPD2_270, GxEPD2_270::HEIGHT> display(GxEPD2_270(/*CS=D5*/ SS, /*DC=*/ A1, /*RST=*/ A0, /*BUSY=*/ D4));
//GxEPD2_BW<GxEPD2_420, GxEPD2_420::HEIGHT> display(GxEPD2_420(/*CS=D5*/ SS, /*DC=*/ A1, /*RST=*/ A0, /*BUSY=*/ D4));
//GxEPD2_BW < GxEPD2_583, GxEPD2_583::HEIGHT / 2 > display(GxEPD2_583(/*CS=D5*/ SS, /*DC=*/ A1, /*RST=*/ A0, /*BUSY=*/ D4));
//GxEPD2_BW < GxEPD2_750, GxEPD2_750::HEIGHT / 2 > display(GxEPD2_750(/*CS=D5*/ SS, /*DC=*/ A1, /*RST=*/ A0, /*BUSY=*/ D4));
// 3-color e-papers
//GxEPD2_3C<GxEPD2_154c, GxEPD2_154c::HEIGHT> display(GxEPD2_154c(/*CS=D5*/ SS, /*DC=*/ A1, /*RST=*/ A0, /*BUSY=*/ D4));
//GxEPD2_3C<GxEPD2_213c, GxEPD2_213c::HEIGHT> display(GxEPD2_213c(/*CS=D5*/ SS, /*DC=*/ A1, /*RST=*/ A0, /*BUSY=*/ D4));
//GxEPD2_3C<GxEPD2_290c, GxEPD2_290c::HEIGHT> display(GxEPD2_290c(/*CS=D5*/ SS, /*DC=*/ A1, /*RST=*/ A0, /*BUSY=*/ D4));
//GxEPD2_3C<GxEPD2_270c, GxEPD2_270c::HEIGHT> display(GxEPD2_270c(/*CS=D5*/ SS, /*DC=*/ A1, /*RST=*/ A0, /*BUSY=*/ D4));
//GxEPD2_3C<GxEPD2_420c, GxEPD2_420c::HEIGHT> display(GxEPD2_420c(/*CS=D5*/ SS, /*DC=*/ A1, /*RST=*/ A0, /*BUSY=*/ D4));
//GxEPD2_3C<GxEPD2_583c, GxEPD2_583c::HEIGHT / 4 > display(GxEPD2_583c(/*CS=D5*/ SS, /*DC=*/ A1, /*RST=*/ A0, /*BUSY=*/ D4));
//GxEPD2_3C<GxEPD2_750c, GxEPD2_750c::HEIGHT / 4 > display(GxEPD2_750c(/*CS=D5*/ SS, /*DC=*/ A1, /*RST=*/ A0, /*BUSY=*/ D4));
#endif

// comment out unused bitmaps to reduce code space used
#include "Bitmaps200x200.h" // 1.54" b/w
#include "Bitmaps128x250.h" // 2.13" b/w
#include "Bitmaps128x296.h" // 2.9"  b/w
#include "Bitmaps176x264.h" // 2.7"  b/w
#include "Bitmaps400x300.h" // 4.2"  b/w
#include "Bitmaps640x384.h" // 7.5"  b/w
// 3-color
#include "Bitmaps3c200x200.h" // 1.54" b/w/r
#include "Bitmaps3c104x212.h" // 2.13" b/w/r
#include "Bitmaps3c128x296.h" // 2.9"  b/w/r
#include "Bitmaps3c176x264.h" // 2.7"  b/w/r
#include "Bitmaps3c400x300.h" // 4.2"  b/w/r

void setup()
{
  delay(5000);
  Serial.begin(115200);
  Serial.println();
  Serial.println("setup");
  delay(1000);
  display.init(115200);
  // first update should be full refresh
  helloWorld();
  delay(1000);
  // partial refresh mode can be used to full screen,
  // effective if display panel hasFastPartialUpdate
  helloFullScreenPartialMode();
  delay(1000);
  helloArduino();
  delay(1000);
  helloEpaper();
  delay(1000);
  showFont("FreeMonoBold9pt7b", &FreeMonoBold9pt7b);
  delay(1000);
  drawBitmaps();
  if (display.epd2.hasPartialUpdate)
  {
    showPartialUpdate();
    delay(1000);
  } // else // on GDEW0154Z04 only full update available, doesn't look nice
  //drawCornerTest();
  //showBox(16, 16, 48, 32, false);
  //showBox(16, 56, 48, 32, true);
  display.powerOff();
  Serial.println("setup done");
}

void loop()
{
}

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

void helloFullScreenPartialMode()
{
  //Serial.println("helloFullScreenPartialMode");
  display.setPartialWindow(0, 0, display.width(), display.height());
  display.setRotation(1);
  display.setFont(&FreeMonoBold9pt7b);
  display.setTextColor(GxEPD_BLACK);
  display.firstPage();
  do
  {
    uint16_t x = (display.width() - 160) / 2;
    uint16_t y = display.height() / 2;
    display.fillScreen(GxEPD_WHITE);
    display.setCursor(x, y);
    display.println("Hello World!");
    y = display.height() / 4;
    display.setCursor(x, y);
    display.println("full screen");
    y = display.height() * 3 / 4;
    if (display.width() <= 200) x = 0;
    display.setCursor(x, y);
    if (display.epd2.hasFastPartialUpdate)
    {
      display.println("fast partial mode");
    }
    else if (display.epd2.hasPartialUpdate)
    {
      display.println("slow partial mode");
    }
    else
    {
      display.println("no partial mode");
    }
  }
  while (display.nextPage());
  //Serial.println("helloFullScreenPartialMode done");
}

void helloArduino()
{
  //Serial.println("helloArduino");
  display.setRotation(1);
  display.setFont(&FreeMonoBold9pt7b);
  display.setTextColor(display.epd2.hasColor ? GxEPD_RED : GxEPD_BLACK);
  uint16_t x = (display.width() - 160) / 2;
  uint16_t y = display.height() / 4;
  display.setPartialWindow(0, y - 14, display.width(), 20);
  display.firstPage();
  do
  {
    display.fillScreen(GxEPD_WHITE);
    display.setCursor(x, y);
    display.println("Hello Arduino!");
  }
  while (display.nextPage());
  delay(1000);
  //Serial.println("helloArduino done");
}

void helloEpaper()
{
  //Serial.println("helloEpaper");
  display.setRotation(1);
  display.setFont(&FreeMonoBold9pt7b);
  display.setTextColor(display.epd2.hasColor ? GxEPD_RED : GxEPD_BLACK);
  uint16_t x = (display.width() - 160) / 2;
  uint16_t y = display.height() * 3 / 4;
  display.setPartialWindow(0, y - 14, display.width(), 20);
  display.firstPage();
  do
  {
    display.fillScreen(GxEPD_WHITE);
    display.setCursor(x, y);
    display.println("Hello E-Paper!");
  }
  while (display.nextPage());
  //Serial.println("helloEpaper done");
}

void showBox(uint16_t x, uint16_t y, uint16_t w, uint16_t h, bool partial)
{
  //Serial.println("showBox");
  display.setRotation(1);
  if (partial)
  {
    display.setPartialWindow(x, y, w, h);
  }
  else
  {
    display.setFullWindow();
  }
  display.firstPage();
  do
  {
    display.fillScreen(GxEPD_WHITE);
    display.fillRect(x, y, w, h, GxEPD_BLACK);
  }
  while (display.nextPage());
  //Serial.println("showBox done");
}

void drawCornerTest()
{
  display.setFullWindow();
  display.setFont(&FreeMonoBold9pt7b);
  display.setTextColor(GxEPD_BLACK);
  for (uint16_t r = 0; r <= 4; r++)
  {
    display.setRotation(r);
    display.firstPage();
    do
    {
      display.fillScreen(GxEPD_WHITE);
      display.fillRect(0, 0, 8, 8, GxEPD_BLACK);
      display.fillRect(display.width() - 18, 0, 16, 16, GxEPD_BLACK);
      display.fillRect(display.width() - 25, display.height() - 25, 24, 24, GxEPD_BLACK);
      display.fillRect(0, display.height() - 33, 32, 32, GxEPD_BLACK);
      display.setCursor(display.width() / 2, display.height() / 2);
      display.print(display.getRotation());
    }
    while (display.nextPage());
    delay(2000);
  }
}

void showFont(const char name[], const GFXfont* f)
{
  display.setFullWindow();
  display.setRotation(0);
  display.setTextColor(GxEPD_BLACK);
  display.firstPage();
  do
  {
    drawFont(name, f);
  }
  while (display.nextPage());
}

void drawFont(const char name[], const GFXfont* f)
{
  //display.setRotation(0);
  display.fillScreen(GxEPD_WHITE);
  display.setTextColor(GxEPD_BLACK);
  display.setFont(f);
  display.setCursor(0, 0);
  display.println();
  display.println(name);
  display.println(" !\"#$%&'()*+,-./");
  display.println("0123456789:;<=>?");
  display.println("@ABCDEFGHIJKLMNO");
  display.println("PQRSTUVWXYZ[\\]^_");
  if (display.epd2.hasColor)
  {
    display.setTextColor(GxEPD_RED);
  }
  display.println("`abcdefghijklmno");
  display.println("pqrstuvwxyz{|}~ ");
}

void showPartialUpdate()
{
  // some useful background
  helloWorld();
  // use asymmetric values for test
  uint16_t box_x = 10;
  uint16_t box_y = 15;
  uint16_t box_w = 70;
  uint16_t box_h = 20;
  uint16_t cursor_y = box_y + box_h - 6;
  float value = 13.95;
  uint16_t incr = display.epd2.hasFastPartialUpdate ? 1 : 3;
  display.setFont(&FreeMonoBold9pt7b);
  display.setTextColor(GxEPD_BLACK);
  // show where the update box is
  for (uint16_t r = 0; r < 4; r++)
  {
    display.setRotation(r);
    display.setPartialWindow(box_x, box_y, box_w, box_h);
    display.firstPage();
    do
    {
      display.fillRect(box_x, box_y, box_w, box_h, GxEPD_BLACK);
      //display.fillScreen(GxEPD_BLACK);
    }
    while (display.nextPage());
    delay(2000);
    display.firstPage();
    do
    {
      display.fillRect(box_x, box_y, box_w, box_h, GxEPD_WHITE);
    }
    while (display.nextPage());
    delay(1000);
  }
  //return;
  // show updates in the update box
  for (uint16_t r = 0; r < 4; r++)
  {
    display.setRotation(r);
    display.setPartialWindow(box_x, box_y, box_w, box_h);
    for (uint16_t i = 1; i <= 10; i += incr)
    {
      display.firstPage();
      do
      {
        display.fillRect(box_x, box_y, box_w, box_h, GxEPD_WHITE);
        display.setCursor(box_x, cursor_y);
        display.print(value * i, 2);
      }
      while (display.nextPage());
      delay(500);
    }
    delay(1000);
    display.firstPage();
    do
    {
      display.fillRect(box_x, box_y, box_w, box_h, GxEPD_WHITE);
    }
    while (display.nextPage());
    delay(1000);
  }
}


void drawBitmaps()
{
  display.setFullWindow();
#ifdef _GxBitmaps128x250_H_
  drawBitmaps128x250();
#endif
#ifdef _GxBitmaps128x296_H_
  drawBitmaps128x296();
#endif
#ifdef _GxBitmaps176x264_H_
  drawBitmaps176x264();
#endif
#ifdef _GxBitmaps400x300_H_
  drawBitmaps400x300();
#endif
#ifdef _GxBitmaps640x384_H_
  drawBitmaps640x384();
#endif
  // 3-color
#ifdef _GxBitmaps3c104x212_H_
  drawBitmaps3c104x212();
#endif
#ifdef _GxBitmaps3c128x296_H_
  drawBitmaps3c128x296();
#endif
#ifdef _GxBitmaps3c176x264_H_
  drawBitmaps3c176x264();
#endif
#ifdef _GxBitmaps3c400x300_H_
  drawBitmaps3c400x300();
#endif
  // show these after the specific bitmaps
#ifdef _GxBitmaps200x200_H_
  drawBitmaps200x200();
#endif
  // 3-color
#ifdef _GxBitmaps3c200x200_H_
  drawBitmaps3c200x200();
#endif
}

#ifdef _GxBitmaps200x200_H_
void drawBitmaps200x200()
{
#if defined(__AVR)
  const unsigned char* bitmaps[] =
  {
    logo200x200, first200x200 //, second200x200, third200x200, fourth200x200, fifth200x200, sixth200x200, senventh200x200, eighth200x200
  };
#elif defined(_BOARD_GENERIC_STM32F103C_H_)
  const unsigned char* bitmaps[] =
  {
    logo200x200, first200x200, second200x200, third200x200, fourth200x200, fifth200x200 //, sixth200x200, senventh200x200, eighth200x200
  };
#else
  const unsigned char* bitmaps[] =
  {
    logo200x200, first200x200, second200x200, third200x200, fourth200x200, fifth200x200, sixth200x200, senventh200x200, eighth200x200
  };
#endif
  if (display.epd2.panel == GxEPD2::GDEP015OC1)
  {
    bool m = display.mirror(true);
    for (uint16_t i = 0; i < sizeof(bitmaps) / sizeof(char*); i++)
    {
      display.firstPage();
      do
      {
        display.fillScreen(GxEPD_WHITE);
        display.drawInvertedBitmap(0, 0, bitmaps[i], display.epd2.WIDTH, display.epd2.HEIGHT, GxEPD_BLACK);
      }
      while (display.nextPage());
      delay(2000);
    }
    display.mirror(m);
  }
  //else
  {
    bool mirror_y = (display.epd2.panel != GxEPD2::GDE0213B1);
    display.clearScreen(); // use default for white
    int16_t x = (int16_t(display.epd2.WIDTH) - 200) / 2;
    int16_t y = (int16_t(display.epd2.HEIGHT) - 200) / 2;
    for (uint16_t i = 0; i < sizeof(bitmaps) / sizeof(char*); i++)
    {
      display.drawImage(bitmaps[i], x, y, 200, 200, false, mirror_y, true);
      delay(2000);
    }
  }
  bool mirror_y = (display.epd2.panel != GxEPD2::GDE0213B1);
  for (uint16_t i = 0; i < sizeof(bitmaps) / sizeof(char*); i++)
  {
    int16_t x = -60;
    int16_t y = -60;
    for (uint16_t j = 0; j < 10; j++)
    {
      display.writeScreenBuffer(); // use default for white
      display.writeImage(bitmaps[i], x, y, 200, 200, false, mirror_y, true);
      display.refresh(true);
      delay(2000);
      x += 40;
      y += 40;
      if ((x >= int16_t(display.epd2.WIDTH)) || (y >= int16_t(display.epd2.HEIGHT))) break;
    }
    if (!display.epd2.hasFastPartialUpdate) break; // comment out for full show
    break; // comment out for full show
  }
  display.writeScreenBuffer(); // use default for white
  display.writeImage(bitmaps[0], int16_t(0), 0, 200, 200, false, mirror_y, true);
  display.writeImage(bitmaps[0], int16_t(int16_t(display.epd2.WIDTH) - 200), int16_t(display.epd2.HEIGHT) - 200, 200, 200, false, mirror_y, true);
  display.refresh(true);
  delay(2000);
}
#endif

#ifdef _GxBitmaps128x250_H_
void drawBitmaps128x250()
{
#if !defined(__AVR)
  const unsigned char* bitmaps[] =
  {
    Bitmap128x250_1, logo128x250, first128x250, second128x250, third128x250
  };
#else
  const unsigned char* bitmaps[] =
  {
    Bitmap128x250_1, logo128x250, first128x250, second128x250, third128x250
  };
#endif
  if (display.epd2.panel == GxEPD2::GDE0213B1)
  {
    bool m = display.mirror(true);
    for (uint16_t i = 0; i < sizeof(bitmaps) / sizeof(char*); i++)
    {
      display.firstPage();
      do
      {
        display.fillScreen(GxEPD_WHITE);
        display.drawInvertedBitmap(0, 0, bitmaps[i], display.epd2.WIDTH, display.epd2.HEIGHT, GxEPD_BLACK);
      }
      while (display.nextPage());
      delay(2000);
    }
    display.mirror(m);
  }
}
#endif

#ifdef _GxBitmaps128x296_H_
void drawBitmaps128x296()
{
#if !defined(__AVR)
  const unsigned char* bitmaps[] =
  {
    Bitmap128x296_1, logo128x296, first128x296, second128x296, third128x296
  };
#else
  const unsigned char* bitmaps[] =
  {
    Bitmap128x296_1, logo128x296 //, first128x296, second128x296, third128x296
  };
#endif
  if (display.epd2.panel == GxEPD2::GDEH029A1)
  {
    bool m = display.mirror(true);
    for (uint16_t i = 0; i < sizeof(bitmaps) / sizeof(char*); i++)
    {
      display.firstPage();
      do
      {
        display.fillScreen(GxEPD_WHITE);
        display.drawInvertedBitmap(0, 0, bitmaps[i], display.epd2.WIDTH, display.epd2.HEIGHT, GxEPD_BLACK);
      }
      while (display.nextPage());
      delay(2000);
    }
    display.mirror(m);
  }
}
#endif

#ifdef _GxBitmaps176x264_H_
void drawBitmaps176x264()
{
  const unsigned char* bitmaps[] =
  {
    Bitmap176x264_1, Bitmap176x264_2
  };
  if (display.epd2.panel == GxEPD2::GDEW027W3)
  {
    for (uint16_t i = 0; i < sizeof(bitmaps) / sizeof(char*); i++)
    {
      display.firstPage();
      do
      {
        display.fillScreen(GxEPD_WHITE);
        display.drawInvertedBitmap(0, 0, bitmaps[i], display.epd2.WIDTH, display.epd2.HEIGHT, GxEPD_BLACK);
      }
      while (display.nextPage());
      delay(2000);
    }
  }
}
#endif

#ifdef _GxBitmaps400x300_H_
void drawBitmaps400x300()
{
#if !defined(__AVR)
  const unsigned char* bitmaps[] =
  {
    Bitmap400x300_1, Bitmap400x300_2
  };
#else
  const unsigned char* bitmaps[] = {}; // not enough code space
#endif
  if (display.epd2.panel == GxEPD2::GDEW042T2)
  {
    for (uint16_t i = 0; i < sizeof(bitmaps) / sizeof(char*); i++)
    {
      display.firstPage();
      do
      {
        display.fillScreen(GxEPD_WHITE);
        display.drawInvertedBitmap(0, 0, bitmaps[i], display.epd2.WIDTH, display.epd2.HEIGHT, GxEPD_BLACK);
      }
      while (display.nextPage());
      delay(2000);
    }
  }
}
#endif

#ifdef _GxBitmaps640x384_H_
void drawBitmaps640x384()
{
#if !defined(__AVR)
  const unsigned char* bitmaps[] =
  {
    Bitmap640x384_1, Bitmap640x384_2
  };
#else
  const unsigned char* bitmaps[] = {}; // not enough code space
#endif
  if (display.epd2.panel == GxEPD2::GDEW075T8)
  {
    for (uint16_t i = 0; i < sizeof(bitmaps) / sizeof(char*); i++)
    {
      display.firstPage();
      do
      {
        display.fillScreen(GxEPD_WHITE);
        display.drawInvertedBitmap(0, 0, bitmaps[i], display.epd2.WIDTH, display.epd2.HEIGHT, GxEPD_BLACK);
      }
      while (display.nextPage());
      delay(2000);
    }
  }
}
#endif

struct bitmap_pair
{
  const unsigned char* black;
  const unsigned char* red;
};

#ifdef _GxBitmaps3c200x200_H_
void drawBitmaps3c200x200()
{
  bitmap_pair bitmap_pairs[] =
  {
    //{Bitmap3c200x200_black, Bitmap3c200x200_red},
    {WS_Bitmap3c200x200_black, WS_Bitmap3c200x200_red}
  };
  if (display.epd2.panel == GxEPD2::GDEW0154Z04)
  {
    display.firstPage();
    do
    {
      display.fillScreen(GxEPD_WHITE);
      // Bitmap3c200x200_black has 2 bits per pixel
      // taken from Adafruit_GFX.cpp, modified
      int16_t byteWidth = (display.epd2.WIDTH + 7) / 8; // Bitmap scanline pad = whole byte
      uint8_t byte = 0;
      for (int16_t j = 0; j < display.epd2.HEIGHT; j++)
      {
        for (int16_t i = 0; i < display.epd2.WIDTH; i++)
        {
          if (i & 3) byte <<= 2;
          else
          {
#if defined(__AVR) || defined(ESP8266) || defined(ESP32)
            byte = pgm_read_byte(&Bitmap3c200x200_black[j * byteWidth * 2 + i / 4]);
#else
            byte = Bitmap3c200x200_black[j * byteWidth * 2 + i / 4];
#endif
          }
          if (!(byte & 0x80))
          {
            display.drawPixel(i, j, GxEPD_BLACK);
          }
        }
      }
      display.drawInvertedBitmap(0, 0, Bitmap3c200x200_red, display.epd2.WIDTH, display.epd2.HEIGHT, GxEPD_RED);
    }
    while (display.nextPage());
    delay(2000);
    for (uint16_t i = 0; i < sizeof(bitmap_pairs) / sizeof(bitmap_pair); i++)
    {
      display.firstPage();
      do
      {
        display.fillScreen(GxEPD_WHITE);
        display.drawInvertedBitmap(0, 0, bitmap_pairs[i].black, display.epd2.WIDTH, display.epd2.HEIGHT, GxEPD_BLACK);
        display.drawInvertedBitmap(0, 0, bitmap_pairs[i].red, display.epd2.WIDTH, display.epd2.HEIGHT, GxEPD_RED);
      }
      while (display.nextPage());
      delay(2000);
    }
  }
  if (display.epd2.hasColor)
  {
    display.clearScreen(); // use default for white
    int16_t x = (int16_t(display.epd2.WIDTH) - 200) / 2;
    int16_t y = (int16_t(display.epd2.HEIGHT) - 200) / 2;
    for (uint16_t i = 0; i < sizeof(bitmap_pairs) / sizeof(bitmap_pair); i++)
    {
      display.drawImage(bitmap_pairs[i].black, bitmap_pairs[i].red, x, y, 200, 200, false, false, true);
      delay(2000);
    }
    for (uint16_t i = 0; i < sizeof(bitmap_pairs) / sizeof(bitmap_pair); i++)
    {
      int16_t x = -60;
      int16_t y = -60;
      for (uint16_t j = 0; j < 10; j++)
      {
        display.writeScreenBuffer(); // use default for white
        display.writeImage(bitmap_pairs[i].black, bitmap_pairs[i].red, x, y, 200, 200, false, false, true);
        display.refresh();
        delay(2000);
        x += 40;
        y += 40;
        if ((x >= int16_t(display.epd2.WIDTH)) || (y >= int16_t(display.epd2.HEIGHT))) break;
      }
    }
    display.writeScreenBuffer(); // use default for white
    display.writeImage(bitmap_pairs[0].black, bitmap_pairs[0].red, 0, 0, 200, 200, false, false, true);
    display.writeImage(bitmap_pairs[0].black, bitmap_pairs[0].red, int16_t(display.epd2.WIDTH) - 200, int16_t(display.epd2.HEIGHT) - 200, 200, 200, false, false, true);
    display.refresh();
    delay(2000);
  }
}
#endif

#ifdef _GxBitmaps3c104x212_H_
void drawBitmaps3c104x212()
{
#if !defined(__AVR)
  bitmap_pair bitmap_pairs[] =
  {
    {Bitmap3c104x212_1_black, Bitmap3c104x212_1_red},
    {Bitmap3c104x212_2_black, Bitmap3c104x212_2_red},
    {WS_Bitmap3c104x212_black, WS_Bitmap3c104x212_red}
  };
#else
  bitmap_pair bitmap_pairs[] =
  {
    {Bitmap3c104x212_1_black, Bitmap3c104x212_1_red},
    //{Bitmap3c104x212_2_black, Bitmap3c104x212_2_red},
    {WS_Bitmap3c104x212_black, WS_Bitmap3c104x212_red}
  };
#endif
  if (display.epd2.panel == GxEPD2::GDEW0213Z16)
  {
    for (uint16_t i = 0; i < sizeof(bitmap_pairs) / sizeof(bitmap_pair); i++)
    {
      display.firstPage();
      do
      {
        display.fillScreen(GxEPD_WHITE);
        display.drawInvertedBitmap(0, 0, bitmap_pairs[i].black, display.epd2.WIDTH, display.epd2.HEIGHT, GxEPD_BLACK);
        if (bitmap_pairs[i].red == WS_Bitmap3c104x212_red)
        {
          display.drawInvertedBitmap(0, 0, bitmap_pairs[i].red, display.epd2.WIDTH, display.epd2.HEIGHT, GxEPD_RED);
        }
        else display.drawBitmap(0, 0, bitmap_pairs[i].red, display.epd2.WIDTH, display.epd2.HEIGHT, GxEPD_RED);
      }
      while (display.nextPage());
      delay(2000);
    }
  }
}
#endif

#ifdef _GxBitmaps3c128x296_H_
void drawBitmaps3c128x296()
{
#if !defined(__AVR)
  bitmap_pair bitmap_pairs[] =
  {
    {Bitmap3c128x296_1_black, Bitmap3c128x296_1_red},
    {Bitmap3c128x296_2_black, Bitmap3c128x296_2_red},
    {WS_Bitmap3c128x296_black, WS_Bitmap3c128x296_red}
  };
#else
  bitmap_pair bitmap_pairs[] =
  {
    //{Bitmap3c128x296_1_black, Bitmap3c128x296_1_red},
    //{Bitmap3c128x296_2_black, Bitmap3c128x296_2_red},
    {WS_Bitmap3c128x296_black, WS_Bitmap3c128x296_red}
  };
#endif
  if (display.epd2.panel == GxEPD2::GDEW029Z10)
  {
    for (uint16_t i = 0; i < sizeof(bitmap_pairs) / sizeof(bitmap_pair); i++)
    {
      display.firstPage();
      do
      {
        display.fillScreen(GxEPD_WHITE);
        display.drawInvertedBitmap(0, 0, bitmap_pairs[i].black, display.epd2.WIDTH, display.epd2.HEIGHT, GxEPD_BLACK);
        if (bitmap_pairs[i].red == WS_Bitmap3c128x296_red)
        {
          display.drawInvertedBitmap(0, 0, bitmap_pairs[i].red, display.epd2.WIDTH, display.epd2.HEIGHT, GxEPD_RED);
        }
        else display.drawBitmap(0, 0, bitmap_pairs[i].red, display.epd2.WIDTH, display.epd2.HEIGHT, GxEPD_RED);
      }
      while (display.nextPage());
      delay(2000);
    }
  }
}
#endif

#ifdef _GxBitmaps3c176x264_H_
void drawBitmaps3c176x264()
{
  bitmap_pair bitmap_pairs[] =
  {
    {Bitmap3c176x264_black, Bitmap3c176x264_red}
  };
  if (display.epd2.panel == GxEPD2::GDEW027C44)
  {
    for (uint16_t i = 0; i < sizeof(bitmap_pairs) / sizeof(bitmap_pair); i++)
    {
      display.firstPage();
      do
      {
        display.fillScreen(GxEPD_WHITE);
        display.drawBitmap(0, 0, bitmap_pairs[i].black, display.epd2.WIDTH, display.epd2.HEIGHT, GxEPD_BLACK);
        display.drawBitmap(0, 0, bitmap_pairs[i].red, display.epd2.WIDTH, display.epd2.HEIGHT, GxEPD_RED);
      }
      while (display.nextPage());
      delay(2000);
    }
  }
}
#endif

#ifdef _GxBitmaps3c400x300_H_
void drawBitmaps3c400x300()
{
#if !defined(__AVR)
  bitmap_pair bitmap_pairs[] =
  {
    {Bitmap3c400x300_1_black, Bitmap3c400x300_1_red},
    {Bitmap3c400x300_2_black, Bitmap3c400x300_2_red},
    {WS_Bitmap3c400x300_black, WS_Bitmap3c400x300_red}
  };
#else
  bitmap_pair bitmap_pairs[] = {}; // not enough code space
#endif
  if (display.epd2.panel == GxEPD2::GDEW042Z15)
  {
    for (uint16_t i = 0; i < sizeof(bitmap_pairs) / sizeof(bitmap_pair); i++)
    {
      display.firstPage();
      do
      {
        display.fillScreen(GxEPD_WHITE);
        display.drawInvertedBitmap(0, 0, bitmap_pairs[i].black, display.epd2.WIDTH, display.epd2.HEIGHT, GxEPD_BLACK);
        display.drawInvertedBitmap(0, 0, bitmap_pairs[i].red, display.epd2.WIDTH, display.epd2.HEIGHT, GxEPD_RED);
      }
      while (display.nextPage());
      delay(2000);
    }
  }
}
#endif
