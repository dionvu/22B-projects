#include "LinkedList.h"

using namespace std;

int main() {
  LinkedList<int> *list = new LinkedList<int>();

  list->append(10);
  list->append(50);
  list->append(100);
  list->insert(40);
  list->remove(40);

  list->printList();

  int num;
  cout << "Enter a number to search: ";
  cin >> num;

  if (list->find(num)) {
    cout << num << " is found in the list." << endl;
  } else {
    cout << num << " is not found in the list." << endl;
  }

  delete list;
}
