#include "typelist.hpp"

// VISITOR
template <typename T, typename... Types>
class Visitor : public Visitor<T>, public Visitor<Types...>
{
public:
  using Visitor<T>::visit;
  using Visitor<Types...>::visit;
};

template <typename T>
class Visitor<T>
{
public:
  virtual void visit(T &visitable) = 0;
};

// VISITABLE
template <typename T, typename... Types>
class Visitable : public Visitable<T>, public Visitable<Types...>
{
public:
  using Visitable<T>::accept;
  using Visitable<Types...>::accept;
};

template <typename T>
class Visitable<T>
{
public:
  virtual void accept(T &visitor) = 0;
};