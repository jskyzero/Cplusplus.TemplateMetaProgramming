# Cplusplus.TemplateMetaProgramming

[![](https://img.shields.io/badge/Author-jskyzero-brightgreen.svg?style=flat)]()
[![](https://img.shields.io/badge/Data-2019/01/14-brightgreen.svg?style=flat)]()
[![Build Status](https://travis-ci.com/oYOvOYo/Cplusplus.TemplateMetaProgramming.svg?branch=master)](https://travis-ci.com/oYOvOYo/Cplusplus.TemplateMetaProgramming)
[![](https://img.shields.io/badge/C%2B%2B-11-blue.svg?style=flat)]()

## Overview

Some codes about template in Cplusplus.

### Fraction Part

+ Factorial
```C++
void Factorial_Part() {
  std::cout << Factorial<5>::result << std::endl;
}
```
+ Fraction
```C++
void Fraction_Part() {
  typedef Fraction<1, -3> x;
  typedef Fraction<-1, 2> y;
  std::cout << "x     = " << FractionToString<x>() << std::endl;
  std::cout << "y     = " << FractionToString<y>() << std::endl;
  std::cout << "x + y = " << FractionToString<Addition<x, y>::result>()
            << std::endl;
  std::cout << "x - y = " << FractionToString<Subtraction<x, y>::result>()
            << std::endl;
  std::cout << "x * y = " << FractionToString<Multiplication<x, y>::result>()
            << std::endl;
  std::cout << "3 * x = "
            << FractionToString<ScalarMultiplication<3, x>::result>()
            << std::endl;
  std::cout << "x / y = "
            << FractionToString<Division<x, y>::result>()
            << std::endl;
}
```
+ List
```C++
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
```

### Template Part

+ TypeTraits
```C++
auto type1 = GetMemTypeFromMemPtr<decltype(&SomeStruct::SomeMember)>::Result;
auto type2 = GetClassTypeFromMemPtr<decltype(&SomeStruct::SomeMember)>::Result;
```

+ Property
```C++
  SomeClass sc;
  auto prop = Property<SomeClass, int>();
  prop.Bind(&SomeClass::SomeMember);
  prop.Set(sc, 10);
```
### Effective Part

This part aims to compare the template metaprogramming's effectiveness with origin methods in cplusplus, in fact this could do in a more fair way, but anyhow, this is only a example.

+ compile time class generation
  + programming at compile time, see the factorial example.
+ compile time code optimization
  + optimization at compule time, see the vector example.
+ static polymorphism
  + do not need virtual look-up table cost.

#### Result & Analysis

use `make compare` to run all programs and see the usage.

```bash
# "factorial"
time ././bin/factorial.out
0.48user 0.01system 0:00.50elapsed 99%CPU (0avgtext+0avgdata 1456maxresident)k
0inputs+0outputs (0major+415minor)pagefaults 0swaps
# "factorial with template meta programming"
time ././bin/factorial.tmp.out
0.03user 0.00system 0:00.02elapsed 106%CPU (0avgtext+0avgdata 1452maxresident)k
0inputs+0outputs (0major+413minor)pagefaults 0swaps
# "vector"
time ././bin/vector.out
4.59user 0.01system 0:04.59elapsed 100%CPU (0avgtext+0avgdata 1464maxresident)k
0inputs+0outputs (0major+417minor)pagefaults 0swaps
# "vector with template meta programming"
time ././bin/vector.tmp.out
4.54user 0.00system 0:04.57elapsed 99%CPU (0avgtext+0avgdata 1460maxresident)k
0inputs+0outputs (0major+416minor)pagefaults 0swaps
# "polymorphic"
time ././bin/polymorphic.out
0.25user 0.01system 0:00.26elapsed 101%CPU (0avgtext+0avgdata 1452maxresident)k
0inputs+0outputs (0major+415minor)pagefaults 0swaps
# "polymorphic with template meta programming"
time ././bin/polymorphic.tmp.out
0.18user 0.00system 0:00.19elapsed 94%CPU (0avgtext+0avgdata 1452maxresident)k
0inputs+0outputs (0major+414minor)pagefaults 0swaps
# make all compare finished
```

so we could see, the template metaprogramming could save time in runtime, for the verter example, the oprimization may not be clearly, this could be oprimization makes no difference when for loop does't need much time.

## Reference

+ [Compile_time_function_execution](https://en.wikipedia.org/wiki/Compile_time_function_execution)
+ [Template_metaprogramming](https://en.wikipedia.org/wiki/Template_metaprogramming)
+ [introduction-to-c-template-metaprogramming](https://monoinfinito.wordpress.com/series/introduction-to-c-template-metaprogramming/)
