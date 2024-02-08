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
  Snack() { name = "", price = 0, stock = 0, numSold = 0; }

  Snack(string name, double price, int stock) {
    this->name = name;
    this->price = price;
    this->stock = stock;
    numSold = 0;
  }

  ~Snack() { cout << "Print stuff!"; }

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

bool Snack::buyItem(double &moneyEntered) {
  if (moneyEntered >= price) {
    moneyEntered -= price;
    numSold++;
    stock--;

    cout << "Item has been depensed. Enjoy!\n";
    return true;
  } else {
    cout << "Not enough money! Broke!\n";
    return false;
  }
}

int main() {
  Snack bar("bar", 1.0, 1);
  cout << bar.getName();
}

string Snack::getName() const { return name; }
void Snack::mutName(string newName) { name = newName; }

double Snack::getPrice() const { return price; }
void Snack::mutPrice(double newPrice) { price = newPrice; }

int Snack::getStock() const { return stock; }
void Snack::mutStock(int newStock) { stock = newStock; }

int Snack::getNumSold() const { return numSold; }
void Snack::mutNumSold(int newNumSold) { numSold = newNumSold; }
