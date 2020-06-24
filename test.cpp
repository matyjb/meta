#include <iostream>
#include <typeinfo>
#include <typeindex>

#include "typelist.hpp"
#include "loki/Typelist.h"
#include "loki/TypelistMacros.h"

class zwierze {};
class ssak : public zwierze {};
class ptak : public zwierze {};
class maszyna {};
class kon : public ssak {};
class czlowiek : public ssak {};
class pelikan : public ptak {};
class samolot : public ptak, public maszyna {};

using ET1 = TypeList<int>;
using ET1Loki = LOKI_TYPELIST_1(int);
using ET2 = TypeList<int, long int, char>;
using ET2Loki = LOKI_TYPELIST_3(int, long int, char);
using ET3 = TypeList<int, int, int, int>;
using ET3Loki = LOKI_TYPELIST_4(int, int, int, int);
using ET4 = TypeList<char, float, int, char>;
using ET4Loki = LOKI_TYPELIST_4(char, float, int, char);
using ET5 = TypeList<int, long int, int, bool, int, char>;
using ET5Loki = LOKI_TYPELIST_6(int, long int, int, bool, int, char);
using ET6 = TypeList<samolot, pelikan, ssak, kon, maszyna, czlowiek, zwierze, ptak>;
using ET6Loki = LOKI_TYPELIST_8(samolot, pelikan, ssak, kon, maszyna, czlowiek, zwierze, ptak);


