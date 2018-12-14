# PxEPD2
## Experimental Particle Display Library for SPI E-Paper Displays

## only use was to analyze issues with Particle Desktop IDE

- With full Graphics and Text support using Adafruit_GFX  (Adafruit_GFX_RK Version 1.3.5)

- For SPI e-paper displays from Dalian Good Display 
- and SPI e-paper boards from Waveshare

## Flat Source Structure Variant of GxEPD2_PP ( Arduino GxEPD2)
- works with Particle Build WEB-IDE and Particle CLI command line tool
- only use was to analyze issues with Particle Desktop IDE
- PxEPD2_Example also works with Particle Desktop IDE

### important note :
 - these displays are for 3.3V supply and 3.3V data lines.
 - never connect data lines directly to 5V data pins.

### Paged Drawing, Picture Loop
 - This library uses paged drawing to limit RAM use and cope with missing single pixel update support
 - buffer size can be selected in the application by template parameter page_height, see GxEPD2_Example
 - Paged drawing is implemented as picture loop, like in U8G2 (Oliver Kraus)
 - see https://github.com/olikraus/u8glib/wiki/tpictureloop
 - Paged drawing is also available using drawPaged() and drawCallback(), like in GxEPD
- ` // GxEPD style paged drawing; drawCallback() is called as many times as needed `
- ` void drawPaged(void (*drawCallback)(const void*), const void* pv) `
- paged drawing is done using Adafruit_GFX methods inside picture loop or drawCallback

### Full Screen Buffer Support
 - full screen buffer is selected by setting template parameter page_height to display height
 - drawing to full screen buffer is done using Adafruit_GFX methods without picture loop or drawCallback
 - and then calling method display()

### Low Level Bitmap Drawing Support
 - bitmap drawing support to the controller memory and screen is available:
 - either through the template class instance methods that forward calls to the base display class
 - or directy using an instance of a base display class and calling its methods directly

### Supporting Arduino Forum Topics:

- Waveshare e-paper displays with SPI: http://forum.arduino.cc/index.php?topic=487007.0
- Good Dispay ePaper for Arduino : https://forum.arduino.cc/index.php?topic=436411.0

### Version 1.0.6
- preliminary version
- based on GxEPD2 Version 1.1.0
- example PxEPD2_Example has a project local library to analyze a Desktop IDE issue
