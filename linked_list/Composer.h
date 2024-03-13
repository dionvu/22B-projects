#include <string>

using namespace std;

class Composer {
private:
  string name;
  unsigned int yearPassed;

public:
  Composer();
  Composer(string, unsigned int);
};

inline Composer::Composer() : name(""), yearPassed(0){};

inline Composer::Composer(string name, unsigned int yearPassed)
    : name(name), yearPassed(yearPassed){};
