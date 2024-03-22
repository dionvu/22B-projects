#include "Array.h"

using namespace std;

int main() {
  Array arr1(5), arr2(10);
  for (int i = 0; i < arr1.getSize(); i++)
    arr1[i] = i;
  for (int i = 0; i < arr2.getSize(); i++)
    arr2[i] = i;
  cout << "arr1 contains: " << arr1;
  cout << "arr2 contains: " << arr2;
  Array arr3(arr1);
  cout << "arr3 contains: " << arr3 << endl;
  arr2 = arr2;
  cout << "arr2 contains: " << arr2;
  arr3 = arr2;
  cout << "arr3 contains: " << arr3 << endl;
  cout << boolalpha; // Display booleans as 'true' or 'false' instead of 1 or 0
  cout << "arr2 == arr3: " << (arr2 == arr3) << endl;
  cout << "arr1 == arr3: " << (arr1 == arr3) << endl;
  cout << "arr1 < arr3: " << (arr1 < arr3) << endl << endl;
  arr3[0] = 100;
  cout << "New arr3: " << arr3;
  cout << "arr2 == arr3: " << (arr2 == arr3) << endl;
  cout << "arr1 == arr3: " << (arr1 == arr3) << endl;
  cout << "arr1 < arr3: " << (arr1 < arr3) << endl << endl;
  arr1 += arr2;
  cout << "arr1 += arr2: " << arr1 << endl;
  cout << "!arr1: " << !arr1;
  cout << "*arr1: " << *arr1 << endl << endl;
  cout << "arr1++: " << arr1++;
  cout << "arr1 is: " << arr1 << endl;
  cout << "--arr1: " << --arr1;
  cout << "arr1 is: " << arr1 << endl;
  cout << "Total number of elements in all arrays: "
       << Array::getNumberOfElements() << endl
       << endl;

  cout << "arr1 is: " << arr1 << endl;
  cin >> arr1;
  cout << "arr1 is: " << arr1 << endl;

  return 0;
}

/** Output:
 * arr1 contains: 0 1 2 3 4
 * arr2 contains: 0 1 2 3 4 5 6 7 8 9
 * arr3 contains: 0 1 2 3 4
 *
 * arr2 contains: 0 1 2 3 4 5 6 7 8 9
 * arr3 contains: 0 1 2 3 4 5 6 7 8 9
 *
 * arr2 == arr3: true
 * arr1 == arr3: true
 * arr1 < arr3: false
 *
 * New arr3: 100 1 2 3 4 5 6 7 8 9
 * arr2 == arr3: false
 * arr1 == arr3: false
 * arr1 < arr3: true
 *
 * arr1 += arr2: 0 1 2 3 4 0 1 2 3 4 5 6 7 8 9
 *
 * !arr1: 6 9 3 5 1 8 1 7 4 2 0 3 0 2 4
 * *arr1: 0
 *
 * arr1++: 6 9 3 5 1 8 1 7 4 2 0 3 0 2 4
 * arr1 is: 7 10 4 6 2 9 2 8 5 3 1 4 1 3 5
 *
 * --arr1: 6 9 3 5 1 8 1 7 4 2 0 3 0 2 4
 * arr1 is: 6 9 3 5 1 8 1 7 4 2 0 3 0 2 4
 *
 * Total number of elements in all arrays: 35
 */
