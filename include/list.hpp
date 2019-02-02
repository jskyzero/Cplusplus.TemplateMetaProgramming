#include <iostream>

typedef int TYPE;

template <TYPE x>
struct Type {
  static const TYPE value = x;
};

struct NIL {
  typedef NIL Head;
  typedef NIL Tail;
};

template <typename H, typename T = NIL>
struct List {
  typedef H Head;
  typedef T Tail;
};

template <typename list>
struct Length {
  static const size_t result = 1 + Length<typename list::Tail>::result;
};

template <>
struct Length<NIL> {
  static const size_t result = 0;
};

template <typename list, size_t N>
struct ItemAt {
  typedef typename ItemAt<typename list::Tail, N - 1>::result result;
};

template <typename list>
struct ItemAt<list, 0> {
  typedef typename list::Head result;
};

template <typename list>
std::string ListToString() {
  return "(" + std::to_string(list::Head::value) + ", " +
         ListToString<typename list::Tail>() + ")";
};

template <>
std::string ListToString<NIL>() {
  return std::string("NIL");
};

template <TYPE... lists>
struct CreateList {
  template <typename head, typename... tail>
  struct __CreateList {
    typedef List<head, typename __CreateList<tail...>::result> result;
  };

  template <typename head>
  struct __CreateList<head> {
    typedef List<head> result;
  };
  typedef typename __CreateList<Type<lists>...>::result result;
};

void List_Part() {
  // typedef List<Type<3>> l3;
  // typedef List<Type<2>, l3> l2;
  // typedef List<Type<1>, l2> l1;

  typedef CreateList<1, 2, 3>::result l1;

  std::cout << std::endl;
  std::cout << "list = "
            << "(1, (2, (3, NIL)))" << std::endl;
  std::cout << "list = " << ListToString<l1>() << std::endl;
  std::cout << "lenth(list) = " << Length<l1>::result << std::endl;
  std::cout << "itemAt(list, 0) = " << ItemAt<l1, 0>::result::value
            << std::endl;
  std::cout << "itemAt(list, 1) = " << ItemAt<l1, 1>::result::value
            << std::endl;
  std::cout << "itemAt(list, 2) = " << ItemAt<l1, 2>::result::value
            << std::endl;
}
