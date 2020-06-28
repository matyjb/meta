#include <iostream>
#include <typeinfo>
#include <typeindex>

#include "Typelist.hpp"
#include "TypelistToStr.hpp"
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
using ET3 = TypeList<int, int, int, int, char>;
using ET3Loki = LOKI_TYPELIST_5(int, int, int, int, char);
using ET4 = TypeList<char, float, int, char>;
using ET4Loki = LOKI_TYPELIST_4(char, float, int, char);
using ET5 = TypeList<int, long int, int, bool, int, char, bool>;
using ET5Loki = LOKI_TYPELIST_7(int, long int, int, bool, int, char, bool);
using ET6 = TypeList<samolot, pelikan, ssak, kon, maszyna, czlowiek, zwierze, ptak>;
using ET6Loki = LOKI_TYPELIST_8(samolot, pelikan, ssak, kon, maszyna, czlowiek, zwierze, ptak);

int main() {
	std::cout << "##########################################" << std::endl;
	std::cout << "############ Listowanie Testy ############" << std::endl;
	std::cout << "##########################################" << std::endl;
	std::cout << "Testowa lista (ET1 - size="<< ET1::size <<"): ";
	std::cout << typeid(TypeAt<ET1,0>::Result).name() << std::endl;
	std::cout << "TypeListToStr:       " << TypeListToStr<ET1>::value << std::endl;
	std::cout << "TypeListToStrLoki:   " << TypeListToStrLoki<ET1Loki>::value << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Testowa lista (ET2 - size="<< ET2::size <<"): ";
	std::cout << typeid(TypeAt<ET2,0>::Result).name() << ", ";
	std::cout << typeid(TypeAt<ET2,1>::Result).name() << ", ";
	std::cout << typeid(TypeAt<ET2,2>::Result).name() << std::endl;
	std::cout << "TypeListToStr:       " << TypeListToStr<ET2>::value << std::endl;
	std::cout << "TypeListToStrLoki:   " << TypeListToStrLoki<ET2Loki>::value << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Testowa lista (ET3 - size="<< ET3::size <<"): ";
	std::cout << typeid(TypeAt<ET3,0>::Result).name() << ", ";
	std::cout << typeid(TypeAt<ET3,1>::Result).name() << ", ";
	std::cout << typeid(TypeAt<ET3,2>::Result).name() << ", ";
	std::cout << typeid(TypeAt<ET3,3>::Result).name() << ", ";
	std::cout << typeid(TypeAt<ET3,4>::Result).name() << std::endl;
	std::cout << "TypeListToStr:       " << TypeListToStr<ET3>::value << std::endl;
	std::cout << "TypeListToStrLoki:   " << TypeListToStrLoki<ET3Loki>::value << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Testowa lista (ET4 - size="<< ET4::size <<"): ";
	std::cout << typeid(TypeAt<ET4,0>::Result).name() << ", ";
	std::cout << typeid(TypeAt<ET4,1>::Result).name() << ", ";
	std::cout << typeid(TypeAt<ET4,2>::Result).name() << ", ";
	std::cout << typeid(TypeAt<ET4,3>::Result).name() << std::endl;
	std::cout << "TypeListToStr:       " << TypeListToStr<ET4>::value << std::endl;
	std::cout << "TypeListToStrLoki:   " << TypeListToStrLoki<ET4Loki>::value << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Testowa lista (ET5 - size="<< ET5::size <<"): ";
	std::cout << typeid(TypeAt<ET5,0>::Result).name() << ", ";
	std::cout << typeid(TypeAt<ET5,1>::Result).name() << ", ";
	std::cout << typeid(TypeAt<ET5,2>::Result).name() << ", ";
	std::cout << typeid(TypeAt<ET5,3>::Result).name() << ", ";
	std::cout << typeid(TypeAt<ET5,4>::Result).name() << ", ";
	std::cout << typeid(TypeAt<ET5,5>::Result).name() << ", ";
	std::cout << typeid(TypeAt<ET5,6>::Result).name() << std::endl;
	std::cout << "TypeListToStr:       " << TypeListToStr<ET5>::value << std::endl;
	std::cout << "TypeListToStrLoki:   " << TypeListToStrLoki<ET5Loki>::value << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Testowa lista (ET6 - size="<< ET6::size <<"): ";
	std::cout << typeid(TypeAt<ET6,0>::Result).name() << ", ";
	std::cout << typeid(TypeAt<ET6,1>::Result).name() << ", ";
	std::cout << typeid(TypeAt<ET6,2>::Result).name() << ", ";
	std::cout << typeid(TypeAt<ET6,3>::Result).name() << ", ";
	std::cout << typeid(TypeAt<ET6,4>::Result).name() << ", ";
	std::cout << typeid(TypeAt<ET6,5>::Result).name() << ", ";
	std::cout << typeid(TypeAt<ET6,6>::Result).name() << ", ";
	std::cout << typeid(TypeAt<ET6,7>::Result).name() << std::endl;
	std::cout << "TypeListToStr:       " << TypeListToStr<ET6>::value << std::endl;
	std::cout << "TypeListToStrLoki:   " << TypeListToStrLoki<ET6Loki>::value << std::endl;

	std::cout << "##########################################" << std::endl;
	std::cout << "### Usuwanie duplikatow (NoDuplicates) ###" << std::endl;
	std::cout << "##########################################" << std::endl;
	std::cout << "Testowa lista (ET1): ";
	std::cout << TypeListToStr<ET1>::value << std::endl;
	std::cout << "NoDuplicates (size: " << NoDuplicates<ET1>::Result::size << "):" << std::endl;
	std::cout << TypeListToStr<NoDuplicates<ET1>::Result>::value << std::endl;
	std::cout << "Loki::TL::NoDuplicates (size: " << Loki::TL::Length<Loki::TL::NoDuplicates<ET1Loki>::Result>::value << "):" << std::endl;
	std::cout << TypeListToStrLoki<Loki::TL::NoDuplicates<ET1Loki>::Result>::value << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Testowa lista (ET2): ";
	std::cout << TypeListToStr<ET2>::value << std::endl;
	std::cout << "NoDuplicates (size: " << NoDuplicates<ET2>::Result::size << "):" << std::endl;
	std::cout << TypeListToStr<NoDuplicates<ET2>::Result>::value << std::endl;
	std::cout << "Loki::TL::NoDuplicates (size: " << Loki::TL::Length<Loki::TL::NoDuplicates<ET2Loki>::Result>::value << "):" << std::endl;
	std::cout << TypeListToStrLoki<Loki::TL::NoDuplicates<ET2Loki>::Result>::value << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Testowa lista (ET3): ";
	std::cout << TypeListToStr<ET3>::value << std::endl;
	std::cout << "NoDuplicates (size: " << NoDuplicates<ET3>::Result::size << "):" << std::endl;
	std::cout << TypeListToStr<NoDuplicates<ET3>::Result>::value << std::endl;
	std::cout << "Loki::TL::NoDuplicates (size: " << Loki::TL::Length<Loki::TL::NoDuplicates<ET3Loki>::Result>::value << "):" << std::endl;
	std::cout << TypeListToStrLoki<Loki::TL::NoDuplicates<ET3Loki>::Result>::value << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Testowa lista (ET4): ";
	std::cout << TypeListToStr<ET4>::value << std::endl;
	std::cout << "NoDuplicates (size: " << NoDuplicates<ET4>::Result::size << "):" << std::endl;
	std::cout << TypeListToStr<NoDuplicates<ET4>::Result>::value << std::endl;
	std::cout << "Loki::TL::NoDuplicates (size: " << Loki::TL::Length<Loki::TL::NoDuplicates<ET4Loki>::Result>::value << "):" << std::endl;
	std::cout << TypeListToStrLoki<Loki::TL::NoDuplicates<ET4Loki>::Result>::value << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Testowa lista (ET5): ";
	std::cout << TypeListToStr<ET5>::value << std::endl;
	std::cout << "NoDuplicates (size: " << NoDuplicates<ET5>::Result::size << "):" << std::endl;
	std::cout << TypeListToStr<NoDuplicates<ET5>::Result>::value << std::endl;
	std::cout << "Loki::TL::NoDuplicates (size: " << Loki::TL::Length<Loki::TL::NoDuplicates<ET5Loki>::Result>::value << "):" << std::endl;
	std::cout << TypeListToStrLoki<Loki::TL::NoDuplicates<ET5Loki>::Result>::value << std::endl;

	std::cout << "##########################################" << std::endl;
	std::cout << "####### Odwracanie listy (Reverse) #######" << std::endl;
	std::cout << "##########################################" << std::endl;
	std::cout << "Testowa lista (ET1): ";
	std::cout << TypeListToStr<ET1>::value << std::endl;
	std::cout << "Reverse (size: " << Reverse<ET1>::Result::size << "):" << std::endl;
	std::cout << TypeListToStr<Reverse<ET1>::Result>::value << std::endl;
	std::cout << "Loki::TL::Reverse (size: " << Loki::TL::Length<Loki::TL::Reverse<ET1Loki>::Result>::value << "):" << std::endl;
	std::cout << TypeListToStrLoki<Loki::TL::Reverse<ET1Loki>::Result>::value << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Testowa lista (ET2): ";
	std::cout << TypeListToStr<ET2>::value << std::endl;
	std::cout << "Reverse (size: " << Reverse<ET2>::Result::size << "):" << std::endl;
	std::cout << TypeListToStr<Reverse<ET2>::Result>::value << std::endl;
	std::cout << "Loki::TL::Reverse (size: " << Loki::TL::Length<Loki::TL::Reverse<ET2Loki>::Result>::value << "):" << std::endl;
	std::cout << TypeListToStrLoki<Loki::TL::Reverse<ET2Loki>::Result>::value << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Testowa lista (ET3): ";
	std::cout << TypeListToStr<ET3>::value << std::endl;
	std::cout << "Reverse (size: " << Reverse<ET3>::Result::size << "):" << std::endl;
	std::cout << TypeListToStr<Reverse<ET3>::Result>::value << std::endl;
	std::cout << "Loki::TL::Reverse (size: " << Loki::TL::Length<Loki::TL::Reverse<ET3Loki>::Result>::value << "):" << std::endl;
	std::cout << TypeListToStrLoki<Loki::TL::Reverse<ET3Loki>::Result>::value << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Testowa lista (ET4): ";
	std::cout << TypeListToStr<ET4>::value << std::endl;
	std::cout << "Reverse (size: " << Reverse<ET4>::Result::size << "):" << std::endl;
	std::cout << TypeListToStr<Reverse<ET4>::Result>::value << std::endl;
	std::cout << "Loki::TL::Reverse (size: " << Loki::TL::Length<Loki::TL::Reverse<ET4Loki>::Result>::value << "):" << std::endl;
	std::cout << TypeListToStrLoki<Loki::TL::Reverse<ET4Loki>::Result>::value << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Testowa lista (ET5): ";
	std::cout << TypeListToStr<ET5>::value << std::endl;
	std::cout << "Reverse (size: " << Reverse<ET5>::Result::size << "):" << std::endl;
	std::cout << TypeListToStr<Reverse<ET5>::Result>::value << std::endl;
	std::cout << "Loki::TL::Reverse (size: " << Loki::TL::Length<Loki::TL::Reverse<ET5Loki>::Result>::value << "):" << std::endl;
	std::cout << TypeListToStrLoki<Loki::TL::Reverse<ET5Loki>::Result>::value << std::endl;

	std::cout << "##########################################" << std::endl;
	std::cout << "### Najbardziej pochodny (MostDerived) ###" << std::endl;
	std::cout << "##########################################" << std::endl;
	std::cout << "Testowa lista: ";
	std::cout << TypeListToStr<ET6>::value << std::endl;
	std::cout << "(schemat dziedziczenia klas dostepny w pliku png)\n";
	std::cout << "MostDerived<ET6, samolot>: " << typeid(MostDerived<ET6, samolot>::Result).name() << std::endl;
	std::cout << "Loki::TL::MostDerived<ET6, samolot>: " << typeid(Loki::TL::MostDerived<ET6Loki, samolot>::Result).name() << std::endl;
	std::cout << "MostDerived<ET6, czlowiek>: " << typeid(MostDerived<ET6, czlowiek>::Result).name() << std::endl;
	std::cout << "Loki::TL::MostDerived<ET6, czlowiek>: " << typeid(Loki::TL::MostDerived<ET6Loki, czlowiek>::Result).name() << std::endl;
	std::cout << "MostDerived<ET6, zwierze>: " << typeid(MostDerived<ET6, zwierze>::Result).name() << std::endl;
	std::cout << "Loki::TL::MostDerived<ET6, zwierze>: " << typeid(Loki::TL::MostDerived<ET6Loki, zwierze>::Result).name() << std::endl;

	std::cout << "##########################################" << std::endl;
	std::cout << "############# DerivedToFront #############" << std::endl;
	std::cout << "##########################################" << std::endl;
	std::cout << "Testowa lista: ";
	std::cout << TypeListToStr<ET6>::value << std::endl;
	std::cout << "DerivedToFront (size: " << DerivedToFront<ET6>::Result::size << "):" << std::endl;
	std::cout << TypeListToStr<DerivedToFront<ET6>::Result>::value << std::endl;
	std::cout << "Loki::TL::DerivedToFront (size: " << Loki::TL::Length<Loki::TL::DerivedToFront<ET6Loki>::Result>::value << "):" << std::endl;
	std::cout << TypeListToStrLoki<Loki::TL::DerivedToFront<ET6Loki>::Result>::value << std::endl;
	
	return 0;
}
