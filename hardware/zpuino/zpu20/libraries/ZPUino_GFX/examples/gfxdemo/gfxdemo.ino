#include <Adafruit_GFX.h>
#include <ZPUino_GFX.h>
#include <PLL.h>

// Assign human-readable names to some common 16-bit color values:
#define	BLACK   0x0000
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

#define min(x,y) ((x)>(y) ? (y):(x))

ZPUino_GFX gfx;

void setup(void) {
    Serial.begin(115200);
    Serial.println(F("TFT LCD test"));

    // Comment out your modeline. See ZPUino_GFX.h for other modes.

    gfx.begin( &modeline_640x480_60 );
    // gfx.begin( &modeline_640x512_60 );
    // gfx.begin( &modeline_320x240_60 );
}

void test()
{
  Serial.println(F("Benchmark                Time (microseconds)"));

  Serial.print(F("Screen fill              "));
  Serial.println(testFillScreen());
  delay(500);

  Serial.print(F("Text                     "));
  Serial.println(testText());
  delay(3000);

  Serial.print(F("Lines                    "));
  Serial.println(testLines(CYAN));
  delay(500);

  Serial.print(F("Horiz/Vert Lines         "));
  Serial.println(testFastLines(RED, BLUE));
  delay(500);

  Serial.print(F("Rectangles (outline)     "));
  Serial.println(testRects(GREEN));
  delay(500);

  Serial.print(F("Rectangles (filled)      "));
  Serial.println(testFilledRects(YELLOW, MAGENTA));
  delay(500);

  Serial.print(F("Circles (filled)         "));
  Serial.println(testFilledCircles(10, MAGENTA));

  Serial.print(F("Circles (outline)        "));
  Serial.println(testCircles(10, WHITE));
  delay(500);

  Serial.print(F("Triangles (outline)      "));
  Serial.println(testTriangles());
  delay(500);

  Serial.print(F("Triangles (filled)       "));
  Serial.println(testFilledTriangles());
  delay(500);

  Serial.print(F("Rounded rects (outline)  "));
  Serial.println(testRoundRects());
  delay(500);

  Serial.print(F("Rounded rects (filled)   "));
  Serial.println(testFilledRoundRects());
  delay(500);

  Serial.println(F("Done!"));
}

void loop(void) {
    test();
    delay(2000);
}

unsigned long testFillScreen() {
  unsigned long start = micros();
  gfx.fillScreen(BLACK);
  gfx.fillScreen(RED);
  gfx.fillScreen(GREEN);
  gfx.fillScreen(BLUE);
  gfx.fillScreen(BLACK);
  return micros() - start;
}

unsigned long testText() {
  gfx.fillScreen(BLACK);
  unsigned long start = micros();
  gfx.setCursor(0, 0);
  gfx.setTextColor(WHITE);  gfx.setTextSize(1);
  gfx.println("Hello World!");
  gfx.setTextColor(YELLOW); gfx.setTextSize(2);
  gfx.println(1234.56);
  gfx.setTextColor(RED);    gfx.setTextSize(3);
  gfx.println(0xDEADBEEF, HEX);
  gfx.println();
  gfx.setTextColor(GREEN);
  gfx.setTextSize(5);
  gfx.println("Groop");
  gfx.setTextSize(2);
  gfx.println("I implore thee,");
  gfx.setTextSize(1);
  gfx.println("my foonting turlingdromes.");
  gfx.println("And hooptiously drangle me");
  gfx.println("with crinkly bindlewurdles,");
  gfx.println("Or I will rend thee");
  gfx.println("in the gobberwarts");
  gfx.println("with my blurglecruncheon,");
  gfx.println("see if I don't!");
  return micros() - start;
}

unsigned long testLines(uint16_t color) {
  unsigned long start, t;
  int           x1, y1, x2, y2,
                w = gfx.width(),
                h = gfx.height();

  gfx.fillScreen(BLACK);

  x1 = y1 = 0;
  y2    = h - 1;
  start = micros();
  for(x2=0; x2<w; x2+=6) gfx.drawLine(x1, y1, x2, y2, color);
  x2    = w - 1;
  for(y2=0; y2<h; y2+=6) gfx.drawLine(x1, y1, x2, y2, color);
  t     = micros() - start; // fillScreen doesn't count against timing

  gfx.fillScreen(BLACK);

  x1    = w - 1;
  y1    = 0;
  y2    = h - 1;
  start = micros();
  for(x2=0; x2<w; x2+=6) gfx.drawLine(x1, y1, x2, y2, color);
  x2    = 0;
  for(y2=0; y2<h; y2+=6) gfx.drawLine(x1, y1, x2, y2, color);
  t    += micros() - start;

  gfx.fillScreen(BLACK);

  x1    = 0;
  y1    = h - 1;
  y2    = 0;
  start = micros();
  for(x2=0; x2<w; x2+=6) gfx.drawLine(x1, y1, x2, y2, color);
  x2    = w - 1;
  for(y2=0; y2<h; y2+=6) gfx.drawLine(x1, y1, x2, y2, color);
  t    += micros() - start;

  gfx.fillScreen(BLACK);

  x1    = w - 1;
  y1    = h - 1;
  y2    = 0;
  start = micros();
  for(x2=0; x2<w; x2+=6) gfx.drawLine(x1, y1, x2, y2, color);
  x2    = 0;
  for(y2=0; y2<h; y2+=6) gfx.drawLine(x1, y1, x2, y2, color);

  return micros() - start;
}

