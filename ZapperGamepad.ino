#include "Button.h"
#include "Arrow.h"
#include "Circle.h"
#include "Rectangle.h"

#include <TVout.h>
#include "font6x8.h"
#include "video_gen.h"

#define TRIGGER_PIN 3
#define DETECT_PIN 2
#define DELAY_TIMEOUT 50

TVout TV;

const int triggerPin = 3;

volatile int triggerState = HIGH;
volatile int detectState = LOW;
volatile int vblank = 0;

Circle buttonA('A',-1,-1,0);
Circle buttonB('B', 1, -1, 0);
Circle buttonC('C',-1, 1, 0);
Circle buttonD('D', 1, 1, 0);

Arrow upArrow(0, -1, false);
Arrow downArrow(0, 1, false);
Arrow leftArrow(-1, 0, false);
Arrow rightArrow(1, 0, false);

Rectangle buttonMid(0);

void setup() 
{
  attachInterrupt(digitalPinToInterrupt(TRIGGER_PIN), triggerPull, FALLING);
  attachInterrupt(digitalPinToInterrupt(DETECT_PIN), lightDetect, RISING);
  // put your setup code here, to run once:
  TV.begin(_NTSC);
  TV.clear_screen();
  TV.select_font(font6x8);

  TV.set_vbi_hook(vbiFlag);

  pinMode(triggerPin, INPUT);

  //Reference lines for layout changes
  /*
  MainTV.draw_line(64, 0, 64, 96, 2);
  MainTV.draw_line(0, 49, 128, 49, 2);
  MainTV.draw_line(24, 49, 64, 9, 2);
  MainTV.draw_line(24, 49, 64, 89, 2);
  MainTV.draw_line(64, 89, 104, 49, 2);
  MainTV.draw_line(64, 9, 104, 49, 2);
  */
}
void loop() 
{
  // put your main code here, to run repeatedly:
  triggerState = digitalRead(triggerPin);
  
  buttonA.draw(true);
  buttonB.draw(false);
  buttonC.draw(false);
  buttonD.draw(true);

  upArrow.draw(true);
  downArrow.draw(false);
  leftArrow.draw(false);
  rightArrow.draw(true);

  buttonMid.draw(detectState);

  while (triggerState == LOW);
  
  wait_for_vblank();

  TV.fill(WHITE);
  wait_for_vblank();
  wait_for_vblank();

  triggerState = LOW;
  TV.clear_screen();
}

void vbiFlag()
{
  vblank = 1;
}

inline void wait_for_vblank()
{
  while (!vblank);
  vblank = 0;
}

void triggerPull()
{
  triggerState = HIGH;
}

void lightDetect()
{
  detectState = !detectState;
}

inline void resetState()
{
  triggerState = LOW;
  detectState = LOW;
}
