#include "movie.h"
movie::movie(char t[], int y, char dd[], float d, float r):media(t, y) {
  strcpy(director, dd);
  duration = d;
  rating = r;
}

void movie::print(){
  cout << title << endl;
  cout << year << endl;
  cout << director << endl;
  cout << duration << endl;
  cout << rating << endl;
}
