#ifndef ARROW_H
#define ARROW_H

#include "Button.h"

class Arrow:public Button
{
  private:

  int posX; //-1 for left, 1 for right, 0 for middle
  int posY; //-1 for above, 1 for below, 0 for middle

  public:
  
  Arrow(int newPosX, int newPosY, bool newIsSet);
  Arrow();

  void draw(bool isInv);
};

#endif
