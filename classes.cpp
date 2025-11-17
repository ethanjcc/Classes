#include <iostream>
#include <cstring>
#include <vector>
#include "video.h"
#include "movie.h"
#include "music.h"

using namespace std;

vector<media*> vect;
//calling functions
void addData();
void searchData();
void deleteData();

//main function that makes the functions go
int main() {
  char userinput[20];
  while(true) {
    cout << "enter command" << endl;
    cin >> userinput;
    if (strcmp(userinput, "ADD") == 0) {
      addData();
    }
    else if (strcmp(userinput, "SEARCH") == 0) {
      searchData();
    }
    else if (strcmp(userinput, "DELETE") == 0) {
      deleteData();
    }
    else if (strcmp(userinput, "QUIT") == 0) {
      break;
    }
    else {
      cout << "invalid" << endl;
    }
  }


  for (media* m : vect) {
    delete m;
  };
  return 0;
}
//for adding data
void addData() {
  char addinput[20];
  //asks what you want to add
  cout << "what do you want to add: ";
  cin >> addinput;
  //to add a videogame
  if (strcmp(addinput, "videogame") == 0) {
    char title[20];
    int year;
    char publisher[20];
    float rating;
    cout << "enter title: " << endl;
    cin >> title;
    cout << "enter year: " << endl;
    cin >> year;
    cout << "enter publisher: " << endl;
    cin >> publisher;
    cout << "enter rating: " << endl;
    cin >> rating;
    video* v = new video(title, year, publisher, rating);
    //v->setTitle(title);
    //v->setYear(year);
    //v->setPublisher(publisher);
    //v->setRating(rating);
    vect.push_back(v);
  }
  //to add music
  else if (strcmp(addinput, "music") == 0) {
    char title[20];
    int year;
    char artist[20];
    float duration;
    char publisher[20];
    cout << "enter title: " << endl;
    cin >> title;
    cout << "enter year: " << endl;
    cin >> year;
    cout << "enter artist: " << endl;
    cin >> artist;
    cout << "enter duration: " << endl;
    cin >> duration;
    cout << "enter publisher: " << endl;
    cin >> publisher;
    music* m = new music(title, year, artist, duration, publisher);
    //m->setTitle(title);
    //m->setYear(year);
    //m->setArtist(artist);
    //m->setDuration(duration);
    //m->setPublisher(publisher);
    vect.push_back(m);
  }
  //to add a movie
  else if (strcmp(addinput, "movie") == 0) {
    char title[20];
    int year;
    char director[20];
    float duration;
    float rating;
    cout << "enter title: " << endl;
    cin >> title;
    cout << "enter year: " << endl;
    cin >> year;
    cout << "enter director: " << endl;
    cin >> director;
    cout << "enter duration: " << endl;
    cin >> duration;
    cout << "enter rating: " << endl;
    cin >> rating;
    movie* mm = new movie(title, year, director, duration, rating);
    //mm->setTitle(title);
    //mm->setYear(year);
    //mm->setDirector(director);
    //mm->setRating(rating);
    vect.push_back(mm);
  }
}

//search for data
void searchData() {
  char searchType[20];
  cout << "Search by title or year?" << endl;
  cin >> searchType;
  //search by title
  if (strcmp(searchType, "title") == 0) {
    char title[20];
    cout << "enter title" << endl;
    cin.ignore();
    cin.getline(title, 20);
    //chatgpt helped with using a bool to find the data
    bool found = false;
    for (media* m : vect) {
      if (strcmp(m->getTitle(), title) == 0) {
	m->print();
	found = true;
      }
    }
    if (!found) {
      cout << "nothing has this title" << endl;
    }
  }
  //search by year
  else if (strcmp(searchType, "year") == 0) {
    int year;
    cout << "enter year" << endl;
    cin >> year;
    bool found = false;
    for (media* m : vect) {
      if (m->getYear() == year) {
	m->print();
	found = true;
      }
    }
    if (!found) {
      cout << "nothing was in this year" << endl;
    }
  }
  else {
    cout << "invalid" << endl;
  }
}

//to delete data
void deleteData() {
  char deleteType[20];
  cout << "delete by title or year?" << endl;
  cin >> deleteType;
  //delete by title
  if (strcmp(deleteType, "title") == 0) {
    char title[20];
    cout << "enter title" << endl;
    cin.ignore();
    cin.getline(title, 20);
    bool found = false;
    //chatgpt helped with for loop
    for (int i = 0; i < vect.size(); i++) {
      media* m = vect[i];
      if (strcmp(m->getTitle(), title) == 0) {
	found = true;
	cout << "found item: " << endl;
	m->print();
	delete m;
	vect.erase(vect.begin() + i);
	cout << "deleted" << endl;
	i--;
      }
    }
    if (!found) {
      cout << "not found" << endl;
    }
  }
  //delete by year
  else if (strcmp(deleteType, "year") == 0) {
    int year;
    cout << "enter year" << endl;
    cin >> year;
    bool found = false;
    for (int i = 0; i < vect.size(); i++) {
      media* m = vect[i];
      if (m->getYear() == year) {
	found = true;
	cout << "found item: " << endl;
	m->print();
	delete m;
	vect.erase(vect.begin() + i);
	cout << "deleted" << endl;
	i--;
      }
    }
    if (!found) {
      cout << "not found" << endl;
    }
  }
  else {
    cout << "invalid" << endl;
  }
}
