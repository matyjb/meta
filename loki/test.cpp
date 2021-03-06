/** sample test for the Loki library 
 *
 * @author marco corvi 
 * @date dec 2004
 *
 * This code is part of a set of sample test programs for the Loki library.
 *
 * The Loki library is copyright(c) 2001 by Andrei Alexandrescu.
 * It is described in the book:
 *     Alexandrescu, Andrei. "Modern C++ Design: Generic Programming and
 *     Design Patterns Applied". Copyright (c) 2001. Addison-Wesley.
 * and is available from 
 *     http://sourceforge.net/projects/loki-lib/
 *
 * Permission to use, copy, modify, distribute and sell this software 
 *     (ie, the test programs) for any purpose is hereby granted without fee.
 * Permission to use, copy, modify, distribute and sell the software
 *     changes made to the Loki library is hereby granted without fee
 *     for any purposes provided the original Loki library copyright notice
 *     appears in all copies and that both that notice and this 
 *     permission notice appear in supporting documentation.
 * The author makes no representations about the suitability of this 
 *     software for any purpose. It is provided "as is" without express 
 *     or implied warranty.
 *
 * =========================================================
 * Sample program using typelists (chapter 3)
 */
#include <iostream>
#include "TypelistMacros.h"

#include "Typelist.h"


int main()
{
  // ===============================================================
  // TypeList
  // ===============================================================
  std::cout << "Working with typelists \n";

  typedef TYPELIST_3( int, float, std::string )  List0;

  // show the usage of Length<...>::value
  //
  std::cout << "Length: " << Loki::TL::Length< List0 >::value << "\n"; 

  // show the usage of TypeAT<..., index>::Result
  //
  Loki::TL::TypeAt< List0, 1 >::Result f = 0.01;
  Loki::TL::TypeAt< List0, 2 >::Result s = "bye";

  std::cout << "TypeAt<(I,F,S), 1> is f " << f << "\n";
  std::cout << "TypeAt<(I,F,S), 2> is s " << s << "\n";

  // show the usage of IndexOf<..., T>::value
  //
  std::cout << "IndexOf   IndexOf<(I,F,S), I>: 0 - " 
	    << Loki::TL::IndexOf< List0, int >::value << "\n";
  std::cout << "IndexOf   IndexOf<(I,F,S), S>: 2 - " 
	    << Loki::TL::IndexOf< List0, std::string >::value << "\n";

  // show the usage of Append<..., T>::Result
  // List1 is 
  //
  typedef Loki::TL::Append< List0, bool >::Result List1;

  std::cout << "Append<(I,S,F),B>          IndexOf<(I,F,S,B), B>: 3 - "
	    << Loki::TL::IndexOf< List1, bool >::value << "\n";

  // show the usage of Erase<..., T>::Result
  // List2 is 
  //
  // N.B. EraseAll works as well (erases all the occurrencies of a type)
  //
  typedef Loki::TL::Erase::Result List2;
  std::cout << "Erase<(I,F,S,B),S>         IndexOf<(I,F,B), B>: 2 - "
	    << Loki::TL::IndexOf< List2, bool >::value << "\n";

  // List3  is 
  // List4  is 
  // List5  is 
  typedef Loki::TL::Append< List0, TYPELIST_2(float, bool) >::Result List3;
  std::cout << "Append<(I,F,S),(F,B)>      IndexOf<(I,F,S,F,B), B>: 4 - "
	    << Loki::TL::IndexOf< List3, bool >::value << "\n";

  typedef Loki::TL::Replace< List3, int, bool >::Result List4;
  std::cout << "Replace<(I,F,S,F,B),I,B>   IndexOf<(B,F,S,F,B), B>: 0 - "
	    << Loki::TL::IndexOf< List4, bool >::value << "\n";

  typedef Loki::TL::NoDuplicates::Result List5;
  std::cout << "NoDuplicates<((I,F,S,F,B)> IndexOf<(I,F,S,B), B>: 3 - "
	    << Loki::TL::IndexOf< List5, bool >::value << "\n";

  typedef Loki::TL::Reverse< List5 >::Result List6;
  std::cout << "Reverse<(I,F,S,B)>         IndexOf<(B,S,F,I), B>: 0 - "
	    << Loki::TL::IndexOf< List6, bool >::value << "\n";


}