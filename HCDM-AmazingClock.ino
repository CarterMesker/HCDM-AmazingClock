#include <MeggyJrSimple.h>    // Required code, line 1 of 2.

  int seconds = 0;
  int minutes = 0;
  int hours = 0;
  unsigned long time;
  unsigned long previous;


void setup()                    // run once, when the sketch starts
{
  MeggyJrSimpleSetup();      // Required code, line 2 of 2.

}

void loop() {
  
  time = millis(); // time takes the current value of millis

  if(time - previous > 1000) { // if the differcence between the current measuerement of millis and the prevevious measurement of millis is greater than 1000 then advance seconds and previous will take the current value of time
   if(seconds > 59) {
     seconds = 0;
     minutes ++; 
   }
   else seconds ++;
  }
    
  drawMinutes;
  DisplaySlate();

}

void drawMinutes() {
  int ones = minutes%10;
  switch (ones) {
    case 1:
      DrawOne(4,1);
      break;
    case 2:
      DrawTwo(4,1);
      break; 
    case 3:
      DrawThree(4,1);
      break; 
    case 4:
      DrawFour(4,1);
      break; 
    case 5:
      DrawFive(4,1);
      break; 
    case 6:
      DrawSix(4,1);
      break; 
    case 7:
      DrawSeven(4,1);
      break; 
    case 8:
      DrawEight(4,1);
      break; 
    case 9:
      DrawNine(4,1);
      break; 
  }
}

void drawHours() {
  int tens = minutes/10;
  switch (tens) {
    case 1:
      DrawOne(0,1);
      break;
    case 2:
      DrawTwo(0,1);
      break; 
    case 3:
      DrawThree(0,1);
      break; 
    case 4:
      DrawFour(0,1);
      break; 
    case 5:
      DrawFive(0,1);
      break; 
    case 6:
      DrawSix(0,1);
      break; 
  }
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

void DrawNine(int offset, int color) {
  DrawPx(0+offset,4,color);
  DrawPx(1+offset,4,color);
  DrawPx(2+offset,4,color);
  DrawPx(0+offset,3,color);
  DrawPx(2+offset,3,color);
  DrawPx(0+offset,2,color);
  DrawPx(1+offset,2,color);
  DrawPx(2+offset,2,color);
  DrawPx(2+offset,1,color);
  DrawPx(0+offset,0,color);
  DrawPx(1+offset,0,color);
  DrawPx(2+offset,0,color);
}


