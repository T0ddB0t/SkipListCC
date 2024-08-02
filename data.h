#include <iostream>
#include "SkipList.h"
#include <memory>   


class individuals {
private:
  map<shared_ptr<int>, shared_ptr<string>> students;

  map<shared_ptr<int>, shared_ptr<string>> classes;

  map<char, string> grades() {
    map<char, string> grades;
    grades.insert(pair<char, string>('a', "A+"));
    grades.insert(pair<char, string>('b', "A"));
    grades.insert(pair<char, string>('c', "A-"));
    grades.insert(pair<char, string>('d', "B+"));
    grades.insert(pair<char, string>('e', "B"));
    grades.insert(pair<char, string>('f', "B-"));
    grades.insert(pair<char, string>('g', "C+"));
    grades.insert(pair<char, string>('h', "C"));
    grades.insert(pair<char, string>('i', "C-"));
    grades.insert(pair<char, string>('j', "D+"));
    grades.insert(pair<char, string>('k', "D"));
    grades.insert(pair<char, string>('l', "D-"));
    grades.insert(pair<char, string>('m', "F+"));
    grades.insert(pair<char, string>('n', "F"));
    grades.insert(pair<char, string>('o', "F-"));
    return grades;
  }
protected:
//have to fix
//idk what tf to do
  void printMap(const map<shared_ptr<int>, shared_ptr<string>>& myMap) {
      for (auto it = myMap.cbegin(); it != myMap.cend(); ++it) {
          cout << *(it->first) << ", " << *(it->second) << endl;
      }
  } // might have ti change to unique pointers 
public:
  void inserter(){
    int quit = 1;
    shared_ptr<string> indiClass(new string);
    shared_ptr<string> name(new string);
    shared_ptr<int> rank(new int);
    int decision;
    while(quit == 1){
      cout << "what do you need to insert?" << endl;
      cout << "Students: 1, Classes: 2, Go Back: 0" << endl;
      //cout << "Using A+ thru F- Grading" << endl;
      cin >> decision;
      cin.ignore();//std::numeric_limits<std::streamsize>::max(), '\n');
      switch(decision){
        case 1:
            cout << "Insert students here..." << endl;
            cout << "Name: ";
            cin >> *name;
            cout << "Rank: ";
            cin >> *rank;
            students.insert(pair<shared_ptr<int>, shared_ptr<string>>(rank, name));
            cout << "<<<Insert complete>>>" << endl;         
          break;
        case 2:
            cout << "Insert Classes here..." << endl;
            cout << "Class: ";
            cin >> *indiClass;
            cout << "Rank: ";
            cin >> *rank;
            classes.insert(pair<shared_ptr<int>, shared_ptr<string>>(rank, indiClass));
            cout << "<<<Insert complete>>>" << endl;
          break;
        case 0:
          quit = 0;
          break;
        default:
          cout << "Error: wrong input, try again?" << endl;
      }
    }
  }
  void printInfo(){
    int decision, quit = 1;
    while(quit != 0){
      cout << "What info would you like to see?" << endl
           << "1: Students 2: Classes 0: Go Back" << endl;
      cin >> decision;
      switch(decision){
        case 1:
          cout << "<<<STUDENTS>>>" << endl;
          printMap(students);
          cout << "<<<END STUDENTS>>>" << endl;
          break;
        case 2:
          cout << "<<<CLASSES>>>" << endl;
          printMap(classes);
          cout << "<<<END CLASSES>>>" << endl;
          break;
        // case 3:
        //   cout << "<<<GRADES>>>" << endl;
        //   cout << grades << endl;
        //   cout << "<<<END GRADES" << endl;
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
  ~individuals(){};
};
