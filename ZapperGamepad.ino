#include <TVout.h>
#include <video_gen.h>

TVout TV;
int Button = 4;

void setup() 
{
  // put your setup code here, to run once:
  TV.begin(_NTSC);
  pinMode(Button, INPUT);
}
void loop() 
{
  // put your main code here, to run repeatedly:

  if (digitalRead(Button) == HIGH)
  {

    // Draw mid button
    drawRect();

    //Draw top arrow
    drawUp();

    //Draw left arrow
    drawLeft();
    
    //Draw right arrow
    drawRight();

    //Draw bottom arrow
    drawDown();

    //Draw Circles
    drawA();

    drawB();
    
    drawC();
 
    drawD();

    TV.delay (60);
  } else {

    TV.clear_screen();

    //INVERSE Draw top arrow
    drawInvUp();

    //INVERSE Draw left arrow
    drawInvLeft();

    //INVERSE Draw right arrow
    drawInvRight();
    
    //INVERSE Draw bottom arrow
    drawInvDown();

    //INVERSE Draw Circles
    drawInvA();

    drawInvB();

    drawInvC();

    drawInvD();

    TV.delay (60);
  }


}

void drawRect()
{
    // Draw mid button
    TV.draw_rect(58, 42, 12, 12, 1, 1); 
}

void drawUp()
{
    TV.draw_rect(58, 23, 12, 11, 1, 1);
    TV.draw_line(53, 22, 76, 22, 1);
    TV.draw_line(54, 21, 75, 21, 1);
    TV.draw_line(55, 20, 74, 20, 1);
    TV.draw_line(56, 19, 73, 19, 1);
    TV.draw_line(57, 18, 72, 18, 1);
    TV.draw_line(58, 17, 71, 17, 1);
    TV.draw_line(59, 16, 70, 16, 1);
    TV.draw_line(60, 15, 69, 15, 1);
    TV.draw_line(61, 14, 68, 14, 1);
    TV.draw_line(62, 13, 67, 13, 1);
    TV.draw_line(63, 12, 66, 12, 1);
    TV.set_pixel(64, 11, 1);
}

void drawLeft()
{
    TV.draw_rect(39, 42, 11, 12, 1, 1);
    TV.draw_line(38, 37, 38, 59, 1);
    TV.draw_line(37, 38, 37, 58, 1);
    TV.draw_line(36, 39, 36, 57, 1);
    TV.draw_line(35, 40, 35, 56, 1);
    TV.draw_line(34, 41, 34, 55, 1);
    TV.draw_line(33, 42, 33, 54, 1);
    TV.draw_line(32, 43, 32, 53, 1);
    TV.draw_line(31, 44, 31, 52, 1);
    TV.draw_line(30, 45, 30, 51, 1);
    TV.draw_line(29, 46, 29, 50, 1);
    TV.draw_line(28, 47, 28, 49, 1);
    TV.set_pixel(27, 48, 1);
}

void drawRight()
{
    TV.draw_rect(78, 42, 11, 12, 1, 1);
    TV.draw_line(89, 37, 89, 59, 1);
    TV.draw_line(90, 38, 90, 58, 1);
    TV.draw_line(91, 39, 91, 57, 1);
    TV.draw_line(92, 40, 92, 56, 1);
    TV.draw_line(93, 41, 93, 55, 1);
    TV.draw_line(94, 42, 94, 54, 1);
    TV.draw_line(95, 43, 95, 53, 1);
    TV.draw_line(96, 44, 96, 52, 1);
    TV.draw_line(97, 45, 97, 51, 1);
    TV.draw_line(98, 46, 98, 50, 1);
    TV.draw_line(99, 47, 99, 49, 1);
    TV.set_pixel(100, 48, 1);
}

void drawDown()
{
    TV.draw_rect(58, 62, 12, 11, 1, 1);
    TV.draw_line(53, 73, 76, 73, 1);
    TV.draw_line(54, 74, 75, 74, 1);
    TV.draw_line(55, 75, 74, 75, 1);
    TV.draw_line(56, 76, 73, 76, 1);
    TV.draw_line(57, 77, 72, 77, 1);
    TV.draw_line(58, 78, 71, 78, 1);
    TV.draw_line(59, 79, 70, 79, 1);
    TV.draw_line(60, 80, 69, 80, 1);
    TV.draw_line(61, 81, 68, 81, 1);
    TV.draw_line(62, 82, 67, 82, 1);
    TV.draw_line(63, 83, 66, 83, 1);
    TV.set_pixel(64, 84, 1);  
}

void drawA()
{
    TV.draw_circle(34, 18, 7, 1, 1); //TL A
    TV.draw_line(34, 13, 30, 21, 0);
    TV.draw_line(34, 13, 38, 21, 0);
    TV.draw_line(31, 19, 37, 19, 0);
}

