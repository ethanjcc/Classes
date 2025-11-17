#ifndef VIDEO_H
#define VIDEO_H
#include <iostream>
#include <cstring>

using namespace std;

#include "media.h"
class video : public media {
  public:
  char publisher [40];
  float rating;
  video(char[], int, char[], float);
  virtual void print();
};
#endif
