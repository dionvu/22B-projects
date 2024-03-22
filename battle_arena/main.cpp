/**
 * @file main.cpp
 * @date 2024 March 21
 * @brief A simple battle simulation program involving various creatures with
 * different abilities.
 */

#include <iostream>
#include <string>

using namespace std;

/**
 * @class Creature
 * @brief Represents a generic creature with strength and hitpoints attributes.
 */
class Creature {
protected:
  int strength;  /**< Strength of the creature */
  int hitpoints; /**< Hitpoints of the creature */

public:
  /**
   * @brief Default constructor for Creature.
   */
  Creature();

  /**
   * @brief Parameterized constructor for Creature.
   * @param newStrength The strength of the creature.
   * @param newHit The hitpoints of the creature.
   */
  Creature(int newStrength, int newHit);

  /**
   * @brief Virtual destructor for Creature.
   */
  virtual ~Creature() {}

  /**
   * @brief Virtual function to get the species of the creature.
   * @return A string representing the species of the creature.
   */
  virtual string getSpecies() const;

  /**
   * @brief Virtual function to calculate the damage inflicted by the creature.
   * @return The amount of damage inflicted.
   */
  virtual int getDamage() const;

  /**
   * @brief Getter function for the strength attribute.
   * @return The strength of the creature.
   */
  int getStrength() const;

  /**
   * @brief Setter function for the strength attribute.
   * @param newStrength The new strength value to set.
   */
  void setStrength(int);

  /**
   * @brief Getter function for the hitpoints attribute.
   * @return The hitpoints of the creature.
   */
  int getHitpoints() const;

  /**
   * @brief Setter function for the hitpoints attribute.
   * @param newHitpoints The new hitpoints value to set.
   */
  void setHitpoints(int);
};

Creature::Creature() : strength(10), hitpoints(10) {}

Creature::Creature(int newStrength, int newHit)
    : strength(newStrength), hitpoints(newHit) {}

string Creature::getSpecies() const { return "Unknown"; }

int Creature::getDamage() const {
  int damage = (rand() % strength) + 1;
  cout << getSpecies() << " attacks for " << damage << " points!" << '\n';
  return damage;
}

int Creature::getStrength() const { return strength; }

void Creature::setStrength(int newStrength) { strength = newStrength; }

int Creature::getHitpoints() const { return hitpoints; }

void Creature::setHitpoints(int newHitpoints) { hitpoints = newHitpoints; }

/**
 * @class Demon
 * @brief Represents a demon creature, inheriting from Creature.
 */
class Demon : public Creature {
public:
  /**
   * @brief Default constructor for Demon.
   */
  Demon();

  /**
   * @brief Parameterized constructor for Demon.
   * @param strength The strength of the demon.
   * @param hit The hitpoints of the demon.
   */
  Demon(int, int);

  /**
   * @brief Destructor for Demon.
   */
  ~Demon() override {}

  /**
   * @brief Override function to get the species of the demon.
   * @return A string representing the species of the demon.
   */
  string getSpecies() const override;

  /**
   * @brief Override function to calculate the damage inflicted by the demon.
   * @return The amount of damage inflicted.
   */
  int getDamage() const override;
};

Demon::Demon() : Creature(){};

Demon::Demon(int strength, int hitpoints) : Creature(strength, hitpoints) {}

string Demon::getSpecies() const { return "Demon"; }

int Demon::getDamage() const {
  int damage = Creature::getDamage();

  if ((rand() % 100) < 5) {
    cout << "Demonic attack inflicts 50 additional damage points!" << '\n';
    damage += 50;
  }
  return damage;
}

/**
 * @class Cyberdemon
 * @brief Represents a cybernetic demon, inheriting from Demon.
 */
class Cyberdemon : public Demon {
public:
  /**
   * @brief Default constructor for Cyberdemon.
   * Initializes a cyberdemon with default strength and hitpoints.
   */
  Cyberdemon();

  /**
   * @brief Parameterized constructor for Cyberdemon.
   * Initializes a cyberdemon with specified strength and hitpoints.
   * @param strength The strength of the cyberdemon.
   * @param hitpoints The hitpoints of the cyberdemon.
   */
  Cyberdemon(int, int);

