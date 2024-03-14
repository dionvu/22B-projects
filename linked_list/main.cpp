#include "Composer.h"
#include "LinkedList.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  char input;
  string name;
  string inputName;
  unsigned int year;

  LinkedList<Composer> *list = new LinkedList<Composer>();

  ifstream file("composers.txt");


  while (getline(file, name, ',')) {
    file >> year;
    file.ignore();
    list->insert(Composer(name, year));
  }

  list->printList();

  do {
    cout << "\nEnter 's' to search, 'r' to remove, 'd' to display, or 'e' to "
            "exit: \n";
    cin >> input;

    switch (input) {
    case 's':
    case 'S':
      cout << "Enter name of composer to search.\n";
      cin.ignore();
      getline(cin, inputName);

      if (list->find(Composer(inputName, 0))) {
        cout << "\n\t"
             << "Composer found.\n";
      } else
        cout << "\n\t"
             << "Composer not found.\n";

      break;
    case 'r':
    case 'R':
      cout << "Enter name of composer to remove: ";
      cin.ignore();
      getline(cin, inputName);

      if (list->remove(Composer(inputName, 0))) {
        cout << "\n\t" << inputName << " was removed from the list.\n";
      } else
        cout << "\n\t" << inputName << " was not in the list.\n";

      break;
    case 'd':
    case 'D':
      cout << '\n';
      list->printList();
      break;
    case 'e':
    case 'E':
      cout << "\n\t"
           << "Exiting...\n";
      break;
    default:
      cout << "\n\t"
           << "Invalid input.\n";
      break;
    }

  } while (input != 'e' && input != 'E');

  delete list;

  return 0;
}
