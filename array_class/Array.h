/**
 * @file Array.h
 * @brief Implementation of the Array class.
 */

#pragma once
#include <iostream>

/**
 * @class Array
 * @brief Represents a dynamic integer array with various operations.
 */
class Array {
private:
  unsigned int size;           /// Size of the array.
  int *data;                   /// Pointer to the dynamically allocated array.
  static bool firstTime;       /// Flag to track if random seed way already set.
  static int totalNumElements; /// Total number of elements in every array.

public:
  /**
   * @brief Getter for the size of the array.
   * @return The size of the array.
   */
  int getSize() const;

  /**
   * @brief Static method to check if the random seed has already been randomly
   * set. Used for ! shuffle operator.
   * @return True if it's the first time; otherwise, false.
   */
  static bool isFirstTime();

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
   * @brief Parameterized constructor that initializes the array with a given
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
   * @brief Equality operator for comparing arrays.
   * @param other The Array to be compared.
   * @return True if arrays are equal; otherwise, false.
   */
  bool operator==(const Array &) const;

  /**
   * @brief Inequality operator for comparing arrays.
   * @param other The Array to be compared.
   * @return True if arrays are not equal; otherwise, false.
   */
  bool operator!=(const Array &) const;

  /**
   * @brief Less than or equal to operator for comparing arrays.
   * @param other The Array to be compared.
   * @return True if the first element of the current array is less than or
   * equal to the other's.
   */
  bool operator<=(const Array &) const;

  /**
   * @brief Greater than or equal to operator for comparing arrays.
   * @param other The Array to be compared.
   * @return True if the first element of the current array is greater than or
   * equal to the other's.
   */
  bool operator>=(const Array &) const;

  /**
   * @brief Less than operator for comparing arrays.
   * @param other The Array to be compared.
   * @return True if the first element of the current array is less than the
   * other's.
   */
  bool operator<(const Array &) const;

  /**
   * @brief Greater than operator for comparing arrays.
   * @param other The Array to be compared.
   * @return True if the first element of the current array is greater than the
   * other's.
   */
  bool operator>(const Array &) const;

  /**
   * @brief Unary negation operator for shuffling array elements.
   * @return Reference to the modified Array object.
   */
  Array &operator!();

  /**
   * @brief Dereference operator for finding the smallest element in
   * the array.
   * @return The smallest element in the array.
   */
  int operator*() const;

  /**
   * @brief Addition assignment operator for concatenating arrays.
   * @param other The Array to be concatenated.
   */
  void operator+=(const Array &other);

  /**
   * @brief Pre-increment operator for incrementing all elements.
   * @return Reference to the modified Array object.
   */
  Array &operator++();

  /**
   * @brief Post-increment operator for incrementing all elements.
   * @param unused Dummy parameter to differentiate from pre-increment.
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
   * @param unused Dummy parameter to differentiate from pre-decrement.
   * @return Copy of the original Array object before decrement.
   */
  Array operator--(int);

  /**
   * @brief Friend function to for the output stream operator for printing
   * the array.
   * @param out The output stream.
   * @param arr The Array object to be printed.
   * @return Reference to the output stream.
   */
  friend std::ostream &operator<<(std::ostream &, const Array &);

  /**
   * @brief Friend function for the input stream operator for reading
   * values into the array.
   * @param in The input stream.
   * @param arr The Array object to read values into.
   * @return Reference to the input stream.
   */
  friend std::istream &operator>>(std::istream &, Array &);
};
