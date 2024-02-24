/**
 * @brief Calculates the work dont on oil being pulled from the ground by an
 * extraction machine depending on different starting heights of the oil. The
 * force needed to lift an amount of oil is F(x) = 40x^2 + 10x +300. Integration
 * is used to calculate resulting work.
 *
 * @date 2024 Feb 14
 */

#include <cmath>
#include <fstream>
#include <iostream>

bool readHeightsFromFile(int[], int);
void insertionSortRecursive(int[], int);
double calcWork(int, int);
void writeResultsToFile(const int[], const int[], int);

int main() {
  const int SIZE = 5;
  const int UPPER_BOUND = 50;
  int heights[SIZE];
  int work[SIZE];

  if (!readHeightsFromFile(heights, SIZE)) {
    std::cout << "Error reading heights from the file";
    return 1;
  }

  insertionSortRecursive(heights, SIZE);

  for (int i = 0; i < SIZE; i++)
    work[i] = calcWork(heights[i], UPPER_BOUND);

  writeResultsToFile(heights, work, SIZE);

  return 0;
}

/**
 * @brief Used to sort the array of heights from lowerest to hightest.
 * @param arr[] The array to be sorted.
 * @param size The size of the array.
 */
void insertionSortRecursive(int arr[], int size) {
  if (size <= 1)
    return;

  insertionSortRecursive(arr, size - 1);

  int last = arr[size - 1];
  int cur = size - 2;

  while (cur >= 0 && arr[cur] > last) {
    arr[cur + 1] = arr[cur];
    cur--;
  }
  arr[cur + 1] = last;
}

/**
 * @brief Sends the results of integration (work) into a file with the
 * coresponding height values.
 * @param heightsArr[] The array to store the values read.
 * @param workArr[] The array of work values.
 * @param SIZE The size of both the height and work arrays.
 */
void writeResultsToFile(const int heightsArr[], const int workArr[], int SIZE) {
  std::ofstream file("work_results.txt");
  for (int i = 0; i < SIZE; i++)
    file << heightsArr[i] << " " << workArr[i] << '\n';
  file.close();
}

/**
 * @brief Integrates F(x) = 40x^2 + 10x +300, and calculates the work.
 * @param lowerBound The lower bound of integration.
 * @param upperBound The upper bound of integration.
 * @return Work.
 */
double calcWork(int lowerBound, int upperBound) {
  double lower = (40 * pow(lowerBound, 3) / 3) + (10 * pow(lowerBound, 2) / 2) +
                 (300 * lowerBound);
  double upper = (40 * pow(upperBound, 3) / 3) + (10 * pow(upperBound, 2) / 2) +
                 (300 * upperBound);
  return upper - lower;
}

/**
 * @brief Reads the height values that will be used for the lower bound of
 * integration.
 * @param heightsArr[] The array to store the values read.
 * @param SIZE The size of the array & how many values are in the file.
 * @return True if heights read properly, false otherwise.
 */
bool readHeightsFromFile(int heightsArr[], int SIZE) {
  std::ifstream file("heights.txt");

  if (!file) {
    std::cout << "File not opened properly.\n";
    return false;
  }

  for (int i = 0; i < SIZE; i++)
    file >> heightsArr[i];

  file.close();

  return true;
}

/** Sample results:
 *
 * -25 1906875
 * -10 1710000
 * 0 1694166
 * 3 1692861
 * 10 1677333
 */
