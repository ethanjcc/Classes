#include "music.h"
music::music(char t[], int y, char a[], float d, char p[]):media(t, y) {
  strcpy(artist, a);
  duration = d;
  strcpy(publisher, p);
}

void music::print(){
  cout << title << endl;
  cout << year << endl;
  cout << artist << endl;
  cout << duration << endl;
  cout << publisher << endl;
}
