/**
 * @file main.cpp
 * @brief A program demonstrating the usage of a singly linked list with
 * templates. The program stores a list of composers and allows the user to
 * search for composer names and remove them from the list.
 * @date 2024 March 14
 */

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

  if (!file) {
    cout << "ERROR: File not opened properly.\n";
    return 1;
  }

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
      cout << "Enter name of composer to remove: \n";
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

/** Sample Run:
 * Claudio Monteverdi - 1643
 * Henry Purcell - 1695
 * Antonio Vivaldi - 1741
 * Johann Sebastian Bach - 1750
 * George Frideric Handel - 1759
 * Wolfgang Amadeus Mozart - 1791
 * Joseph Haydn - 1809
 * Ludwig van Beethoven - 1827
 * Franz Schubert - 1828
 * Felix Mendelssohn - 1847
 * Frederic Chopin - 1849
 * Robert Schumann - 1856
 * Hector Berlioz - 1869
 * Richard Wagner - 1883
 * Franz Liszt - 1886
 * Pyotr Ilyich Tchaikovsky - 1893
 * Johannes Brahms - 1897
 * Giuseppe Verdi - 1901
 * Antonin Dvorak - 1904
 * Edvard Grieg - 1907
 * Gustav Mahler - 1911
 * Claude Debussy - 1918
 * Camille Saint-Saens - 1921
 * Giacomo Puccini - 1924
 * George Gershwin - 1937
 * Maurice Ravel - 1937
 * Sergei Rachmaninoff - 1943
 * Bela Bartok - 1945
 * Arnold Schoenberg - 1951
 * Sergei Prokofiev - 1953
 * Igor Stravinsky - 1971
 * Dmitri Shostakovich - 1975
 * Leonard Bernstein - 1990
 * Aaron Copland - 1990
 *
 * Enter 's' to search, 'r' to remove, 'd' to display, or 'e' to exit:
 * v
 *
 *         Invalid input.
 *
 * Enter 's' to search, 'r' to remove, 'd' to display, or 'e' to exit:
 * s
 * Enter name of composer to search.
 * Aaron Copland
 *
 *         Composer found.
 *
 * Enter 's' to search, 'r' to remove, 'd' to display, or 'e' to exit:
 * r
 * Enter name of composer to remove:
 * Dmitri Shostakovich
 *
 *         Aaron Copland was removed from the list.
 *
 * Enter 's' to search, 'r' to remove, 'd' to display, or 'e' to exit:
 * d
 *
 * Claudio Monteverdi - 1643
 * Henry Purcell - 1695
 * Antonio Vivaldi - 1741
 * Johann Sebastian Bach - 1750
 * George Frideric Handel - 1759
 * Wolfgang Amadeus Mozart - 1791
 * Joseph Haydn - 1809
 * Ludwig van Beethoven - 1827
 * Franz Schubert - 1828
 * Felix Mendelssohn - 1847
 * Frederic Chopin - 1849
 * Robert Schumann - 1856
 * Hector Berlioz - 1869
 * Richard Wagner - 1883
 * Franz Liszt - 1886
 * Pyotr Ilyich Tchaikovsky - 1893
 * Johannes Brahms - 1897
 * Giuseppe Verdi - 1901
 * Antonin Dvorak - 1904
 * Edvard Grieg - 1907
 * Gustav Mahler - 1911
 * Claude Debussy - 1918
 * Camille Saint-Saens - 1921
 * Giacomo Puccini - 1924
 * George Gershwin - 1937
 * Maurice Ravel - 1937
 * Sergei Rachmaninoff - 1943
 * Bela Bartok - 1945
 * Arnold Schoenberg - 1951
 * Sergei Prokofiev - 1953
 * Igor Stravinsky - 1971
 * Leonard Bernstein - 1990
 * Aaron Copland - 1990
 *
 * Enter 's' to search, 'r' to remove, 'd' to display, or 'e' to exit:
 * s
 * Enter name of composer to search.
 * Bo Burnham
 *
 *         Composer not found.
 *
 * Enter 's' to search, 'r' to remove, 'd' to display, or 'e' to exit:
 * e
 *
 *         Exiting...
 */
