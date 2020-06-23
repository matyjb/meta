#include <iostream>
#include <typeinfo>
#include <typeindex>

#include "typelist.hpp"

using ExampleType1 = TypeList<int>;
using ExampleType2 = TypeList<int, long int, char>;
using ExampleType3 = TypeList<int, int, int, int>;

using ExampleType4 = TypeList<ExampleType1, ExampleType2>;

using ExampleType5 = TypeList<int, long int, int, bool, int, char>;

class base {};
class derived : base {};
class mostderived2 : base {};
class mostderived : derived {};
class mostderived3 : derived {};

using ExampleType6 = TypeList<base, derived, mostderived2, mostderived, mostderived3>;


int main() {

	// std::cout << TypeList<>::size << "\n";
	// std::cout << ExampleType1::size << "\n";
	// std::cout << ExampleType2::size << "\n";
	// std::cout << ExampleType3::size << "\n";
	// std::cout << ExampleType4::size << "\n";
	// std::cout << "\n";
	// typename TypeAt<ExampleType3, 0>::Result i;
	// i = 7;
	// std::cout << "i = " << i << "\n";
	// //std::cout << decltype(i).name() << "\n";
	// std::cout << "\n";
	// std::cout << typeid(int).name() << "\n";
	// std::cout << typeid(int).hash_code() << "\n";
	// std::cout << (std::type_index(typeid(int)) == std::type_index(typeid(TypeAt<ExampleType3, 0>::Result))) << "\n";
	// std::cout << typeid(TypeAt<ExampleType3, 0>::Result).name() << "\n";
	// std::cout << (typeid(TypeAt<ExampleType3, 0>::Result).hash_code() == typeid(int).hash_code()) << "\n";
	// std::cout << (typeid(TypeAt<ExampleType3, 0>::Result) == typeid(int)) << "\n";
	// std::cout << "\n";
	// typename TypeAt<ExampleType2, 2>::Result c;
	// c = 'a';
	// std::cout << "c = " << c << "\n";
	// std::cout << "\n";
	// std::cout << Append<TypeList<>, double>::Result::size << "\n";
	// std::cout << Append<TypeList<int>, double>::Result::size << "\n";
	// std::cout << Append<TypeList<int, float>, double>::Result::size << "\n";
	// std::cout << Append<ExampleType3, double>::Result::size << "\n";
	// std::cout << "\n";
	// std::cout << IndexOf<TypeList<>, int>::value << "\n";
	// std::cout << IndexOf<ExampleType2, int>::value << "\n";
	// std::cout << IndexOf<ExampleType2, long int>::value << "\n";
	// std::cout << "\n";
	// std::cout << Erase<ExampleType2, long int>::Result::size << "\n";
	// std::cout << "\n";
	// typename CreateTuple<ExampleType2>::Result tmp;
	// std::get<0>(tmp) = 7;
	// std::get<1>(tmp) = 14L;
	// std::get<2>(tmp) = 'z';
	// std::cout << std::get<0>(tmp) << "\n";
	// std::cout << std::get<1>(tmp) << "\n";
	// std::cout << std::get<2>(tmp) << "\n";

	//sprawdzenie nowych funkcji:
	std::cout << "\n";
	std::cout << "Lista 5 o dlugosci: " << ExampleType5::size << "\n";
	std::cout << typeid(TypeAt<ExampleType5, 0>::Result).name() << ", ";
	std::cout << typeid(TypeAt<ExampleType5, 1>::Result).name() << ", ";
	std::cout << typeid(TypeAt<ExampleType5, 2>::Result).name() << ", ";
	std::cout << typeid(TypeAt<ExampleType5, 3>::Result).name() << ", ";
	std::cout << typeid(TypeAt<ExampleType5, 4>::Result).name() << ", ";
	std::cout << typeid(TypeAt<ExampleType5, 5>::Result).name() << "\n";
	std::cout << "\n";

	std::cout << "Usuwanie wszystkich int" << "\n";
	std::cout << EraseAll<ExampleType5,int>::Result::size << "\n";
	std::cout << typeid(TypeAt<EraseAll<ExampleType5,int>::Result, 0>::Result).name() << ", ";
	std::cout << typeid(TypeAt<EraseAll<ExampleType5,int>::Result, 1>::Result).name() << ", ";
	std::cout << typeid(TypeAt<EraseAll<ExampleType5,int>::Result, 2>::Result).name() << "\n";
	std::cout << "\n";

	std::cout << "Usuwanie duplikatow" << "\n";
	std::cout << NoDuplicates<ExampleType5>::Result::size << "\n";
	std::cout << typeid(TypeAt<NoDuplicates<ExampleType5>::Result, 0>::Result).name() << ", ";
	std::cout << typeid(TypeAt<NoDuplicates<ExampleType5>::Result, 1>::Result).name() << ", ";
	std::cout << typeid(TypeAt<NoDuplicates<ExampleType5>::Result, 2>::Result).name() << ", ";
	std::cout << typeid(TypeAt<NoDuplicates<ExampleType5>::Result, 3>::Result).name() << "\n";
	std::cout << "\n";

	std::cout << "Odwracanie listy" << "\n";
	std::cout << Reverse<ExampleType5>::Result::size << "\n";
	std::cout << typeid(TypeAt<Reverse<ExampleType5>::Result, 0>::Result).name() << ", ";
	std::cout << typeid(TypeAt<Reverse<ExampleType5>::Result, 1>::Result).name() << ", ";
	std::cout << typeid(TypeAt<Reverse<ExampleType5>::Result, 2>::Result).name() << ", ";
	std::cout << typeid(TypeAt<Reverse<ExampleType5>::Result, 3>::Result).name() << ", ";
	std::cout << typeid(TypeAt<Reverse<ExampleType5>::Result, 4>::Result).name() << ", ";
	std::cout << typeid(TypeAt<Reverse<ExampleType5>::Result, 5>::Result).name() << "\n";
	std::cout << "\n";

	std::cout << "Najbardziej pochodny element" << "\n";
	std::cout << typeid(MostDerived<TypeList<mostderived>, base>::Result).name() << ", ";
	std::cout << "\n";
	std::cout << typeid(MostDerived<TypeList<mostderived,mostderived2>, base>::Result).name() << ", ";
	std::cout << "\n";
	std::cout << typeid(MostDerived<TypeList<mostderived,mostderived2>, derived>::Result).name() << ", ";
	std::cout << "\n";
	std::cout << typeid(MostDerived<TypeList<mostderived3>, derived>::Result).name() << ", ";
	std::cout << "\n";

	// std::cout << typeid(MostDerived<ExampleType6, mostderived>::Result).name() << ", ";
	std::cout << "\n";

	return 0;
}