  /**
   * @brief Override function to get the species of the cyberdemon.
   * @return A string representing the species of the cyberdemon, which is
   * "Cyberdemon".
   */
  string getSpecies() const override;

  /**
   * @brief Override function to calculate the damage inflicted by the
   * cyberdemon. Calls the getDamage function of its base class Demon.
   * @return The total amount of damage inflicted.
   */
  int getDamage() const override;
};

Cyberdemon::Cyberdemon(int strength, int hitpoints)
    : Demon(strength, hitpoints) {}

string Cyberdemon::getSpecies() const { return "Cyberdemon"; }

int Cyberdemon::getDamage() const {
  int damage = Demon::getDamage();
  return damage;
}

/**
 * @class Balrog
 * @brief Represents a Balrog creature, inheriting from Demon.
 */
class Balrog : public Demon {
public:
  /**
   * @brief Default constructor for Balrog.
   * Initializes a Balrog with default strength and hitpoints.
   */
  Balrog();

  /**
   * @brief Parameterized constructor for Balrog.
   * Initializes a Balrog with specified strength and hitpoints.
   * @param strength The strength of the Balrog.
   * @param hitpoints The hitpoints of the Balrog.
   */
  Balrog(int, int);

  /**
   * @brief Destructor for Balrog.
   * Provides cleanup for the Balrog class.
   */
  ~Balrog() override;

  /**
   * @brief Override function to get the species of the Balrog.
   * @return A string representing the species of the Balrog, which is "Balrog".
   */
  string getSpecies() const override;

  /**
   * @brief Override function to calculate the damage inflicted by the Balrog.
   * Balrogs have a chance to inflict additional damage and perform a speed
   * attack.
   * @return The total amount of damage inflicted.
   */
  int getDamage() const override;
};

Balrog::Balrog() : Demon() {}

Balrog::Balrog(int strength, int hitpoints) : Demon(strength, hitpoints) {}

Balrog::~Balrog() {}

string Balrog::getSpecies() const { return "Balrog"; }

int Balrog::getDamage() const {
  int damage = Demon::getDamage();
  int secondDamage;

  // Avoided calling getDamage() again in order to prevent user confusion due
  // to three attack messages when Balrog only attacks minimum twice.
  if ((rand() % 100) < 5) {
    cout << "Balrog's demonic attack inflicts 50 additional damage points!"
         << '\n';
    damage += 50;
  }

  secondDamage = (rand() % getStrength()) + 1;
  cout << "Balrog speed attack inflicted " << secondDamage
       << " additional damage points!" << '\n';

  damage += secondDamage;

  return damage;
}

/**
 * @class Elf
 * @brief Represents an Elf creature, inheriting from Creature.
 */
class Elf : public Creature {
public:
  /**
   * @brief Default constructor for Elf.
   * Initializes an Elf with default strength and hitpoints.
   */
  Elf();

  /**
   * @brief Parameterized constructor for Elf.
   * Initializes an Elf with specified strength and hitpoints.
   * @param strength The strength of the Elf.
   * @param hitpoints The hitpoints of the Elf.
   */
  Elf(int strength, int hitpoints);

  /**
   * @brief Destructor for Elf.
   * Provides cleanup for the Elf class.
   */
  ~Elf() override;

  /**
   * @brief Override function to get the species of the Elf.
   * @return A string representing the species of the Elf, which is "Elf".
   */
  string getSpecies() const override;

  /**
   * @brief Override function to calculate the damage inflicted by the Elf.
   * Elves have a chance to perform a magical attack, inflicting additional
   * damage.
   * @return The total amount of damage inflicted.
   */
  int getDamage() const override;
};

Elf::~Elf(){};

Elf::Elf() : Creature() {}

Elf::Elf(int strength, int hitpoints) : Creature(strength, hitpoints) {}

string Elf::getSpecies() const { return "Elf"; }

int Elf::getDamage() const {
  int damage = Creature::getDamage();

  if ((rand() % 10) == 0) {
    cout << "Magical attack inflicts " << damage << " additional damage points!"
         << '\n';
    damage *= 2;
  }
  return damage;
}

/**
 * @class Human
 * @brief Represents a Human creature, inheriting from Creature.
 */
