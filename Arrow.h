#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Button.h"

class Arrow:public Button
{
  public:

  int posX; //-1 for left, 1 for right, 0 for middle
  int posY; //-1 for above, 1 for below, 0 for middle

  Arrow(int newPosX, int newPosY, bool newIsSet);
  Arrow();

  void draw(bool isInv);
};

#endif
