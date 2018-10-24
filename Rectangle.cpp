# include "Rectangle.h"

TVout RectTV;

Rectangle::Rectangle()
{
  
}

Rectangle::Rectangle(bool newIsSet):Button(newIsSet)
{

}

void Rectangle::draw(bool isInv)
{
  //RectTV.draw_rect(58, 42, 12, 12, 1, !isInv);
  RectTV.draw_rect(53, 39, 22, 20, 1, !isInv);
}
