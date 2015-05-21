#include <MeggyJrSimple.h>    // Required code, line 1 of 2.

  int seconds = 0; //variable for seconds
  int minutes = 0; //variable for minutes
  int hours = 0; //variable for hours
  unsigned long time; //variable for unsigned time current
  unsigned long previous; //variable for unsigned time previous
  boolean am = true; //variale for am/pm
  boolean secondsLeft = false; //variable for seconds left
  
  


void setup()                    // run once, when the sketch starts
{
  MeggyJrSimpleSetup();      // Required code, line 2 of 2.
  Serial.begin(9600);
}

void loop() {
  
  CheckButtonsPress(); //check buttons press
  if(Button_A) { //if button A is pressed add one minute
    minutes++;
    Tone_Start(18182, 50);
  }
  
  if(Button_B) { //if button B is pressed add one hour
    hours++;
    Tone_Start(ToneB3, 50);
  }
  
  time = millis(); // time takes the current value of millis

  if(time - previous > 1000) { // if the difference between the current measuerement of millis and the prevevious measurement of millis is greater than 1000 then advance seconds and previous will take the current value of time
    if (seconds < 59)
    {
      seconds++;
      secondsLeft=!secondsLeft;
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
    if (hours > 12)
    {
      am =! am;
      hours = 1;
    }
   previous = time; 
  }
  if(hours <= 12) { //if hours are greater then 12 change am/pm
    if(am) {
      drawHours(2); //display hours
      drawMinutes(1); //display minutes
    }
    else {
      drawHours(6); //display hours
      drawMinutes(5); //display minutes
    }
  }
  if(secondsLeft)
    DrawSeconds(0,4); //display seconds left
  else
    DrawSeconds(7,4); //display seconds right
  DisplaySlate();
  if(hours == 1 && minutes == 0 && seconds == 0) //on the change of the hour play hour change music
    hourMusic();
  ClearSlate();

}

void drawMinutes(int color) //draw minutes
{
  int ones = minutes%10; //equation for determining current value of minutes ones value
  int tens = minutes/10; //equation for determining current value of minutes tens value
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


void DrawZero(int offset, int color) { //draw the number 0
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

void DrawOne(int offset, int color) { //draw the number 1
  DrawPx(1+offset,4,color);
  DrawPx(0+offset,3,color);
  DrawPx(1+offset,3,color);
  DrawPx(1+offset,2,color);
  DrawPx(1+offset,1,color);
  DrawPx(0+offset,0,color);
  DrawPx(1+offset,0,color);
  DrawPx(2+offset,0,color);
}

void DrawTwo(int offset, int color) { //draw the number 2
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

void DrawThree(int offset, int color) { //draw the number 3
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

void DrawFour(int offset, int color) { //draw the number 4
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

void DrawFive(int offset, int color) { //draw the number 5
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

void DrawSix(int offset, int color) { //draw the number 6
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

void DrawSeven(int offset, int color) { //draw the number 7
  DrawPx(0+offset,4,color);
  DrawPx(1+offset,4,color);
  DrawPx(2+offset,4,color);
  DrawPx(2+offset,3,color);
  DrawPx(2+offset,2,color);
  DrawPx(2+offset,1,color);
  DrawPx(2+offset,0,color);
}

void DrawEight(int offset, int color) { //draw the number 8
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

void DrawNine(int offset, int color) { //draw the number 9
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

void drawHours(int color) { //draw hours
  if(hours < 7) { //if hours is 1-6 draw hours on hours line 1
    for(int i=1; i <= hours; i++) {
      DrawPx(i,7,color);
    }
  }
  else { //if hours is 6-12 draw hours on hours line 1 and 2
    for(int i=1; i < 7; i++) {
      DrawPx(i,7,color);
    }
    for(int i=1; i <= hours-6; i++) {
      DrawPx(i,6,color);
    }
  }
}

void hourMusic() { //music for the change of the hour
  Tone_Start(ToneF3, 750);
  delay(750);
  Tone_Start(ToneA3, 750);
  delay(750);
  Tone_Start(ToneG3, 750);
  delay(750);
  Tone_Start(ToneC3, 750);
  delay(1000);
  Tone_Start(ToneF3, 750);
  delay(750);
  Tone_Start(ToneG3, 750);
  delay(750);
  Tone_Start(ToneA3, 750);
  delay(750);
  Tone_Start(ToneF3, 750);
  delay(1000);
  Tone_Start(ToneA3, 750);
  delay(750);
  Tone_Start(ToneF3, 750);
  delay(750);
  Tone_Start(ToneG3, 750);
  delay(750);
  Tone_Start(ToneC3, 750);
  delay(1000);
  Tone_Start(ToneC3, 750);
  delay(750);
  Tone_Start(ToneG3, 750);
  delay(750);
  Tone_Start(ToneA3, 750);
  delay(750);
  Tone_Start(ToneF3, 750);
}

void DrawSeconds(int offset, int color) { //draw seconds counter
  DrawPx(0+offset,6,color);
  DrawPx(0+offset,7,color);
}

