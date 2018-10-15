#include <TVout.h>
#include <font6x8.h>
#include <video_gen.h>

TVout TV;

class Button
{
  public:

  bool isSet;

  Button(bool newIsSet)
  {
    isSet = newIsSet;
  }

  Button()
  {
    
  }
};

class Circle:public Button
{
  public:
  
  char faceChar;
  int posX;
  int posY;

  Circle(char newFace, int newPosX, int newPosY, bool newIsSet):Button(newIsSet)
  {
    faceChar = newFace;
    posX = newPosX;
    posY = newPosY;
  }

  Circle()
  {
    
  }
  
  void draw(bool isInv)
  {
    int buttonPosX = (29*posX)+64;
    int buttonPosY = (29*posY)+49;

    int circleFill = 2-(3*isInv);

    TV.println(buttonPosX-2, buttonPosY-3, faceChar);
    TV.draw_circle(buttonPosX, buttonPosY, 10, 1, circleFill);
  };
};

class Rectangle:public Button
{
  public:

  Rectangle()
  {
    
  }

  Rectangle(bool newIsSet):Button(newIsSet)
  {
    
  }

  void draw(bool isInv)
  {
    //TV.draw_rect(58, 42, 12, 12, 1, !isInv);
    TV.draw_rect(53, 39, 22, 20, 1, !isInv);
  }
};

class Arrow:public Button
{
  public:

  int posX; //-1 for left, 1 for right, 0 for middle
  int posY; //-1 for above, 1 for below, 0 for middle

  Arrow(int newPosX, int newPosY, bool newIsSet): Button(newIsSet)
  {
    posX = newPosX;
    posY = newPosY;
  }

  Arrow()
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
  };
};

int Button = 4;
bool Select = true;

void setup() 
{
  // put your setup code here, to run once:
  TV.begin(_NTSC);
  TV.select_font(font6x8);
  pinMode(Button, INPUT);

  Circle buttonA('A',-1,-1,0);
  Circle buttonB('B', 1, -1, 0);
  Circle buttonC('C',-1, 1, 0);
  Circle buttonD('D', 1, 1, 0);

  Arrow upArrow(0, -1, false);
  Arrow downArrow(0, 1, false);
  Arrow leftArrow(-1, 0, false);
  Arrow rightArrow(1, 0, false);

  Rectangle buttonMid(0);
  
  buttonA.draw(false);
  buttonB.draw(false);
  buttonC.draw(false);
  buttonD.draw(false);

  upArrow.draw(true);
  downArrow.draw(true);
  leftArrow.draw(true);
  rightArrow.draw(true);

  buttonMid.draw(false);

  //Reference lines for layout changes
  /*
  TV.draw_line(64, 0, 64, 96, 2);
  TV.draw_line(0, 49, 128, 49, 2);
  TV.draw_line(24, 49, 64, 9, 2);
  TV.draw_line(24, 49, 64, 89, 2);
  TV.draw_line(64, 89, 104, 49, 2);
  TV.draw_line(64, 9, 104, 49, 2);
  */
}
void loop() 
{
  // put your main code here, to run repeatedly:
  
}


void drawRect()
{
    // Draw mid button
    TV.draw_rect(58, 42, 12, 12, 1, 1); 
}
