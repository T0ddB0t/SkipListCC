#include "SkipList.h"
#include "data.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
  SkipList<map<int, int, char>, 41, 82> list;
  
  individuals insert;
  //insert.inserter();
  insert.printInfo();
  
}