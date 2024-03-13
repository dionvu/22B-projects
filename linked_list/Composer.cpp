#include "Composer.h"
#include "iostream"

using namespace std;

Composer::Composer() : name(""), yearPassed(0){};

Composer::Composer(string name, unsigned int yearPassed)
    : name(name), yearPassed(yearPassed){};

ostream &operator<<(ostream &out, const Composer &composer) {
  out << "Name: " << composer.name << " Year: " << composer.yearPassed << endl;
  return out;
}