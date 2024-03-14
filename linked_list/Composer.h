#include <cctype>
#include <string>

using namespace std;

class Composer {
private:
  string name;
  unsigned int yearPassed;

public:
  Composer();
  Composer(string, unsigned int);
  friend ostream &operator<<(ostream &, const Composer &);

  bool operator<(const Composer &other) const {
    return this->yearPassed < other.yearPassed;
  }

  bool operator>(const Composer &other) const {
    return this->yearPassed > other.yearPassed;
  }

  bool operator<=(const Composer &other) const {
    return this->yearPassed <= other.yearPassed;
  }

  bool operator>=(const Composer &other) const {
    return this->yearPassed >= other.yearPassed;
  }

  bool operator==(const Composer &other) const {
    return this->name == other.name;
  }
};
