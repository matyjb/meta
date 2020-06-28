#include <iostream>
#include <typeinfo>
#include <typeindex>
#include "Typelist.hpp"
#include "loki/Typelist.h"

// te szablony sa do reprezentacji typelisty w postaci stringa
// jedna wersja dla TypeList, a jedna dla Loki::Typelist

const std::string przecinek = ", ";

template <typename ListOfTypes>
struct TypeListToStr;

template <>
struct TypeListToStr<TypeList<>>
{
	public:
		inline static const std::string value = "";
};

template <typename T>
struct TypeListToStr<TypeList<T>>
{
	public:
		inline static const std::string value = typeid(T).name();
};

template <typename Head, typename... Tail>
struct TypeListToStr<TypeList<Head, Tail...>>
{
private:
	inline static const std::string aux_value = TypeListToStr<TypeList<Tail...>>::value;

public:
	inline static const std::string value = typeid(Head).name() + przecinek + aux_value;
};

// LOKI
template <typename ListOfTypes>
struct TypeListToStrLoki;

template <>
struct TypeListToStrLoki<Loki::NullType>
{
	public:
		inline static const std::string value = "";
};

template <typename T>
struct TypeListToStrLoki<Loki::Typelist<T, Loki::NullType>>
{
	public:
		inline static const std::string value = typeid(T).name();
};

template <typename Head, typename Tail>
struct TypeListToStrLoki<Loki::Typelist<Head, Tail>>
{
private:
	inline static const std::string aux_value = TypeListToStrLoki<Tail>::value;

public:
	inline static const std::string value = typeid(Head).name() + przecinek + aux_value;
};