class Human : public Creature {
public:
  /**
   * @brief Default constructor for Human.
   * Initializes a Human with default strength and hitpoints.
   */
  Human();

  /**
   * @brief Parameterized constructor for Human.
   * Initializes a Human with specified strength and hitpoints.
   * @param strength The strength of the Human.
   * @param hitpoints The hitpoints of the Human.
   */
  Human(int strength, int hitpoints);

  /**
   * @brief Destructor for Human.
   * Provides cleanup for the Human class.
   */
  ~Human() override;

  /**
   * @brief Override function to get the species of the Human.
   * @return A string representing the species of the Human, which is "Human".
   */
  string getSpecies() const override;

  /**
   * @brief Override function to calculate the damage inflicted by the Human.
   * Humans have no special abilities, so their damage calculation is
   * straightforward.
   * @return The total amount of damage inflicted.
   */
  int getDamage() const override;
};

Human::Human() : Creature() {}

Human::Human(int strength, int hitpoints) : Creature(strength, hitpoints) {}

Human::~Human() {}

string Human::getSpecies() const { return "Human"; }

int Human::getDamage() const {
  int damage = Creature::getDamage();
  return damage;
}

/**
 * @brief Simulates a battle between two creatures.
 *
 * This function repeatedly calculates damage inflicted by each creature
 * until one of them has no hit points left.
 *
 * @param creature1 The first creature participating in the battle.
 * @param creature2 The second creature participating in the battle.
 */
void battleArena(Creature &creature1, Creature &creature2) {
  int damage1; /**< Damage inflicted by creature1 */
  int damage2; /**< Damage inflicted by creature2 */

  // Continue battle until one creature loses all hitpoints
  while (creature1.getHitpoints() > 0 && creature2.getHitpoints() > 0) {
    // Calculate damage inflicted by each creature
    damage1 = creature1.getDamage();
    damage2 = creature2.getDamage();

    // Reduce hitpoints of the opposing creature based on damage inflicted
    creature2.setHitpoints(creature2.getHitpoints() - damage1);
    creature1.setHitpoints(creature1.getHitpoints() - damage2);
  }

  // Determine the winner based on hitpoints remaining
  if (creature1.getHitpoints() <= 0 && creature2.getHitpoints() <= 0)
    cout << "The battle is a tie!" << '\n';
  else if (creature1.getHitpoints() <= 0)
    cout << creature2.getSpecies() << " wins!" << '\n';
  else
    cout << creature1.getSpecies() << " wins!" << '\n';
}

int main() {
  srand(static_cast<int>(time(NULL)));

  Human bob(30, 10);
  bob.getDamage();
  bob.getHitpoints();
  cout << endl;

  Elf respen;
  respen.getDamage();
  respen.getHitpoints();
  cout << endl;

  Balrog valar(50, 50);
  valar.getDamage();
  valar.getHitpoints();
  cout << endl;

  Cyberdemon cerberus(30, 40);
  cerberus.getDamage();
  cerberus.getHitpoints();
  cout << endl;

  Elf aegnor(50, 200);
  Balrog morgoth(50, 120);
  cout << endl;

  battleArena(aegnor, morgoth);
}

/** Sample Run:
 * Human attacks for 8 points!
 *
 * Elf attacks for 5 points!
 *
 * Balrog attacks for 9 points!
 * Balrog speed attack inflicted 30 additional damage points!
 *
 * Cyberdemon attacks for 5 points!
 *
 *
 * Elf attacks for 23 points!
 * Balrog attacks for 1 points!
 * Balrog speed attack inflicted 37 additional damage points!
 * Elf attacks for 46 points!
 * Balrog attacks for 46 points!
 * Balrog speed attack inflicted 34 additional damage points!
 * Elf attacks for 8 points!
 * Balrog attacks for 7 points!
 * Balrog speed attack inflicted 7 additional damage points!
 * Elf attacks for 13 points!
 * Balrog attacks for 46 points!
 * Balrog speed attack inflicted 10 additional damage points!
 * Elf attacks for 23 points!
 * Magical attack inflicts 23 additional damage points!
 * Balrog attacks for 32 points!
 * Balrog speed attack inflicted 48 additional damage points!
 * The battle is a tie!
 */
