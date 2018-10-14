#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Button.h"

class Circle:public Button
{
  public:
  
  char faceChar;
  int posX;
  int posY;

  Circle(char newFace, int newPosX, int newPosY, bool newIsSet):Button(newIsSet);
  Circle();
  
  void draw(bool isInv);
};

#endif
