#include <MeggyJrSimple.h>    // Required code, line 1 of 2.

void setup()                    // run once, when the sketch starts
{
  MeggyJrSimpleSetup();      // Required code, line 2 of 2.
}

void loop() {
  
  ClearSlate();
  DrawSeven(0,1);
  DisplaySlate();
  delay(1000);

}

void DrawOne(int offset, int color) {
  DrawPx(1+offset,4,color);
  DrawPx(0+offset,3,color);
  DrawPx(1+offset,3,color);
  DrawPx(1+offset,2,color);
  DrawPx(1+offset,1,color);
  DrawPx(0+offset,0,color);
  DrawPx(1+offset,0,color);
  DrawPx(2+offset,0,color);
}

void DrawTwo(int offset, int color) {
  DrawPx(0+offset,4,color);
  DrawPx(1+offset,4,color);
  DrawPx(2+offset,4,color);
  DrawPx(2+offset,3,color);
  DrawPx(0+offset,2,color);
  DrawPx(1+offset,2,color);
  DrawPx(2+offset,2,color);
  DrawPx(0+offset,1,color);
  DrawPx(0+offset,0,color);
  DrawPx(1+offset,0,color);
  DrawPx(2+offset,0,color);
}

void DrawThree(int offset, int color) {
  DrawPx(0+offset,4,color);
  DrawPx(1+offset,4,color);
  DrawPx(2+offset,4,color);
  DrawPx(2+offset,3,color);
  DrawPx(0+offset,2,color);
  DrawPx(1+offset,2,color);
  DrawPx(2+offset,2,color);
  DrawPx(2+offset,1,color);
  DrawPx(0+offset,0,color);
  DrawPx(1+offset,0,color);
  DrawPx(2+offset,0,color);
}

void DrawFour(int offset, int color) {
  DrawPx(0+offset,4,color);
  DrawPx(2+offset,4,color);
  DrawPx(0+offset,3,color);
  DrawPx(2+offset,3,color);
  DrawPx(0+offset,2,color);
  DrawPx(1+offset,2,color);
  DrawPx(2+offset,2,color);
  DrawPx(2+offset,1,color);
  DrawPx(2+offset,0,color);
}

void DrawFive(int offset, int color) {
  DrawPx(0+offset,4,color);
  DrawPx(1+offset,4,color);
  DrawPx(2+offset,4,color);
  DrawPx(0+offset,3,color);
  DrawPx(0+offset,2,color);
  DrawPx(1+offset,2,color);
  DrawPx(2+offset,2,color);
  DrawPx(2+offset,1,color);
  DrawPx(0+offset,0,color);
  DrawPx(1+offset,0,color);
  DrawPx(2+offset,0,color);
}

void DrawSix(int offset, int color) {
  DrawPx(0+offset,4,color);
  DrawPx(1+offset,4,color);
  DrawPx(2+offset,4,color);
  DrawPx(0+offset,3,color);
  DrawPx(0+offset,2,color);
  DrawPx(1+offset,2,color);
  DrawPx(2+offset,2,color);
  DrawPx(2+offset,1,color);
  DrawPx(0+offset,1,color);
  DrawPx(0+offset,0,color);
  DrawPx(1+offset,0,color);
  DrawPx(2+offset,0,color);
}

void DrawSeven(int offset, int color) {
  DrawPx(0+offset,4,color);
  DrawPx(1+offset,4,color);
  DrawPx(2+offset,4,color);
  DrawPx(2+offset,3,color);
  DrawPx(2+offset,2,color);
  DrawPx(2+offset,1,color);
  DrawPx(2+offset,0,color);
}

void DrawEight(int offset, int color) {
  DrawPx(0+offset,4,color);
  DrawPx(1+offset,4,color);
  DrawPx(2+offset,4,color);
  DrawPx(0+offset,3,color);
  DrawPx(2+offset,3,color);
  DrawPx(0+offset,2,color);
  DrawPx(1+offset,2,color);
  DrawPx(2+offset,2,color);
  DrawPx(2+offset,1,color);
  DrawPx(0+offset,1,color);
  DrawPx(0+offset,0,color);
  DrawPx(1+offset,0,color);
  DrawPx(2+offset,0,color);
}



