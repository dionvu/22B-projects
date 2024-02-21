#pragma once
#include <iostream>

class Array {
private:
  unsigned int size;
  int *data;

public:
  Array(){};
  Array(int size) : size(size) { data = new int[size]; };
  ~Array() { delete[] data; }

  Array(const Array &other);

  bool operator!=(const Array &other) const;
  bool operator>=(const Array &other) const;
  Array &operator++();
  Array operator++(int);
  friend std::ostream &operator<<(std::ostream &out, const Array &other);
  friend std::istream &operator>>(std::istream &in, Array &other);
};
