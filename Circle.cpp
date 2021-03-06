# include "Circle.h"

Circle::Circle(char newFace, int newPosX, int newPosY, bool newIsSet):Button(newIsSet)
{
  faceChar = newFace;
  posX = newPosX;
  posY = newPosY;
}

Circle::Circle()
{
  faceChar = ' ';
  posX = 0;
  posY = 0;
}

void Circle::draw(bool isInv)
{
  int buttonPosX = (29*posX)+64;
  int buttonPosY = (29*posY)+49;

  int circleFill = 2-(3*isInv);

  TV.draw_circle(buttonPosX, buttonPosY, 10, 1, 0);
  TV.println(buttonPosX-2, buttonPosY-3, faceChar);
  TV.draw_circle(buttonPosX, buttonPosY, 10, 1, circleFill);
}
