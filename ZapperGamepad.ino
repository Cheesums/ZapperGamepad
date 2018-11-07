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

volatile int triggerState = LOW;
volatile int detectState = LOW;
volatile int vblank = 0;
volatile int detectInt = 0;

int i = 0;

Circle buttonA('A',-1,-1,0);
Circle buttonB('B', 1, -1, 0);
Circle buttonC('C',-1, 1, 0);
Circle buttonD('D', 1, 1, 0);

Arrow buttonUp(0, -1, false);
Arrow buttonDown(0, 1, false);
Arrow buttonLeft(-1, 0, false);
Arrow buttonRight(1, 0, false);

Rectangle buttonMid(0);

void setup() 
{
  attachInterrupt(digitalPinToInterrupt(TRIGGER_PIN), triggerHandle, FALLING);
  attachInterrupt(digitalPinToInterrupt(DETECT_PIN), detectHandle, RISING);
  // put your setup code here, to run once:
  TV.begin(_NTSC);
  TV.clear_screen();
  TV.select_font(font6x8);

  TV.set_vbi_hook(vbiFlag);

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
  //triggerState = digitalRead(triggerPin);

  
  buttonA.draw(false);
  buttonB.draw(false);
  buttonC.draw(false);
  buttonD.draw(false);

  buttonUp.draw(false);
  buttonDown.draw(false);
  buttonLeft.draw(false);
  buttonRight.draw(false);

  buttonMid.draw(detectState);

  resetState();
  TV.print(detectInt);
  while (triggerState == LOW);
  attachInterrupt(digitalPinToInterrupt(DETECT_PIN), detectHandle, RISING);

  i = i +1;

}

//TV utlility functions

void vbiFlag()
{
  vblank = 1;
}

inline void wait_for_vblank()
{
  while (!vblank);
  vblank = 0;
}

void triggerHandle()
{
  triggerState = HIGH;
}

void detectHandle()
{
  detectState = !detectState;
  detectInt = detectInt + 1;
  detachInterrupt(digitalPinToInterrupt(DETECT_PIN));
}

inline void resetState()
{
  triggerState = LOW;
  //detectState = LOW;
}