void drawB()
{
    TV.draw_circle(93, 18, 7, 1, 1); //TR B
    TV.draw_line(91, 13, 91, 21, 0);
    TV.draw_line(91, 13, 95, 13, 0);
    TV.draw_line(91, 17, 95, 17, 0);
    TV.draw_line(91, 21, 96, 21, 0);
    TV.draw_line(95, 14, 95, 17, 0);
    TV.draw_line(96, 18, 96, 20, 0);
}

void drawC()
{
    TV.draw_circle(34, 77, 7, 1, 1); //BL C
    TV.draw_line(33, 73, 37, 73, 0);
    TV.draw_line(31, 75, 31, 79, 0);
    TV.draw_line(33, 81, 37, 81, 0);
    TV.set_pixel(37, 80, 0);
    TV.set_pixel(37, 74, 0);
    TV.set_pixel(32, 74, 0);
    TV.set_pixel(32, 80, 0);
}

void drawD()
{
    TV.draw_circle(93, 77, 7, 1, 1); //BR D
    TV.draw_line(90, 73, 90, 81, 0);
    TV.draw_line(90, 73, 95, 73, 0);
    TV.draw_line(90, 81, 95, 81, 0);
    TV.draw_line(96, 75, 96, 80, 0);
    TV.draw_line(94, 74, 96, 74, 0);
    TV.draw_line(95, 80, 97, 80, 0);
}

void drawInvUp()
{
    TV.draw_rect(58, 23, 12, 11, 1, 0);
    TV.draw_line(59, 23, 70, 23, 0);
    TV.draw_line(53, 22, 59, 22, 1);
    TV.draw_line(70, 22, 75, 22, 1);
    TV.draw_line(53, 22, 64, 11, 1);
    TV.draw_line(64, 11, 75, 22, 1);
}

void drawInvLeft()
{
    TV.draw_rect(39, 42, 11, 12, 1, 0);
    TV.draw_line(39, 53, 39, 43, 0);
    TV.draw_line(38, 42, 38, 37, 1);
    TV.draw_line(38, 54, 38, 59, 1);
    TV.draw_line(38, 36, 27, 47, 1);
    TV.draw_line(38, 59, 27, 48, 1);
}

void drawInvRight()
{
    TV.draw_rect(78, 42, 11, 12, 1, 0);
    TV.draw_line(89, 43, 89, 53, 0);
    TV.draw_line(89, 37, 89, 42, 1);
    TV.draw_line(89, 54, 89, 59, 1);
    TV.draw_line(89, 37, 100, 48, 1);
    TV.draw_line(89, 59, 100, 48, 1);  
}

void drawInvDown()
{
    TV.draw_rect(58, 62, 12, 11, 1, 0);
    TV.draw_line(59, 73, 70, 73, 0);
    TV.draw_line(53, 73, 59, 73, 1);
    TV.draw_line(70, 73, 75, 73, 1);
    TV.draw_line(53, 73, 64, 84, 1);
    TV.draw_line(75, 73, 64, 84, 1);
}

void drawInvA()
{
    TV.draw_circle(34, 18, 7, 1, 0); //TL A
    TV.draw_line(34, 13, 30, 21, 1);
    TV.draw_line(34, 13, 38, 21, 1);
    TV.draw_line(31, 19, 37, 19, 1);
}

void drawInvB()
{
    TV.draw_circle(93, 18, 7, 1, 0); //TR B
    TV.draw_line(91, 13, 91, 21, 1);
    TV.draw_line(91, 13, 95, 13, 1);
    TV.draw_line(91, 17, 95, 17, 1);
    TV.draw_line(91, 21, 96, 21, 1);
    TV.draw_line(95, 14, 95, 17, 1);
    TV.draw_line(96, 18, 96, 20, 1);  
}

void drawInvC()
{
    TV.draw_circle(34, 77, 7, 1, 0); //BL C
    TV.draw_line(33, 73, 37, 73, 1);
    TV.draw_line(31, 75, 31, 79, 1);
    TV.draw_line(33, 81, 37, 81, 1);
    TV.set_pixel(37, 80, 1);
    TV.set_pixel(37, 74, 1);
    TV.set_pixel(32, 74, 1);
    TV.set_pixel(32, 80, 1);  
}

void drawInvD()
{
    TV.draw_circle(93, 77, 7, 1, 0); //BR D
    TV.draw_line(90, 73, 90, 81, 1);
    TV.draw_line(90, 73, 95, 73, 1);
    TV.draw_line(90, 81, 95, 81, 1);
    TV.draw_line(96, 75, 96, 80, 1);
    TV.draw_line(94, 74, 96, 74, 1);
    TV.draw_line(95, 80, 97, 80, 1);  
}

