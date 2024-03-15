/**
 * @file Composer.h
 * @brief Represents a Composer and their year of death.
 */

#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Represents a composer with a name and the year they passed away.
 */
class Composer {
private:
  string name;             ///< The name of the composer.
  unsigned int yearPassed; ///< The year the composer passed away.

public:
  /**
   * @brief Default constructor.
   * Initializes the name to an empty string and the year passed to 0.
   */
  Composer();

  /**
   * @brief Constructor with parameters.
   *
   * @param name The name of the composer.
   * @param year The year the composer passed away.
   */
  Composer(string name, unsigned int year);

  /**
   * @brief Overloaded stream insertion operator.
   * Outputs the name and year of the composer.
   *
   * @param os The output stream.
   * @param composer The composer to be output.
   * @return ostream& The output stream.
   */
  friend ostream &operator<<(ostream &os, const Composer &composer);

  /**
   * @brief Less than comparison operator.
   * Compares composers based on their names.
   *
   * @param other The other composer to compare with.
   * @return true If this composer's name is less than the other composer's
   * name.
   * @return false Otherwise.
   */
  bool operator<(const Composer &other) const;

  /**
   * @brief Greater than comparison operator.
   * Compares composers based on their names.
   *
   * @param other The other composer to compare with.
   * @return true If this composer's name is greater than the other composer's
   * name.
   * @return false Otherwise.
   */
  bool operator>(const Composer &other) const;

  /**
   * @brief Less than or equal to comparison operator.
   * Compares composers based on their names.
   *
   * @param other The other composer to compare with.
   * @return true If this composer's name is less than or equal to the other
   * composer's name.
   * @return false Otherwise.
   */
  bool operator<=(const Composer &other) const;

  /**
   * @brief Greater than or equal to comparison operator.
   * Compares composers based on their names.
   *
   * @param other The other composer to compare with.
   * @return true If this composer's name is greater than or equal to the other
   * composer's name.
   * @return false Otherwise.
   */
  bool operator>=(const Composer &other) const;

  /**
   * @brief Equality comparison operator.
   * Compares composers based on their names.
   *
   * @param other The other composer to compare with.
   * @return true If this composer's name is equal to the other composer's name.
   * @return false Otherwise.
   */
  bool operator==(const Composer &other) const;
};
