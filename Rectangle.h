#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Button.h"
#include "TVout.h"

extern TVout TV;

class Rectangle:public Button
{
  public:

  Rectangle();
  Rectangle(bool set);
  
  void draw(bool isInv);
};
#endif
