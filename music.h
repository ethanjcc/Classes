#ifndef MUSIC_H
#define MUSIC_H
#include <iostream>
#include <cstring>

using namespace std;

#include "media.h"
class music : public media {
  public:
  char artist [40];
  float duration;
  char publisher [40];
  music(char[], int, char[], float, char[]);
  virtual void print();
};
#endif
