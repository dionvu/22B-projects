/**
 * @file Composer.cpp
 * @brief Implementation of Composer class.
 */

#include "Composer.h"
#include "iostream"

using namespace std;

Composer::Composer() : name(""), yearPassed(0){};

Composer::Composer(string name, unsigned int yearPassed)
    : name(name), yearPassed(yearPassed){};

ostream &operator<<(ostream &out, const Composer &composer) {
  out << composer.name << " - " << composer.yearPassed << endl;
  return out;
}

bool Composer::operator<(const Composer &other) const {
  return this->yearPassed < other.yearPassed;
}

bool Composer::operator>(const Composer &other) const {
  return this->yearPassed > other.yearPassed;
}

bool Composer::operator<=(const Composer &other) const {
  return this->yearPassed <= other.yearPassed;
}

bool Composer::operator>=(const Composer &other) const {
  return this->yearPassed >= other.yearPassed;
}

bool Composer::operator==(const Composer &other) const {
  return this->name == other.name;
}
