/**
 * @brief Basic cli that simulates purchasing snacks at a vending machine.
 * Tracks the stock, amount sold, and transaction times of each item.
 *
 * @date 2024 Feb 15
 */
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

/**
 * @class Snack
 * @brief Represents a type of snack. Tracks amount sold, stock, and transaction
 * times (displayed when destructed).
 */
class Snack {
private:
  string name;
  double price;
  int stock;
  int numSold;
  string *transactionTimes;

public:
  Snack() {
    name = "", price = 0, stock = 0, numSold = 0;
    transactionTimes = nullptr;
  }

  Snack(string name, double price, int stock) {
    this->name = name;
    this->price = price;
    this->stock = stock;
    transactionTimes = nullptr;
    numSold = 0;
  }

  ~Snack() {
    cout << "\nClosing info for " << name << ": \n"
         << "    " << stock << " in stock" << '\n'
         << "    " << numSold << " sold for a profit of $" << price * numSold
         << '\n';

    cout << "    Transaction Times:\n";

    if (transactionTimes != nullptr) {
      cout << "        ";
      for (int i = 0; i < numSold; i++) {
        cout << transactionTimes[i] << " ";
      }
    }

    cout << '\n';

    delete[] transactionTimes;
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

  string getCurrentTime();
};

// Prototypes
void displayVendingMachine(const Snack[], int);
int getQuarters();
void userBuyItem(Snack[], int);
bool promptToContine();

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

/** Name getter, and setter */
string Snack::getName() const { return name; }
void Snack::mutName(string newName) { name = newName; }

/** Price getter, and setter */
double Snack::getPrice() const { return price; }
void Snack::mutPrice(double newPrice) { price = newPrice; }

/** Stock getter, and setter*/
int Snack::getStock() const { return stock; }
void Snack::mutStock(int newStock) {
  stock = newStock;
  transactionTimes = new string[stock];
}

/** Number sold getter, and setter */
int Snack::getNumSold() const { return numSold; }
void Snack::mutNumSold(int newNumSold) { numSold = newNumSold; }

/**
 * @brief Purchases the Snack, and decrements the stock if stock is not zero.
 *
 * @param moneyEntered Reference to the amount of money that user entered.
 *
 * @return True if can be purchased, false otherwise.
 */
bool Snack::buyItem(double &moneyEntered) {
  if (stock <= 0) {
    cout << "Sorry! We are out of " << name << ".\n";
    return false;
  }
  if (moneyEntered < price) {
    cout << "Not enough money! Broke!\n";
    return false;
  }

  if (transactionTimes == nullptr) {
    transactionTimes = new string[this->stock];
  }

  moneyEntered -= price;
  numSold++;
  transactionTimes[numSold - 1] = getCurrentTime();
  stock--;

  cout << "Item has been depensed. Enjoy!\n";
  return true;
}

/**
 * @brief Gets the current real life time.
 *
 * @returns Formatted string containing the time.
 */
string Snack::getCurrentTime() {
  time_t t = time(0);
  struct tm ts;
  char buff[10];

  ts = *localtime(&t);
  strftime(buff, sizeof(buff), "%X", &ts);
  return buff;
}

/**
 * @brief Displays a table with an entry for each snack in the machine.
 * Displaying, the item number, price, and stock.
 *
 * @param machine[] Array of Snacks.
 * @param numItems The length of machine[].
 */
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

/**
 * @brief Prompts, and validates input for how many quarters user wants to
 * insert.
 *
 * @return quarters The amount user inputted.
 */
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

/**
 * @brief Converts the anmount of quarters to dollars, and prompts & validates
 * user input for an Snack to purchase. Calculates the amount of change to
 * return.
 *
 * @param machine[] Array of Snacks.
 * @param numItems The length of machine[].
 */
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

/**
 * @brief Asks the user if they want to continue purchasing more snacks.
 * @param machine[] Array of Snacks.
 * @param numItems The length of machine[].
 */
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
