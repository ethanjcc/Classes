#include "media.h"
media::media(char t[], int y) {
  strcpy(title, t);
  year = y;
}

char* media::getTitle(){
  return title;
}

int media::getYear(){
  return year;
}

void media::print(){
  cout << title << endl;
  cout << year << endl;
}
