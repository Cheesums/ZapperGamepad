#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Button.h"

class Rectangle:public Button
{
  public:

  Rectangle();
  Rectangle(bool newIsSet):Button(newIsSet);

  void draw(bool isInv);
};

#endif