int main() {
	std::cout << "##########################################" << "\n";
	std::cout << "### Usuwanie duplikatow (NoDuplicates) ###" << "\n";
	std::cout << "##########################################" << "\n";
	std::cout << "Testowa lista: ";
	std::cout << typeid(TypeAt<ET4, 0>::Result).name() << ", ";
	std::cout << typeid(TypeAt<ET4, 1>::Result).name() << ", ";
	std::cout << typeid(TypeAt<ET4, 2>::Result).name() << ", ";
	std::cout << typeid(TypeAt<ET4, 3>::Result).name() << "\n";
	std::cout << "NoDuplicates (size: " << NoDuplicates<ET4>::Result::size << "):\n";
	std::cout << typeid(TypeAt<NoDuplicates<ET4>::Result, 0>::Result).name() << ", ";
	std::cout << typeid(TypeAt<NoDuplicates<ET4>::Result, 1>::Result).name() << ", ";
	std::cout << typeid(TypeAt<NoDuplicates<ET4>::Result, 2>::Result).name() << "\n";
	std::cout << "Loki::TL::NoDuplicates (size: " << Loki::TL::Length<Loki::TL::NoDuplicates<ET4Loki>::Result>::value << "):\n";
	std::cout << typeid(Loki::TL::TypeAt<Loki::TL::NoDuplicates<ET4Loki>::Result, 0>::Result).name() << ", ";
	std::cout << typeid(Loki::TL::TypeAt<Loki::TL::NoDuplicates<ET4Loki>::Result, 1>::Result).name() << ", ";
	std::cout << typeid(Loki::TL::TypeAt<Loki::TL::NoDuplicates<ET4Loki>::Result, 2>::Result).name() << "\n";

	std::cout << "##########################################" << "\n";
	std::cout << "####### Odwracanie listy (Reverse) #######" << "\n";
	std::cout << "##########################################" << "\n";
	std::cout << "Testowa lista: ";
	std::cout << typeid(TypeAt<ET5, 0>::Result).name() << ", ";
	std::cout << typeid(TypeAt<ET5, 1>::Result).name() << ", ";
	std::cout << typeid(TypeAt<ET5, 2>::Result).name() << ", ";
	std::cout << typeid(TypeAt<ET5, 3>::Result).name() << ", ";
	std::cout << typeid(TypeAt<ET5, 4>::Result).name() << ", ";
	std::cout << typeid(TypeAt<ET5, 5>::Result).name() << "\n";
	std::cout << "Reverse (size: " << Reverse<ET5>::Result::size << "):\n";
	std::cout << typeid(TypeAt<Reverse<ET5>::Result, 0>::Result).name() << ", ";
	std::cout << typeid(TypeAt<Reverse<ET5>::Result, 1>::Result).name() << ", ";
	std::cout << typeid(TypeAt<Reverse<ET5>::Result, 2>::Result).name() << ", ";
	std::cout << typeid(TypeAt<Reverse<ET5>::Result, 3>::Result).name() << ", ";
	std::cout << typeid(TypeAt<Reverse<ET5>::Result, 4>::Result).name() << ", ";
	std::cout << typeid(TypeAt<Reverse<ET5>::Result, 5>::Result).name() << "\n";
	std::cout << "Loki::TL::Reverse (size: " << Loki::TL::Length<Loki::TL::Reverse<ET5Loki>::Result>::value << "):\n";
	std::cout << typeid(Loki::TL::TypeAt<Loki::TL::Reverse<ET5Loki>::Result, 0>::Result).name() << ", ";
	std::cout << typeid(Loki::TL::TypeAt<Loki::TL::Reverse<ET5Loki>::Result, 1>::Result).name() << ", ";
	std::cout << typeid(Loki::TL::TypeAt<Loki::TL::Reverse<ET5Loki>::Result, 2>::Result).name() << ", ";
	std::cout << typeid(Loki::TL::TypeAt<Loki::TL::Reverse<ET5Loki>::Result, 3>::Result).name() << ", ";
	std::cout << typeid(Loki::TL::TypeAt<Loki::TL::Reverse<ET5Loki>::Result, 4>::Result).name() << ", ";
	std::cout << typeid(Loki::TL::TypeAt<Loki::TL::Reverse<ET5Loki>::Result, 5>::Result).name() << "\n";

	std::cout << "##########################################" << "\n";
	std::cout << "### Najbardziej pochodny (MostDerived) ###" << "\n";
	std::cout << "##########################################" << "\n";
	std::cout << "Testowa lista: ";
	std::cout << typeid(TypeAt<ET6, 0>::Result).name() << ", ";
	std::cout << typeid(TypeAt<ET6, 1>::Result).name() << ", ";
	std::cout << typeid(TypeAt<ET6, 2>::Result).name() << ", ";
	std::cout << typeid(TypeAt<ET6, 3>::Result).name() << ", ";
	std::cout << typeid(TypeAt<ET6, 4>::Result).name() << ", ";
	std::cout << typeid(TypeAt<ET6, 5>::Result).name() << "\n";
	std::cout << "(schemat dziedziczenia klas dostepny w pliku png)\n";
	std::cout << "MostDerived<ET6, samolot>: " << typeid(MostDerived<ET6, samolot>::Result).name() << "\n";
	std::cout << "Loki::TL::MostDerived<ET6, samolot>: " << typeid(Loki::TL::MostDerived<ET6Loki, samolot>::Result).name() << "\n";
	std::cout << "MostDerived<ET6, czlowiek>: " << typeid(MostDerived<ET6, czlowiek>::Result).name() << "\n";
	std::cout << "Loki::TL::MostDerived<ET6, czlowiek>: " << typeid(Loki::TL::MostDerived<ET6Loki, czlowiek>::Result).name() << "\n";
	std::cout << "MostDerived<ET6, zwierze>: " << typeid(MostDerived<ET6, zwierze>::Result).name() << "\n";
	std::cout << "Loki::TL::MostDerived<ET6, zwierze>: " << typeid(Loki::TL::MostDerived<ET6Loki, zwierze>::Result).name() << "\n";

	std::cout << "##########################################" << "\n";
	std::cout << "############# DerivedToFront #############" << "\n";
	std::cout << "##########################################" << "\n";
	std::cout << "Testowa lista: ";
	std::cout << typeid(TypeAt<ET6, 0>::Result).name() << ", ";
	std::cout << typeid(TypeAt<ET6, 1>::Result).name() << ", ";
	std::cout << typeid(TypeAt<ET6, 2>::Result).name() << ", ";
	std::cout << typeid(TypeAt<ET6, 3>::Result).name() << ", ";
	std::cout << typeid(TypeAt<ET6, 4>::Result).name() << ", ";
	std::cout << typeid(TypeAt<ET6, 5>::Result).name() << "\n";
	std::cout << "DerivedToFront (size: " << DerivedToFront<ET6>::Result::size << "):\n";
	std::cout << typeid(TypeAt<DerivedToFront<ET6>::Result, 0>::Result).name() << ", ";
	std::cout << typeid(TypeAt<DerivedToFront<ET6>::Result, 1>::Result).name() << ", ";
	std::cout << typeid(TypeAt<DerivedToFront<ET6>::Result, 2>::Result).name() << ", ";
	std::cout << typeid(TypeAt<DerivedToFront<ET6>::Result, 3>::Result).name() << ", ";
	std::cout << typeid(TypeAt<DerivedToFront<ET6>::Result, 4>::Result).name() << ", ";
	std::cout << typeid(TypeAt<DerivedToFront<ET6>::Result, 5>::Result).name() << "\n";
	std::cout << "Loki::TL::DerivedToFront (size: " << Loki::TL::Length<Loki::TL::DerivedToFront<ET6Loki>::Result>::value << "):\n";
	std::cout << typeid(Loki::TL::TypeAt<Loki::TL::DerivedToFront<ET6Loki>::Result, 0>::Result).name() << ", ";
	std::cout << typeid(Loki::TL::TypeAt<Loki::TL::DerivedToFront<ET6Loki>::Result, 1>::Result).name() << ", ";
	std::cout << typeid(Loki::TL::TypeAt<Loki::TL::DerivedToFront<ET6Loki>::Result, 2>::Result).name() << ", ";
	std::cout << typeid(Loki::TL::TypeAt<Loki::TL::DerivedToFront<ET6Loki>::Result, 3>::Result).name() << ", ";
	std::cout << typeid(Loki::TL::TypeAt<Loki::TL::DerivedToFront<ET6Loki>::Result, 4>::Result).name() << ", ";
	std::cout << typeid(Loki::TL::TypeAt<Loki::TL::DerivedToFront<ET6Loki>::Result, 5>::Result).name() << "\n";
	
	return 0;
}
