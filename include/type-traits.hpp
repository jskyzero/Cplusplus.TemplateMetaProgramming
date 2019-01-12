#define TYPE_NAME(x) (typeid(x).name())

template <typename MemPtrType>
struct GetMemPtrType {
  typedef MemPtrType Result;
};

template <typename ParentType, typename Type>
struct GetMemPtrType<Type ParentType::*> {
  typedef Type Result;
};


template <typename MemPtrType>
struct GetMemPtrClass {
  typedef MemPtrType Result;
};

template <typename ParentType, typename Type>
struct GetMemPtrClass<Type ParentType::*> {
  typedef ParentType Result;
};

