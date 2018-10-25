#ifndef CIRCLE_H
#define CIRCLE_H

#include "Button.h"
#include "TVout.h"
#include "font6x8.h"

extern TVout TV;

class Circle:public Button
{
  private:
  
  char faceChar;
  int posX;
  int posY;

  public:

  Circle(char newFace, int newPosX, int newPosY, bool newIsSet);
  Circle();
  
  void draw(bool isInv);
};

#endif
