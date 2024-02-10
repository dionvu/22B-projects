#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

class Snack {
private:
  string name;
  double price;
  int stock;
  int numSold;

public:
  ~Snack() {
    cout << name << ": \n"
         << "    " << stock << " in stock" << '\n'
         << "    " << numSold << " sold for a profit of $" << price * numSold
         << '\n';

    cout << '\n';
  }
  Snack() {
    this->name = "", this->price = 0, this->stock = 0, this->numSold = 0;
  }

  Snack(string name, double price, int stock) {
    this->name = name;
    this->price = price;
    this->stock = stock;
    numSold = 0;
  }

  string getName() const;
  void mutName(string);

  double getPrice() const;
  void mutPrice(double);

  int getStock() const;
  void mutStock(int);

  int getNumSold() const;
  void mutNumSold(int);

  bool buyItem(double &);
};

void displayVendingMachine(const Snack machine[], int numItems) {
  cout << fixed << setprecision(2) << '\n';

  cout << setw(15) << left << "Item #" << setw(15) << left << "Item Name"
       << setw(15) << left << "Price" << setw(15) << left << "# in-stock";
  cout << '\n';

  for (int i = 0; i < 4 * 15; i++)
    cout << "-";
  cout << '\n';

  for (int i = 0; i < numItems; i++) {
    cout << setw(15) << left << i + 1 << setw(15) << left
         << machine[i].getName() << setw(15) << left << machine[i].getPrice()
         << setw(15) << left << machine[i].getStock();
    cout << '\n';
  }

  cout << '\n';
}

int getQuarters() {
  int quarters;
  do {
    cout << "Input how many quarters: ";
    cin >> quarters;
    if (quarters < 1)
      cout << "Invalid input, enter a value greater than 0...\n";
  } while (quarters < 1);

  return quarters;
}

void userBuyItem(Snack machine[], int numItems) {
  double amount;
  int choice;

  displayVendingMachine(machine, numItems);
  amount = getQuarters() * 0.25;

  cout << "Amount entered: $" << amount << "\n\n";

  do {
    cout << "Enter the item number to make a purchase: ";
    cin >> choice;
    if (choice < 1 || choice > numItems)
      cout << "Invalid input, enter a value between 1 and " << numItems << '\n';
  } while (choice < 1 || choice > numItems);

  if (machine[choice - 1].buyItem(amount)) {
    if (amount != 0)
      cout << "$" << amount << " returned below.\n";
  }
}

bool promptToContine() {
  string choice;

  do {
    cout << "Buy more items? (Y / N): ";
    cin >> choice;

    if (choice != "Y" && choice != "y" && choice != "N" && choice != "n")
      cout << "Invalid choice.\n";

  } while (choice != "Y" && choice != "y" && choice != "N" && choice != "n");

  if (choice == "Y" || choice == "y")
    return true;

  return false;
}

int main() {
  const int NUM_ITEMS = 3;

  int quarters;

  Snack machine[NUM_ITEMS] = {Snack(), Snack("candy", 1.25, 5),
                              Snack("Soda", 1.00, 2)};

  machine[0].mutName("chips");
  machine[0].mutPrice(1.75);
  machine[0].mutStock(3);

  do {
    userBuyItem(machine, NUM_ITEMS);
  } while (promptToContine());
}

string Snack::getName() const { return name; }
void Snack::mutName(string newName) { name = newName; }

double Snack::getPrice() const { return price; }
void Snack::mutPrice(double newPrice) { price = newPrice; }

int Snack::getStock() const { return stock; }
void Snack::mutStock(int newStock) { stock = newStock; }

int Snack::getNumSold() const { return numSold; }
void Snack::mutNumSold(int newNumSold) { numSold = newNumSold; }

bool Snack::buyItem(double &moneyEntered) {
  if (stock <= 0) {
    cout << "Sorry! We are out of " << name << ".\n";
    return false;
  }
  if (moneyEntered < price) {
    cout << "Not enough money! Broke!\n";
    return false;
  }
  moneyEntered -= price;
  numSold++;
  stock--;
  cout << "Item has been depensed. Enjoy!\n";
  return true;
}
