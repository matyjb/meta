#include <iostream>
#include <typeinfo>
#include <typeindex>

#include "Typelist.h"
#include "TypelistMacros.h"

class base {};
class derived : public base {};
class mostderived2 : public base {};
class base2 {};
class mostderived : public derived, public base2 {};
class mostderived3 : public base2 {};

int main() {

	std::cout << "Najbardziej pochodny element" << "\n";
	std::cout << typeid(Loki::TL::MostDerived<LOKI_TYPELIST_1(mostderived), base>::Result).name() << ", ";
	std::cout << "\n";
	std::cout << typeid(Loki::TL::MostDerived<LOKI_TYPELIST_2(mostderived,mostderived2), base>::Result).name() << ", ";
	std::cout << "\n";
	std::cout << typeid(Loki::TL::MostDerived<LOKI_TYPELIST_2(mostderived,mostderived2), derived>::Result).name() << ", ";
	std::cout << "\n";
	std::cout << typeid(Loki::TL::MostDerived<LOKI_TYPELIST_1(mostderived3), derived>::Result).name() << ", ";
	std::cout << "\n";

	// std::cout << typeid(MostDerived<ExampleType6, mostderived>::Result).name() << ", ";
	std::cout << "\n";

	std::cout << "Sortowanie od najbardziej zagniezdzonych klas" << "\n";
	// std::cout << Loki::TL::DerivedToFront<LOKI_TYPELIST_6(mostderived,mostderived2,base,base2,mostderived3,derived)>::Result << "\n";
  std::cout << typeid(Loki::TL::TypeAt<Loki::TL::DerivedToFront<LOKI_TYPELIST_7(mostderived,mostderived2,base,base2,mostderived3,derived, derived)>::Result, 0>::Result).name() << ", ";
  std::cout << typeid(Loki::TL::TypeAt<Loki::TL::DerivedToFront<LOKI_TYPELIST_7(mostderived,mostderived2,base,base2,mostderived3,derived, derived)>::Result, 1>::Result).name() << ", ";
  std::cout << typeid(Loki::TL::TypeAt<Loki::TL::DerivedToFront<LOKI_TYPELIST_7(mostderived,mostderived2,base,base2,mostderived3,derived, derived)>::Result, 2>::Result).name() << ", ";
  std::cout << typeid(Loki::TL::TypeAt<Loki::TL::DerivedToFront<LOKI_TYPELIST_7(mostderived,mostderived2,base,base2,mostderived3,derived, derived)>::Result, 3>::Result).name() << ", ";
  std::cout << typeid(Loki::TL::TypeAt<Loki::TL::DerivedToFront<LOKI_TYPELIST_7(mostderived,mostderived2,base,base2,mostderived3,derived, derived)>::Result, 4>::Result).name() << ", ";
  std::cout << typeid(Loki::TL::TypeAt<Loki::TL::DerivedToFront<LOKI_TYPELIST_7(mostderived,mostderived2,base,base2,mostderived3,derived, derived)>::Result, 5>::Result).name() << ", ";
  std::cout << typeid(Loki::TL::TypeAt<Loki::TL::DerivedToFront<LOKI_TYPELIST_7(mostderived,mostderived2,base,base2,mostderived3,derived, derived)>::Result, 6>::Result).name() << ", ";
	// std::cout << "\n";

	return 0;
}
