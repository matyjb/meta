#include "Visitor.hpp"
#include <iostream>
#include <vector>

class Dwarf;
class Hobbit;
class Elf;

class MiddleEarthCreatureVisitor : public Visitor<Dwarf, Hobbit, Elf>
{
};
class MiddleEarthCreature : public Visitable<MiddleEarthCreatureVisitor>
{
};

class Dwarf : public MiddleEarthCreature
{
	void accept(MiddleEarthCreatureVisitor& visitor)
	{
		visitor.visit(*this);
	}
};

class Hobbit : public MiddleEarthCreature
{
	void accept(MiddleEarthCreatureVisitor& visitor)
	{
		visitor.visit(*this);
	}
};

class Elf : public MiddleEarthCreature
{
	void accept(MiddleEarthCreatureVisitor& visitor)
	{
		visitor.visit(*this);
	}
};

//*****************************************************************
// The 'taking to Isengard' visitor.
//*****************************************************************
class TakingToIsengardVisitor : public MiddleEarthCreatureVisitor
{
public:
  void visit(Dwarf& dwarf)
  {
    std::cout << "Taking the dwarfs to Isengard\n";
  }

  void visit(Hobbit& hobbit)
  {
    std::cout << "Taking the hobbits to Isengard\n";
  }

  void visit(Elf& elf)
  {
    std::cout << "Taking the elves to Isengard\n";
  }
};

//*****************************************************************
// The 'serialise' visitor.
//*****************************************************************
class SerialiseVisitor : public MiddleEarthCreatureVisitor
{
public:
  void visit(Dwarf& dwarf)
  {
    std::cout << "Serialise the dwarfs\n";
  }

  void visit(Hobbit& hobbit)
  {
    std::cout << "Serialise the hobbits\n";
  }

  void visit(Elf& elf)
  {
    std::cout << "Serialise the elves\n";
  }
};

void apply(MiddleEarthCreatureVisitor& visitor, std::vector<MiddleEarthCreature*> middleearthcreature_list)
{
  for (std::vector<MiddleEarthCreature*>::size_type i = 0; i < middleearthcreature_list.size(); ++i)
  {
    // Send the visitor to the middle-earth creature.
	  middleearthcreature_list[i]->accept(visitor);
  }
}

int main() {
  Dwarf Gimli;
  Hobbit Bilbo;
  Elf Legolas;

  std::vector<MiddleEarthCreature*> middleearthcreatures;
  middleearthcreatures.push_back(&Gimli);
  middleearthcreatures.push_back(&Bilbo);
  middleearthcreatures.push_back(&Legolas);

  TakingToIsengardVisitor takingtoIsengardVisitor;
  SerialiseVisitor serialiseVisitor;

  apply(takingtoIsengardVisitor, middleearthcreatures);
  apply(serialiseVisitor, middleearthcreatures);

  return 0;
}
