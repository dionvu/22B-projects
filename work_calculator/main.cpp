#include <cmath>
#include <fstream>
#include <iostream>

using namespace std;

bool readHeightsFromFile(int heightsArr[], const int SIZE) {
  ifstream file("heights.txt");

  if (!file) {
    cout << "File not opened properly.\n";
    return false;
  }

  for (int i = 0; i < SIZE; i++)
    file >> heightsArr[i];

  file.close();

  return true;
}

double calcWork(int lowerBound, int upperBound) {
  double lower = (40 * pow(lowerBound, 3) / 3) + (10 * pow(lowerBound, 2) / 2) +
                 (300 * lowerBound);
  double upper = (40 * pow(upperBound, 3) / 3) + (10 * pow(upperBound, 2) / 2) +
                 (300 * upperBound);
  return upper - lower;
}

void writeResultsToFile(int heightsArr[], int workArr[], const int SIZE) {
  ofstream file("work_results.txt");
  for (int i = 0; i < SIZE; i++) {
    file << heightsArr[i] << " " << workArr[i] << '\n';
  }
  file.close();
}

int main() {
  const int SIZE = 5;
  int heights[SIZE];
  int work[SIZE];

  readHeightsFromFile(heights, SIZE);

  for (int i = 0; i < SIZE; i++) {
    work[i] = calcWork(heights[i], 50);
  }

  writeResultsToFile(heights, work, SIZE);
}
