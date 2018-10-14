#include "Arrow.h"

Arrow::Arrow(int newPosX, int newPosY, bool newIsSet): Button(newIsSet)
{
  posX = newPosX;
  posY = newPosY;
}

Arrow::Arrow()
{

}

void draw(bool isInv)
{
  
  int rectX = 58+(20*posX);
  int rectY = 43+(20*posY);
  int deltX = 11+abs(posY)+abs(posX);
  int deltY = 11+abs(posX)+abs(posY);

  TV.draw_rect(rectX, rectY, deltX, deltY, 1, !isInv);

  if (isInv)
  {
    int lineOffAX0 =  ((6+(5*posX))*abs(posX))+(-7*abs(posY));
    int lineOffAY0 =  (-7*abs(posX))+((6+(5*posY))*abs(posY));
    int lineOffAX1 =  ((6+(5*posX))*abs(posX))+(19*abs(posY));
    int lineOffAY1 = (19*abs(posX))+((6+(5*posY))*abs(posY));

    int linePosAX0 = rectX + lineOffAX0;
    int linePosAY0 = rectY + lineOffAY0;
    int linePosAX1 = rectX + lineOffAX1;
    int linePosAY1 = rectY + lineOffAY1;

    int lineTipX = rectX +((6-posX)+(20*posX)-posX)*abs(posX)+(6*abs(posY));
    int lineTipY = rectY +(6+(18*posY));
    
    int linePosBX0 = rectX + (((1+posX)/2)*12)*posX;
    int linePosBY0 = rectY + (((1+posY)/2)*12)*posY;
    int linePosBX1 = rectX + (((1+posX)/2)*12)*posX + 13*abs(posY);
    int linePosBY1 = rectY + (((1+posY)/2)*12)*posY+12*abs(posX);

    int linePosCX0 = rectX + (((1+posX)/2)*12)*posX + abs(posY) - posX;
    int linePosCY0 = rectY + (((1+posY)/2)*12)*posY - posY + abs(posX);
    int linePosCX1 = rectX + (((1+posX)/2)*12)*posX + 13*abs(posY) - abs(posY) - posX;
    int linePosCY1 = rectY + (((1+posY)/2)*12)*posY+12*abs(posX) - posY - abs(posX);
    
    //TV.draw_line(51, 24, 78, 24, 2);
    TV.draw_line(linePosAX0, linePosAY0, linePosAX1, linePosAY1, 1);
    TV.draw_line(linePosAX0, linePosAY0, lineTipX, lineTipY, 1);
    TV.draw_line(linePosAX1, linePosAY1, lineTipX, lineTipY, 1);
    TV.draw_line(linePosBX0, linePosBY0, linePosBX1, linePosBY1, 0);
    TV.draw_line(linePosCX0, linePosCY0, linePosCX1, linePosCY1, 0);
    
  }else
  {
    
    int arrOffX0 = (-7*abs(posY))+((((1+posX)/2)*11)+((-1+posX)/2))*posX;
    int arrOffY0 = ((((1+posY)/2)*11)+((-1+posY)/2))*posY+(-7*abs(posX));
    int arrOffX1 = (20*abs(posY))+((((1+posX)/2)*11)+((-1+posX)/2))*posX;
    int arrOffY1 = ((((1+posY)/2)*11)+((-1+posY)/2))*posY+(19*abs(posX));

    int arrMultX0 = posX+1-abs(posX);
    int arrMultY0 = posY+1-abs(posY);
    int arrMultX1 = (-1*abs(posY))+posX;
    int arrMultY1 = posY+(-1*abs(posX));

    int arrPosX0 = rectX+arrOffX0;
    int arrPosY0 = rectY+arrOffY0;
    int arrPosX1 = rectX+arrOffX1;
    int arrPosY1 = rectY+arrOffY1;

    for(int i = 0; i < 14; i++)
    {
      TV.draw_line(arrPosX0+(i*arrMultX0), arrPosY0+(i*arrMultY0), arrPosX1+(i*arrMultX1), arrPosY1+(i*arrMultY1), 1);
    }
  }
}
