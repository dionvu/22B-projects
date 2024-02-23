#include "Array.h"
#include "ctime"

bool Array::firstTime = true;

Array::Array(){};

Array::Array(int size) : size(size) { data = new int[size]; };

Array::~Array() { delete[] data; };

int &Array::operator[](int index) { return data[index]; }

bool Array::operator==(const Array &other) const {
  if (this->size <= other.size) {
    for (int i = 0; i < this->size; i++) {
      if (this->data[i] != other.data[i])
        return false;
    }
  } else {
    for (int i = 0; i < other.size; i++) {
      if (this->data[i] != other.data[i])
        return false;
    }
  }
  return true;
}

std::ostream &operator<<(std::ostream &out, const Array &other) {
  for (int i = 0; i < other.size; i++)
    out << other.data[i] << " ";
  out << '\n';
  return out;
}

Array::Array(const Array &other) : size(other.size), data(new int[other.size]) {
  for (int i = 0; i < other.size; i++)
    data[i] = other.data[i];
}

Array Array::operator=(Array &other) {
  if (this != &other) { // Check for self-assignment
    delete[] data;
    size = other.size;
    data = new int[size];
    for (int i = 0; i < size; i++)
      data[i] = other.data[i];
  }
  return *this;
}
bool Array::operator<(const Array &other) const {
  return this->data[0] < other.data[0];
}

bool Array::operator>(const Array &other) const {
  return this->data[0] > other.data[0];
}

bool Array::operator>=(const Array &other) const {
  return this->data[0] >= other.data[0];
}

bool Array::operator<=(const Array &other) const {
  return this->data[0] <= other.data[0];
}

int Array::operator*() const {
  int smallestValue = data[0];
  for (int i = 1; i < size; i++)
    smallestValue = data[i] < smallestValue ? data[i] : smallestValue;
  return smallestValue;
}

void Array::operator+=(const Array &other) {
  int *newArr = new int[size + other.size];

  for (int i = 0; i < size; i++)
    newArr[i] = data[i];

  for (int j = 0; j < other.size; j++)
    newArr[size + j] = other.data[j];

  size = size + other.size;
  delete[] data;
  data = newArr;
}

Array &Array::operator--() {
  for (int i = 0; i < size; i++)
    --data[i];
  return *this;
}

Array &Array::operator++() {
  for (int i = 0; i < size; i++)
    ++data[i];
  return *this;
}

Array &Array::operator!() {
  if (isFirstTime()) {
    std::srand(std::time(nullptr));
    firstTime = false;
  }

  int last = size - 1;
  int index;
  while (last > 0) {
    index = std::rand() % (last + 1);
    std::swap(data[index], data[last]);
    last--;
  }
  return *this;
}

int Array::getSize() const { return size; };
