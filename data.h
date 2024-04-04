#include "SkipList.h"

class individuals {
public:
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

  map<char, string> grades(char rank, string indiGrade) {
    map<char, string> grades;
    grades.insert(pair<char, string>(rank, indiGrade));
    return grades;
  }
};
class inserter {
public:
};
