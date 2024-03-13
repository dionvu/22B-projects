#include "Composer.h"
#include "LinkedList.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  LinkedList<Composer> *list = new LinkedList<Composer>();

  ifstream file("composers.txt");

  string name;
  int year;

  while (getline(file, name, ',')) {
    file >> year;
    file.ignore();
    list->append(Composer(name, year));
  }

  list->printList();

  delete list;
}
