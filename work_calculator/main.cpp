#include <cmath>
#include <fstream>
#include <iostream>

using namespace std;

// Prototypes
bool readHeightsFromFile(int[], int);
double calcWork(int, int);
void writeResultsToFile(int[], int[], int);
void insertionSortRecursive(int[], int);

int main() {
  const int SIZE = 5;
  int heights[SIZE];
  int work[SIZE];

  readHeightsFromFile(heights, SIZE);

  insertionSortRecursive(heights, SIZE);

  for (int i = 0; i < SIZE; i++) {
    work[i] = calcWork(heights[i], 50);
  }

  writeResultsToFile(heights, work, SIZE);
}

void insertionSortRecursive(int arr[], int SIZE) {
  if (SIZE <= 1)
    return;

  insertionSortRecursive(arr, SIZE - 1);

  int last = arr[SIZE - 1];
  int cur = SIZE - 2;

  while (cur >= 0 && arr[cur] > last) {
    arr[cur + 1] = arr[cur];
    cur--;
  }
  arr[cur + 1] = last;
}

void writeResultsToFile(int heightsArr[], int workArr[], int SIZE) {
  ofstream file("work_results.txt");
  for (int i = 0; i < SIZE; i++) {
    file << heightsArr[i] << " " << workArr[i] << '\n';
  }
  file.close();
}

double calcWork(int lowerBound, int upperBound) {
  double lower = (40 * pow(lowerBound, 3) / 3) + (10 * pow(lowerBound, 2) / 2) +
                 (300 * lowerBound);
  double upper = (40 * pow(upperBound, 3) / 3) + (10 * pow(upperBound, 2) / 2) +
                 (300 * upperBound);
  return upper - lower;
}

bool readHeightsFromFile(int heightsArr[], int SIZE) {
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
