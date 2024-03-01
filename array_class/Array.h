/**
 * @file Array.h
 * @brief Implementation of an Array class with quirky modifications to
 * specific operators.
 * @date 2024-02-29
 */

#pragma once
#include <iostream>

using namespace std;

/**
 * @class Array
 * @brief Represents a dynamic integer array with various operations.
 */
class Array {
private:
  unsigned int size;          /// Size of the array.
  int *data;                  /// Pointer to the dynamically allocated array.
  static bool srandFirstTime; /// Flag to track if random seed way already set.
  static unsigned int totalNumElements;

public:
  /**
   * @brief Getter for the size of the array.
   * @return The size of the array.
   */
  int getSize() const;

  /**
   * @brief Subscript operator for array element access.
   * @param index The index of the array.
   * @return Reference to the element at the specified index.
   */
  int &operator[](int);

  /**
   * @brief Static method to get the total number of elements across all
   * instances.
   * @return The total number of elements.
   */
  static int getNumberOfElements();

  /**
   * @brief Adds to the total number of elements.
   * @param num Number of elements to add.
   */
  static void increaseNumElements(int);

  /**
   * @brief Subtracts from the total number of elements.
   * @param num Number of elements to add.
   */
  static void decreaseNumElements(int);

  /**
   * @brief Default constructor.
   */
  Array();

  /**
   * @brief Constructor that initializes the array with a given
   * size.
   * @param size The size of the array.
   */
  Array(int);

  /**
   * @brief Destructor. Frees the dynamically allocated memory.
   */
  ~Array();

  /**
   * @brief Copy constructor.
   * @param other The Array object to be copied.
   */
  Array(const Array &);

  /**
   * @brief Assignment operator.
   * @param other The Array object to be assigned.
   * @return Reference to the modified Array object.
   */
  Array operator=(Array &);

  /**
   * @brief Equality operator for comparing arrays. checks if either array is a
   * subset of the other.
   * @param other The Array to be compared.
   * @return True if arrays are equal; otherwise, false.
   */
  bool operator==(const Array &) const;

  /**
   * @brief Less than operator for comparing arrays.
   * @param other The Array to be compared.
   * @return True if the first element of the current array is less than the
   * other's. If they are equal, continue comparing until an element is either
   * greater or less.
   */
  bool operator<(const Array &) const;

  /**
   * @brief Greater than operator for comparing arrays.
   * @param other The Array to be compared.
   * @return True if the first element of the current array is greater than the
   * other's; If they are equal, continue comparing until an element is either
   * greater or less.
   */
  bool operator>(const Array &) const;

  /**
   * @brief Operator for shuffling array elements.
   * @return Reference to the modified Array object.
   */
  Array &operator!();

  /**
   * @brief Operator for finding the smallest element in
   * the array.
   * @return The smallest element in the array.
   */
  int operator*() const;

  /**
   * @brief Addition assignment operator for concatenating arrays.
   * @param other The Array to be concatenated.
   */
  void operator+=(const Array &);

  /**
   * @brief Pre-increment operator for incrementing all elements.
   * @return Reference to the modified Array object.
   */
  Array &operator++();

  /**
   * @brief Post-increment operator for incrementing all elements.
   * @param Unused parameter to differentiate from pre-increment.
   * @return Copy of the original Array object before increment.
   */
  Array operator++(int);

  /**
   * @brief Pre-decrement operator for decrementing all elements.
   * @return Reference to the modified Array object.
   */
  Array &operator--();

  /**
   * @brief Post-decrement operator for decrementing all elements.
   * @param Unused parameter to differentiate from pre-decrement.
   * @return Copy of the original Array object before decrement.
   */
  Array operator--(int);

  /**
   * @brief Output stream operator for printing the array.
   * @param out The output stream.
   * @param arr The Array object to be printed.
   * @return Reference to the output stream.
   */
  friend ostream &operator<<(ostream &, const Array &);
};
