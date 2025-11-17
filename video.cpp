#include "video.h"
video::video(char t[], int y, char p[], float r):media(t, y) {
  strcpy(publisher, p);
  rating = r;
}

void video::print(){
  cout << title << endl;
  cout << year << endl;
  cout << publisher << endl;
  cout << rating << endl;
}
