#if !defined __TYPELIST_HPP__
#define __TYPELIST_HPP__

#include <tuple>

template<typename ... Args>
struct TypeList;


template<typename ... Args>
struct TypeList {
	static const int size = sizeof...(Args);
};

//******************************************************


template<typename ... Args>
struct CreateTuple;

template<typename ... Args>
struct CreateTuple<TypeList<Args...> > {
	using Result = std::tuple<Args...>;
};


//******************************************************


template<typename ListOfTypes, int index>
struct TypeAt;


template<typename Head, typename ... Tail>
struct TypeAt<TypeList<Head, Tail...>, 0> {
	using Result = Head;
};

template<typename Head, typename ... Tail, int index>
struct TypeAt<TypeList<Head, Tail...>, index> {
	using Result = typename TypeAt<TypeList<Tail...>, index - 1>::Result;
};


//******************************************************


template<typename T, typename ListOfTypes>
struct InsertFront;


template<typename T, typename ... Args>
struct InsertFront<T, TypeList<Args...> > {
	using Result = TypeList<T, Args...>;
};


//******************************************************


template<typename ListOfTypes, typename T>
struct Append;


template<typename T>
struct Append<TypeList<>, T> {
	using Result = TypeList<T>;
};

template<typename Head, typename ... Tail, typename T>
struct Append<TypeList<Head, Tail...>, T> {
	using Result = typename InsertFront<Head, typename Append<TypeList<Tail...>, T>::Result>::Result;
};


//******************************************************


template<typename T, typename ListOfTypes>
struct IndexOf;


template<typename T>
struct IndexOf<TypeList<>, T> {
	static const int value = -1;
};

template<typename Head, typename ... Tail>
struct IndexOf<TypeList<Head, Tail...>, Head> {
	static const int value = 0;
};

template<typename T, typename Head, typename ... Tail>
struct IndexOf<TypeList<Head, Tail...>, T> {
    private:
	static const int aux_value = IndexOf<TypeList<Tail...>, T>::value;
    public:
	static const int value = (aux_value == -1)?(-1):(1 + aux_value);
};


//******************************************************


template<typename ListOfTypes, typename T>
struct Erase;


template<typename T>
struct Erase<TypeList<>, T> {
	using Result = TypeList<>;
};

template<typename Head, typename ... Tail>
struct Erase<TypeList<Head, Tail...>, Head> {
	using Result = TypeList<Tail...>;
};

template<typename Head, typename ... Tail, typename T>
struct Erase<TypeList<Head, Tail...>, T> {
	using Result = typename InsertFront<Head, typename Erase<TypeList<Tail...>, T>::Result>::Result;
};


//******************************************************

template<typename ListOfTypes, typename T>
struct EraseAll;


template<typename T>
struct EraseAll<TypeList<>, T> {
	using Result = TypeList<>;
};

template<typename Head, typename ... Tail>
struct EraseAll<TypeList<Head, Tail...>, Head> {
	using Result = typename EraseAll<TypeList<Tail...>,Head>::Result;
};

template<typename Head, typename ... Tail, typename T>
struct EraseAll<TypeList<Head, Tail...>, T> {
	using Result = typename InsertFront<Head,typename EraseAll<TypeList<Tail...>,T>::Result>::Result;
};


//******************************************************


template<typename ListOfTypes, typename T, typename U>
struct Replace;

template <typename Head, typename U, typename ... Tail>
struct Replace<TypeList<Head, Tail...>, Head, U> {
	using Result = typename InsertFront< U, TypeList<Tail...> >::Result;
};

template <typename Head, typename T, typename U, typename ... Tail>
struct Replace<TypeList<Head, Tail...>, T, U> {
	using Result = typename InsertFront< Head, typename Replace<TypeList<Tail...>, T, U>::Result >::Result;
};

template <typename T, typename U>
struct Replace<TypeList<>, T, U> {
	using Result = TypeList<>;
};


//******************************************************


template <typename ListOfTypes>
struct NoDuplicates;

template <>
struct NoDuplicates<TypeList<>>
{
	using Result = TypeList<>;
};

// template <typename Head>
// struct NoDuplicates<TypeList<Head>>
// {
// 	using Result = TypeList<Head>;
// };

template <typename Head, typename ...Tail>
struct NoDuplicates<TypeList<Head,Tail...>>
{
	private:
		using L1 = typename EraseAll<TypeList<Tail...>,Head>::Result;
		using L2 = typename NoDuplicates<L1>::Result;
	public:
		using Result = typename InsertFront<Head, L2>::Result;
};

//******************************************************


template <class ListOfTypes>
struct Reverse;

template <>
struct Reverse<TypeList<>>
{
	using Result = TypeList<>;
};

template <typename Head, typename ...Tail>
struct Reverse<TypeList<Head,Tail...>>
{
	private:
		using L1 = typename Reverse<TypeList<Tail...>>::Result;
	public:
		using Result = typename Append<L1,Head>::Result;
};


//******************************************************


template <bool flag, typename T, typename U>
struct Select
{
	using Result = T;
};

template <typename T, typename U>
struct Select<false, T, U>
{
	using Result = U;
};


//******************************************************


template <typename T, typename U>
struct IsSameType
{
	enum { value = false };
};

template <typename T>
struct IsSameType<T, T>
{
	enum { value = true };
};


//******************************************************


template <class T, class U>
struct SuperSubclass
{ //tu jest coś źle ze zwracaniem wartości
	enum { value = IsSameType<T.name(), U.name()>::value };
};

template <>
struct SuperSubclass<void, void>
{
	enum { value = false };
};


//******************************************************


template <class T, class ListofTypes>
struct MostDerived;

template <class T>
struct MostDerived<TypeList<>, T>
{
	using Result = T;
};

template <class Head, class ...Tail, class T>
struct MostDerived<TypeList<Head, Tail...>, T>
{
private:
	using Candidate = typename MostDerived<Tail..., T>::Result;
public:
	using Result = typename Select<SuperSubclass<Candidate, Head>::value, Head, Candidate>::Result;
};


//******************************************************


template <class ListOfTypes>
struct DerivedToFront;

template <>
struct DerivedToFront<TypeList<>>
{
	using Result = TypeList<>;
};

template <class Head, class ...Tail>
struct DerivedToFront<TypeList<Head, Tail...> >
{
private:
	using TheMostDerived = typename MostDerived<Tail..., Head>::Result;
	using L = typename Replace<Tail..., TheMostDerived, Head>::Result;
public:
	using Result = TypeList<TheMostDerived, L>::Result;
};


#endif
