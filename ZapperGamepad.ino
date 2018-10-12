#include <TVout.h>
#include <font6x8.h>
#include <video_gen.h>

TVout TV;

class Button
{
  public:

  bool isSet;

  Button(bool newIsSet)
  {
    isSet = newIsSet;
  }

  Button()
  {
    
  }
};

class Circle:public Button
{
  public:
  
  char faceChar;
  int posX;
  int posY;

  Circle(char newFace, int newPosX, int newPosY, bool newIsSet):Button(newIsSet)
  {
    faceChar = newFace;
    posX = newPosX;
    posY = newPosY;
  }

  Circle()
  {
    
  }
  
  void draw(bool isInv)
  {
    int buttonPosX = (30*posX)+64;
    int buttonPosY = (30*posY)+49;

    int circleFill = 2-(3*isInv);

    TV.println(buttonPosX-2, buttonPosY-3, faceChar);
    TV.draw_circle(buttonPosX, buttonPosY, 7, 1, circleFill);
  };
};

int Button = 4;
bool Select = true;

void setup() 
{
  // put your setup code here, to run once:
  TV.begin(_NTSC);
  TV.select_font(font6x8);
  pinMode(Button, INPUT);

  Circle buttonA('A',-1,-1,0);
  Circle buttonB('B', 1, -1, 0);
  Circle buttonC('C',-1, 1, 0);
  Circle buttonD('D', 1, 1, 0);
  
  buttonA.draw(false);
  buttonB.draw(false);
  buttonC.draw(false);
  buttonD.draw(false);
  
}
void loop() 
{
  // put your main code here, to run repeatedly:
  
}


void drawRect()
{
    // Draw mid button
    TV.draw_rect(58, 42, 12, 12, 1, 1); 
}

