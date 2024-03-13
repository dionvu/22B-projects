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
};
