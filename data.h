#include <iostream>
#include "SkipList.h"
#include <limits>

class individuals {
private:
  map<int, string> students(int number, string name) {
    map<int, string> student;
    student.insert(pair<int, string>(number, name));
    return student;
  }

  map<int, string> classes(int number, string classes) {
    map<int, string> period;
    period.insert(pair<int, string>(number, classes));
    return period;
  }

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
public:
  void inserter(){
    int quit = 1;
    string indiClass;
    string name;
    int rank;
    int decision;
    while(quit == 1){
      cout << "what do you need to insert?" << endl;
      cout << "Students: 1, Classes: 2, Quit: 0" << endl;
      cout << "Using A+ thru F- Grading" << endl;
      cin >> decision;
      cin.ignore();//std::numeric_limits<std::streamsize>::max(), '\n');
      switch(decision){
        case 1:
            cout << "Insert students here..." << endl;
            cout << "Name: ";
            getline(cin, name);
            cout << "Rank: ";
            cin >> rank;
            students(rank, name);
            cout << "<<<Insert complete>>>" << endl;         
          break;
        case 2:
            cout << "Insert Classes here..." << endl;
            cout << "Class: ";
            getline(cin, indiClass);
            cout << "Rank: ";
            cin >> rank;
            classes(rank, indiClass);
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
    while(quit == 1){
      switch(decision){
        case 1:
          cout << "<<<STUDENTS>>>" << endl;
          cout << students << endl;
          cout << "<<<END STUDENTS>>>" << endl;
          break;
        case 2:
          cout << "<<<CLASSES>>>" << endl;
          cout << classes << endl;
          cout << "<<<END CLASSES>>>" << endl;
          break;
        case 3:
          cout << "<<<GRADES>>>" << endl;
          cout << grades << endl;
          cout << "<<<END GRADES" << endl;
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
};
