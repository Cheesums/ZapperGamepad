#ifndef BUTTON_H
#define BUTTON_H

#include <TVout.h>

#include <font6x8.h>
#include <video_gen.h>


class Button
{
  public:

  bool isSet;

  Button();
  Button(bool set);
};

#endif
