/**
 * @file Array.cpp
 */

#include "Array.h"
#include <ctime>

using namespace std;

bool Array::srandFirstTime = true;
unsigned int Array::totalNumElements = 0;

Array::Array() {}

Array::Array(int size) : size(size) {
  Array::increaseNumElements(size);
  data = new int[size];
}

Array::~Array() {
  Array::decreaseNumElements(size);
  delete[] data;
}

Array::Array(const Array &other) : size(other.size), data(new int[other.size]) {
  Array::increaseNumElements(size);
  for (int i = 0; i < other.size; i++)
    data[i] = other.data[i];
}

int &Array::operator[](int index) { return data[index]; }

ostream &operator<<(ostream &out, const Array &arr) {
  for (int i = 0; i < arr.size; i++)
    out << arr.data[i] << " ";
  out << '\n';
  return out;
}

istream &operator>>(istream &in, Array &arr) {
  int *temp = new int[arr.size + 1];

  for (int i = 0; i < arr.size; i++) {
    temp[i] = arr[i];
  }
  in >> temp[arr.size];

  delete[] arr.data;
  arr.size += 1;
  arr.data = temp;
  return in;
}

Array Array::operator=(Array &other) {
  if (this != &other) {
    Array::decreaseNumElements(size);
    delete[] data;
    size = other.size;
    data = new int[size];
    Array::increaseNumElements(size);
    for (int i = 0; i < size; i++)
      data[i] = other.data[i];
  }
  return *this;
}

void Array::operator+=(const Array &other) {
  int *newArr = new int[size + other.size];

  for (int i = 0; i < size; i++)
    newArr[i] = data[i];

  for (int j = 0; j < other.size; j++)
    newArr[size + j] = other.data[j];

  size = size + other.size;
  Array::increaseNumElements(other.size);
  delete[] data;
  data = newArr;
}

Array &Array::operator++() {
  for (int i = 0; i < size; i++)
    ++data[i];
  return *this;
}

Array Array::operator++(int) {
  Array original(*this);
  for (int i = 0; i < size; i++)
    ++data[i];
  return original;
}

Array &Array::operator--() {
  for (int i = 0; i < size; i++)
    --data[i];
  return *this;
}

Array Array::operator--(int) {
  Array original(*this);
  for (int i = 0; i < size; i++)
    --data[i];
  return original;
}

Array &Array::operator!() {
  if (srandFirstTime) {
    srand(time(nullptr));
    srandFirstTime = false;
  }

  int last = size - 1;
  int index;
  while (last > 0) {
    index = rand() % (last + 1);
    swap(data[index], data[last]);
    last--;
  }
  return *this;
}

bool Array::operator==(const Array &other) const {
  if (size <= other.size) {
    for (int i = 0; i <= other.size - size; i++) {
      bool isSubset = true;

      for (int j = 0; j < size; j++)
        if (data[j] != other.data[i + j]) {
          isSubset = false;
          break;
        }

      if (isSubset)
        return true;
    }
  } else {
    for (int i = 0; i <= size - other.size; i++) {
      bool isSubset = true;

      for (int j = 0; j < other.size; j++)
        if (data[i + j] != other.data[j]) {
          isSubset = false;
          break;
        }

      if (isSubset)
        return true;
    }
  }

  return false;
}

bool Array::operator<(const Array &other) const {
  int minSize = min(size, other.size);

  for (int i = 0; i < minSize; i++) {
    if (data[i] < other.data[i])
      return true;
    else if (data[i] > other.data[i])
      return false;
  }

  return false;
}

bool Array::operator>(const Array &other) const {
  int minSize = min(size, other.size);

  for (int i = 0; i < minSize; i++) {
    if (data[i] > other.data[i])
      return true;
    else if (data[i] < other.data[i])
      return false;
  }

  return false;
}

int Array::operator*() const {
  int smallestValue = data[0];
  for (int i = 1; i < size; i++)
    smallestValue = data[i] < smallestValue ? data[i] : smallestValue;
  return smallestValue;
}

int Array::getSize() const { return size; }

int Array::getNumberOfElements() { return totalNumElements; }

void Array::increaseNumElements(int num) { Array::totalNumElements += num; }

void Array::decreaseNumElements(int num) { Array::totalNumElements -= num; }
