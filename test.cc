#include "SkipList.h"
#include "data.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
  SkipList<map<int, int, char>, 41, 82> list;
  
  int quit = 1;
  int decision; 
  individuals inserter;
  while(quit != 0){
    cout << "would you like to insert or print info?\n"
         << "1: insert 2: print info 0: quit\n"; 
    cin >> decision;
    switch(decision){
      case 1:
        inserter.inserter();
        break;
      case 2:
        inserter.printInfo();
        break;
      case 0:
        quit = 0;
        break;
      default:
        cout << "Error: wrong input, try again?" << endl;
        break;
    }
  }
}