unsigned long testFastLines(uint16_t color1, uint16_t color2) {
  unsigned long start;
  int           x, y, w = gfx.width(), h = gfx.height();

  gfx.fillScreen(BLACK);
  start = micros();
  for(y=0; y<h; y+=5) gfx.drawFastHLine(0, y, w, color1);
  for(x=0; x<w; x+=5) gfx.drawFastVLine(x, 0, h, color2);

  return micros() - start;
}

unsigned long testRects(uint16_t color) {
  unsigned long start;
  int           n, i, i2,
                cx = gfx.width()  / 2,
                cy = gfx.height() / 2;

  gfx.fillScreen(BLACK);
  n     = min(gfx.width(), gfx.height());
  start = micros();
  for(i=2; i<n; i+=6) {
    i2 = i / 2;
    gfx.drawRect(cx-i2, cy-i2, i, i, color);
  }

  return micros() - start;
}

unsigned long testFilledRects(uint16_t color1, uint16_t color2) {
  unsigned long start, t = 0;
  int           n, i, i2,
                cx = gfx.width()  / 2 - 1,
                cy = gfx.height() / 2 - 1;

  gfx.fillScreen(BLACK);
  n = min(gfx.width(), gfx.height());
  for(i=n; i>0; i-=6) {
    i2    = i / 2;
    start = micros();
    gfx.fillRect(cx-i2, cy-i2, i, i, color1);
    t    += micros() - start;
    // Outlines are not included in timing results
    gfx.drawRect(cx-i2, cy-i2, i, i, color2);
  }

  return t;
}

unsigned long testFilledCircles(uint8_t radius, uint16_t color) {
  unsigned long start;
  int x, y, w = gfx.width(), h = gfx.height(), r2 = radius * 2;

  gfx.fillScreen(BLACK);
  start = micros();
  for(x=radius; x<w; x+=r2) {
    for(y=radius; y<h; y+=r2) {
      gfx.fillCircle(x, y, radius, color);
    }
  }

  return micros() - start;
}

unsigned long testCircles(uint8_t radius, uint16_t color) {
  unsigned long start;
  int           x, y, r2 = radius * 2,
                w = gfx.width()  + radius,
                h = gfx.height() + radius;

  // Screen is not cleared for this one -- this is
  // intentional and does not affect the reported time.
  start = micros();
  for(x=0; x<w; x+=r2) {
    for(y=0; y<h; y+=r2) {
      gfx.drawCircle(x, y, radius, color);
    }
  }

  return micros() - start;
}

unsigned long testTriangles() {
  unsigned long start;
  int           n, i, cx = gfx.width()  / 2 - 1,
                      cy = gfx.height() / 2 - 1;

  gfx.fillScreen(BLACK);
  n     = min(cx, cy);
  start = micros();
  for(i=0; i<n; i+=5) {
    gfx.drawTriangle(
      cx    , cy - i, // peak
      cx - i, cy + i, // bottom left
      cx + i, cy + i, // bottom right
      gfx.buildColor(0, 0, i));
  }

  return micros() - start;
}

unsigned long testFilledTriangles() {
  unsigned long start, t = 0;
  int           i, cx = gfx.width()  / 2 - 1,
                   cy = gfx.height() / 2 - 1;

  gfx.fillScreen(BLACK);
  start = micros();
  for(i=min(cx,cy); i>10; i-=5) {
    start = micros();
    gfx.fillTriangle(cx, cy - i, cx - i, cy + i, cx + i, cy + i,
      gfx.buildColor(0, i, i));
    t += micros() - start;
    gfx.drawTriangle(cx, cy - i, cx - i, cy + i, cx + i, cy + i,
      gfx.buildColor(i, i, 0));
  }

  return t;
}

unsigned long testRoundRects() {
  unsigned long start;
  int           w, i, i2,
                cx = gfx.width()  / 2 - 1,
                cy = gfx.height() / 2 - 1;

  gfx.fillScreen(BLACK);
  w     = min(gfx.width(), gfx.height());
  start = micros();
  for(i=0; i<w; i+=6) {
    i2 = i / 2;
    gfx.drawRoundRect(cx-i2, cy-i2, i, i, i/8, gfx.buildColor(i, 0, 0));
  }

  return micros() - start;
}

unsigned long testFilledRoundRects() {
  unsigned long start;
  int           i, i2,
                cx = gfx.width()  / 2 - 1,
                cy = gfx.height() / 2 - 1;

  gfx.fillScreen(BLACK);
  start = micros();
  for(i=min(gfx.width(), gfx.height()); i>20; i-=6) {
    i2 = i / 2;
    gfx.fillRoundRect(cx-i2, cy-i2, i, i, i/8, gfx.buildColor(0, i, 0));
  }

  return micros() - start;
}
