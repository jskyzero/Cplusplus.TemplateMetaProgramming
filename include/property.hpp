template <typename ParentType, typename MemberType>
struct Property {
  typedef MemberType ParentType::*MemberPtrType;
  MemberPtrType p_;
  void Bind(MemberPtrType p) { p_ = p; }
  void Set(ParentType & parent, const MemberType & value) { parent.*p_ = value; }
};
