#ifndef MEDIA_H
#define MEDIA_H
#include <iostream>
#include <cstring>

using namespace std;

class media {
  public:
  char title [40];
  int year;
  media(char[], int);
  char* getTitle();
  int getYear();
  virtual void print();
};
#endif

