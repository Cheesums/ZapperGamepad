#include "Button.h"
#include "Arrow.h"
#include "Circle.h"
#include "Rectangle.h"

#include <TVout.h>
#include "font6x8.h"
#include "video_gen.h"

TVout TV;

void setup() 
{
  // put your setup code here, to run once:
  TV.begin(_NTSC);
  TV.select_font(font6x8);

  Circle buttonA('A',-1,-1,0);
  Circle buttonB('B', 1, -1, 0);
  Circle buttonC('C',-1, 1, 0);
  Circle buttonD('D', 1, 1, 0);

  Arrow upArrow(0, -1, false);
  Arrow downArrow(0, 1, false);
  Arrow leftArrow(-1, 0, false);
  Arrow rightArrow(1, 0, false);

  Rectangle buttonMid(0);
  
  buttonA.draw(true);
  buttonB.draw(false);
  buttonC.draw(false);
  buttonD.draw(true);

  upArrow.draw(true);
  downArrow.draw(false);
  leftArrow.draw(false);
  rightArrow.draw(true);

  buttonMid.draw(true);

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
  
}
