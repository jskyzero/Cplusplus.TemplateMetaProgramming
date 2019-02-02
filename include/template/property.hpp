

template <typename ParentType, typename MemberType>
struct Property {
  // typedef member ptr type
  typedef MemberType ParentType::*MemberPtrType;
  // use pointer to change data
  MemberPtrType p;
  // bind pointer
  void Bind(MemberPtrType p_) { p = p_; }
  // change data
  void Set(ParentType& parent, const MemberType& value) { parent.*p = value; }
};
