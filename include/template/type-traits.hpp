#include <typeinfo> // for typeid()


#define TYPE_NAME(x) (typeid(x).name())

template <typename MemPtrType>
struct GetMemTypeFromMemPtr {
};

template <typename ParentType, typename Type>
struct GetMemTypeFromMemPtr<Type ParentType::*> {
  typedef Type Result;
};


template <typename MemPtrType>
struct GetClassTypeFromMemPtr {
};

template <typename ParentType, typename Type>
struct GetClassTypeFromMemPtr<Type ParentType::*> {
  typedef ParentType Result;
};

