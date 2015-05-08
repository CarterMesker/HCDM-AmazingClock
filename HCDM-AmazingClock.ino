#include <MeggyJrSimple.h>    // Required code, line 1 of 2.

  int seconds = 0;
  int minutes = 0;
  int hours = 0;
  unsigned long time;
  unsigned long previous;


void setup()                    // run once, when the sketch starts
{
  MeggyJrSimpleSetup();      // Required code, line 2 of 2.
  Serial.begin(9600);
}

void loop() {
  
  CheckButtonsPress();
  if(Button_A) {
    minutes++;
    Tone_Start(18182, 50);
  }
  
  if(Button_B) {
    hours++;
    Tone_Start(ToneB3, 50);
  }
  
  time = millis(); // time takes the current value of millis

  if(time - previous > 1000) { // if the difference between the current measuerement of millis and the prevevious measurement of millis is greater than 1000 then advance seconds and previous will take the current value of time
    if (seconds < 59)
    {
      seconds++;
    }
    else 
    {
     seconds = 0;
     minutes++;
    }
    if (minutes > 59) 
    {
      minutes = 0;
      hours++;
    }
   previous = time; 
  }
  Serial.print("Seconds = ");
  Serial.println(seconds);
  Serial.print("Minutes = ");
  Serial.println(minutes);
  if(hours <= 12) {
    drawMinutes(1);
  }
  if(hours > 12) {
    drawMinutes(5);
  }
  if(hours <= 12) {
    drawHours(1);
  }
  if(hours > 12) {
    drawHours(5);
  }
  DisplaySlate();
  ClearSlate();

}

void drawMinutes(int color) 
{
  int ones = minutes%10;
  int tens = minutes/10;
  switch (ones) 
  {
    case 1:
      DrawOne(4,color);
      break;
    case 2:
      DrawTwo(4,color);
      break; 
    case 3:
      DrawThree(4,color);
      break; 
    case 4:
      DrawFour(4,color);
      break; 
    case 5:
      DrawFive(4,color);
      break; 
    case 6:
      DrawSix(4,color);
      break; 
    case 7:
      DrawSeven(4,color);
      break; 
    case 8:
      DrawEight(4,color);
      break; 
    case 9:
      DrawNine(4,color);
      break; 
    case 0:
      DrawZero(4,color);
      break;
  }
  switch (tens) 
  {
    case 1:
      DrawOne(0,color);
      break;
    case 2:
      DrawTwo(0,color);
      break; 
    case 3:
      DrawThree(0,color);
      break; 
    case 4:
      DrawFour(0,color);
      break; 
    case 5:
      DrawFive(0,color);
      break; 
    case 0:
      DrawZero(0,color);
      break;
  }
}


void DrawZero(int offset, int color) {
  DrawPx(0+offset,4,color);
  DrawPx(1+offset,4,color);
  DrawPx(2+offset,4,color);
  DrawPx(0+offset,3,color);
  DrawPx(2+offset,3,color);
  DrawPx(0+offset,2,color);
  DrawPx(2+offset,2,color);
  DrawPx(2+offset,1,color);
  DrawPx(0+offset,1,color);
  DrawPx(0+offset,0,color);
  DrawPx(1+offset,0,color);
  DrawPx(2+offset,0,color);
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

void DrawHours(int i, int color) {
  for(int i=1; i <= hours; i++) {
    DrawPx(i,6,color)
  }
}

