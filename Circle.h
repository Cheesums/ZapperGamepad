#ifndef CIRCLE_H
#define CIRCLE_H

#include "Button.h"

class Circle:public Button
{
  char faceChar;
  int posX;
  int posY;

  public:

  Circle(char newFace, int newPosX, int newPosY, bool newIsSet);
  Circle();
  
  void draw(bool isInv);
};

#endif
