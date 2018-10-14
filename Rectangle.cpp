# include "Rectangle.h"

Rectangle::Rectangle()
{
  
}

Rectangle::Rectangle(bool newIsSet):Button(newIsSet)
{

}

void draw(bool isInv)
{
  //TV.draw_rect(58, 42, 12, 12, 1, !isInv);
  TV.draw_rect(53, 39, 22, 20, 1, !isInv);
}
