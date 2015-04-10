#ifndef _ADAFRUIT_GFX_H
#define _ADAFRUIT_GFX_H

#if ARDUINO >= 100
 #include "Arduino.h"
 #include "Print.h"
#else
 #include "WProgram.h"
#endif

#define swap(a, b) { int t = a; a = b; b = t; }

template<typename PixelType>
class Adafruit_GFX_core : public Print {

 public:

  Adafruit_GFX_core(); // Constructor
  void begin(int w, int h);

  // This MUST be defined by the subclass:
  virtual void drawPixel(int x, int y, PixelType color) = 0;

  // These MAY be overridden by the subclass to provide device-specific
  // optimized code.  Otherwise 'generic' versions are used.
  virtual void
    drawLine(int x0, int y0, int x1, int y1, PixelType color),
    drawFastVLine(int x, int y, int h, PixelType color),
    drawFastHLine(int x, int y, int w, PixelType color),
    drawRect(int x, int y, int w, int h, PixelType color),
    fillRect(int x, int y, int w, int h, PixelType color),
    fillScreen(PixelType color),
    invertDisplay(boolean i);

  // These exist only with Adafruit_GFX (no subclass overrides)
  void
    drawCircle(int x0, int y0, int r, PixelType color),
    drawCircleHelper(int x0, int y0, int r, uint8_t cornername,
      PixelType color),
    fillCircle(int x0, int y0, int r, PixelType color),
    fillCircleHelper(int x0, int y0, int r, uint8_t cornername,
      int delta, PixelType color),
    drawTriangle(int x0, int y0, int x1, int y1,
      int x2, int y2, PixelType color),
    fillTriangle(int x0, int y0, int x1, int y1,
      int x2, int y2, PixelType color),
    drawRoundRect(int x0, int y0, int w, int h,
      int radius, PixelType color),
    fillRoundRect(int x0, int y0, int w, int h,
      int radius, PixelType color),
    drawBitmap(int x, int y, const uint8_t *bitmap,
      int w, int h, PixelType color),
    drawChar(int x, int y, unsigned char c, PixelType color,
      PixelType bg, uint8_t size),
    setCursor(int x, int y),
    setTextColor(PixelType c),
    setTextColor(PixelType c, PixelType bg),
    setTextSize(uint8_t s),
    setTextWrap(boolean w),
    setRotation(uint8_t r);

#if ARDUINO >= 100
  virtual size_t write(uint8_t);
#else
  virtual void   write(uint8_t);
#endif

  // Return the size of the display (per current rotation)
  int width(void) const {
      return _width;
  }
 
  int height(void) const {
      return _height;
  }

  uint8_t getRotation(void);

 protected:
  int
    WIDTH, HEIGHT;   // This is the 'raw' display w/h - never changes
  int
    _width, _height, // Display w/h as modified by current rotation
    cursor_x, cursor_y;
  unsigned int
    textcolor, textbgcolor;
  uint8_t
    textsize,
    rotation;
  boolean
    wrap; // If set, 'wrap' text at right edge of display
};

typedef Adafruit_GFX_core<uint16_t> Adafruit_GFX;
typedef Adafruit_GFX_core<uint32_t> Adafruit_GFX_32;

#endif // _ADAFRUIT_GFX_H
