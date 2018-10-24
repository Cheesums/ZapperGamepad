#ifndef BUTTON_H
#define BUTTON_H

#include <TVout.h>

#include <font6x8.h>
#include <video_gen.h>


class Button
{
  private:

  bool isSet;

  public:
  
  Button();
  Button(bool set);
};

#endif
