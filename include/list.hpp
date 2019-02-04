// todo: more operation on list like compare

#include <algorithm>
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

// Length
template <typename list>
struct Length {
  static const size_t result = 1 + Length<typename list::Tail>::result;
};

template <>
struct Length<NIL> {
  static const size_t result = 0;
};

// ItemAt
template <typename list, size_t N>
struct ItemAt {
  typedef typename ItemAt<typename list::Tail, N - 1>::result result;
};

template <typename list>
struct ItemAt<list, 0> {
  typedef typename list::Head result;
};

// InsertItemAt
template <typename list, typename item, size_t index>
struct InsertItemAt {
  typedef List<
      typename list::Head,
      typename InsertItemAt<typename list::Tail, item, index - 1>::result>
      result;
};

template <typename list, typename item>
struct InsertItemAt<list, item, 0> {
  typedef List<item, list> result;
};

// RemoveItemAt
template <typename list, size_t index>
struct RemoveItemAt {
  typedef List<typename list::Head,
               typename RemoveItemAt<typename list::Tail, index - 1>::result>
      result;
};

template <typename list>
struct RemoveItemAt<list, 0> {
  typedef typename list::Tail result;
};

// ListToString
template <typename list>
std::string ListToString() {
  return "(" + std::to_string(list::Head::value) + ", " +
         ListToString<typename list::Tail>() + ")";
};

template <>
std::string ListToString<NIL>() {
  return std::string("NIL");
};

//  // test version
//
// void f() {}
//
// template <typename head, typename... types>
// void f(head x, types... variables) {
//   std::cout << x << " ";
//   f(variables...);
// }

// CreateList
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

// Slice [begin, end)
template <typename list, size_t begin, size_t end>
struct Slice {
  template <size_t x>
  struct Type {
    static const TYPE value = x;
  };

  template <typename __list, typename __begin, typename __end>
  struct __Slice {
    typedef typename __Slice<
        typename RemoveItemAt<__list, Length<__list>::result - 1>::result,
        __begin, __end>::result result;
  };

  template <typename __list, typename __begin>
  struct __Slice<__list, __begin, Type<(Length<__list>::result)>> {
    typedef typename __Slice<typename __list::Tail, Type<__begin::value - 1>,
                             Type<(Length<__list>::result - 1)>>::result result;
  };

  template <typename __list>
  struct __Slice<__list, Type<0>, Type<(Length<__list>::result)>> {
    typedef __list result;
  };

  typedef typename __Slice<
      list, Type<begin >= 0 ? begin : 0>,
      Type<end <= Length<list>::result ? end : Length<list>::result>>::result
      result;
};

void List_Part() {
  // typedef List<Type<3>> l3;
  // typedef List<Type<2>, l3> l2;
  // typedef List<Type<1>, l2> l1

  typedef CreateList<1>::result l1;
  typedef CreateList<1, 2, 3>::result l2;

  std::cout << std::endl;
  std::cout << "l1 = " << ListToString<l1>() << std::endl;
  std::cout << "l2 = " << ListToString<l2>() << std::endl;
  std::cout << "lenth(l2) = " << Length<l2>::result << std::endl;
  std::cout << "itemAt(l2, 2) = " << ItemAt<l2, 2>::result::value << std::endl;
  std::cout << "insertItemAt(l1, 0, 0) = "
            << ListToString<InsertItemAt<l1, Type<0>, 0>::result>()
            << std::endl;
  std::cout << "insertItemAt(l1, 0, 0) = "
            << ListToString<InsertItemAt<l1, Type<0>, 0>::result>()
            << std::endl;
  std::cout << "removeItemAt(l2, 0) = "
            << ListToString<RemoveItemAt<l2, 0>::result>() << std::endl;
  std::cout << "removeItemAt(l2, 2) = "
            << ListToString<RemoveItemAt<l2, 2>::result>() << std::endl;
  std::cout << "slice(l2, 0, 3) = " << ListToString<Slice<l2, 0, 3>::result>()
            << std::endl;
  std::cout << "slice(l2, 0, 1) = " << ListToString<Slice<l2, 0, 1>::result>()
            << std::endl;
  std::cout << "slice(l2, 1, 2) = " << ListToString<Slice<l2, 1, 2>::result>()
            << std::endl;
  std::cout << "slice(l2, 1, 3) = " << ListToString<Slice<l2, 1, 3>::result>()
            << std::endl;
  std::cout << "slice(l2, 0, 5) = " << ListToString<Slice<l2, 0, 5>::result>()
            << std::endl;
}
