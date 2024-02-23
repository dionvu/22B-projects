#pragma once
#include <iostream>

class Array {
private:
  unsigned int size;
  int *data;
  static bool firstTime;

public:
  static bool isFirstTime() { return firstTime; };

  Array();
  Array(int);
  ~Array();

  Array(const Array &other);

  Array operator=(Array &);

  bool operator==(const Array &) const;
  bool operator!=(const Array &) const;
  bool operator<=(const Array &) const;
  bool operator>=(const Array &) const;
  bool operator<(const Array &) const;
  bool operator>(const Array &) const;

  Array &operator!();

  int operator*() const;
  void operator+=(const Array &other); // Adds the two arrays into a new one

  Array &operator++();
  Array &operator--();
  friend std::ostream &operator<<(std::ostream &out, const Array &);
  friend std::istream &operator>>(std::istream &, Array &);
  int getSize() const;

  int &operator[](int);
};
