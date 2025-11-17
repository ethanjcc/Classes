#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <cstring>

using namespace std;

#include "media.h"
class movie : public media {
  public:
  char director [40];
  float duration;
  float rating;
  movie(char[], int, char[], float, float);
  virtual void print();
};
#endif
