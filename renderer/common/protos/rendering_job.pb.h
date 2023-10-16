// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: rendering_job.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_rendering_5fjob_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_rendering_5fjob_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3021000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3021012 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_rendering_5fjob_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_rendering_5fjob_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_rendering_5fjob_2eproto;
class ProjectFiles;
struct ProjectFilesDefaultTypeInternal;
extern ProjectFilesDefaultTypeInternal _ProjectFiles_default_instance_;
class RenderingJob;
struct RenderingJobDefaultTypeInternal;
extern RenderingJobDefaultTypeInternal _RenderingJob_default_instance_;
class RenderingJobItem;
struct RenderingJobItemDefaultTypeInternal;
extern RenderingJobItemDefaultTypeInternal _RenderingJobItem_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::ProjectFiles* Arena::CreateMaybeMessage<::ProjectFiles>(Arena*);
template<> ::RenderingJob* Arena::CreateMaybeMessage<::RenderingJob>(Arena*);
template<> ::RenderingJobItem* Arena::CreateMaybeMessage<::RenderingJobItem>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

enum ControlPackageCategory : int {
  CLIENT_RENDERER_REGISTER = 0,
  CLIENT_RENDERER_JOB_FEEDBACK = 1,
  CLIENT_TRY_GET_RENDER_JOB = 3,
  CLIENT_QUERY_JOB_DETAIL = 4,
  ControlPackageCategory_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::min(),
  ControlPackageCategory_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::max()
};
bool ControlPackageCategory_IsValid(int value);
constexpr ControlPackageCategory ControlPackageCategory_MIN = CLIENT_RENDERER_REGISTER;
constexpr ControlPackageCategory ControlPackageCategory_MAX = CLIENT_QUERY_JOB_DETAIL;
constexpr int ControlPackageCategory_ARRAYSIZE = ControlPackageCategory_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* ControlPackageCategory_descriptor();
template<typename T>
inline const std::string& ControlPackageCategory_Name(T enum_t_value) {
  static_assert(::std::is_same<T, ControlPackageCategory>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function ControlPackageCategory_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    ControlPackageCategory_descriptor(), enum_t_value);
}
inline bool ControlPackageCategory_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, ControlPackageCategory* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<ControlPackageCategory>(
    ControlPackageCategory_descriptor(), name, value);
}
// ===================================================================

class RenderingJobItem final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:RenderingJobItem) */ {
 public:
  inline RenderingJobItem() : RenderingJobItem(nullptr) {}
  ~RenderingJobItem() override;
  explicit PROTOBUF_CONSTEXPR RenderingJobItem(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  RenderingJobItem(const RenderingJobItem& from);
  RenderingJobItem(RenderingJobItem&& from) noexcept
    : RenderingJobItem() {
    *this = ::std::move(from);
  }

  inline RenderingJobItem& operator=(const RenderingJobItem& from) {
    CopyFrom(from);
    return *this;
  }
  inline RenderingJobItem& operator=(RenderingJobItem&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const RenderingJobItem& default_instance() {
    return *internal_default_instance();
  }
  static inline const RenderingJobItem* internal_default_instance() {
    return reinterpret_cast<const RenderingJobItem*>(
               &_RenderingJobItem_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(RenderingJobItem& a, RenderingJobItem& b) {
    a.Swap(&b);
  }
  inline void Swap(RenderingJobItem* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(RenderingJobItem* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  RenderingJobItem* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<RenderingJobItem>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const RenderingJobItem& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const RenderingJobItem& from) {
    RenderingJobItem::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(RenderingJobItem* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "RenderingJobItem";
  }
  protected:
  explicit RenderingJobItem(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kWorkingDirFieldNumber = 2,
    kFrameFieldNumber = 1,
  };
  // string working_dir = 2;
  void clear_working_dir();
  const std::string& working_dir() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_working_dir(ArgT0&& arg0, ArgT... args);
  std::string* mutable_working_dir();
  PROTOBUF_NODISCARD std::string* release_working_dir();
  void set_allocated_working_dir(std::string* working_dir);
  private:
  const std::string& _internal_working_dir() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_working_dir(const std::string& value);
  std::string* _internal_mutable_working_dir();
  public:

  // int32 frame = 1;
  void clear_frame();
  int32_t frame() const;
  void set_frame(int32_t value);
  private:
  int32_t _internal_frame() const;
  void _internal_set_frame(int32_t value);
  public:

  // @@protoc_insertion_point(class_scope:RenderingJobItem)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr working_dir_;
    int32_t frame_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_rendering_5fjob_2eproto;
};
// -------------------------------------------------------------------

class ProjectFiles final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:ProjectFiles) */ {
 public:
  inline ProjectFiles() : ProjectFiles(nullptr) {}
  ~ProjectFiles() override;
  explicit PROTOBUF_CONSTEXPR ProjectFiles(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  ProjectFiles(const ProjectFiles& from);
  ProjectFiles(ProjectFiles&& from) noexcept
    : ProjectFiles() {
    *this = ::std::move(from);
  }

  inline ProjectFiles& operator=(const ProjectFiles& from) {
    CopyFrom(from);
    return *this;
  }
  inline ProjectFiles& operator=(ProjectFiles&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const ProjectFiles& default_instance() {
    return *internal_default_instance();
  }
  static inline const ProjectFiles* internal_default_instance() {
    return reinterpret_cast<const ProjectFiles*>(
               &_ProjectFiles_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(ProjectFiles& a, ProjectFiles& b) {
    a.Swap(&b);
  }
  inline void Swap(ProjectFiles* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(ProjectFiles* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  ProjectFiles* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<ProjectFiles>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const ProjectFiles& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const ProjectFiles& from) {
    ProjectFiles::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(ProjectFiles* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "ProjectFiles";
  }
  protected:
  explicit ProjectFiles(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kRelativePathFieldNumber = 1,
    kDownloadUrlFieldNumber = 2,
  };
  // string relative_path = 1;
  void clear_relative_path();
  const std::string& relative_path() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_relative_path(ArgT0&& arg0, ArgT... args);
  std::string* mutable_relative_path();
  PROTOBUF_NODISCARD std::string* release_relative_path();
  void set_allocated_relative_path(std::string* relative_path);
  private:
  const std::string& _internal_relative_path() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_relative_path(const std::string& value);
  std::string* _internal_mutable_relative_path();
  public:

  // string download_url = 2;
  void clear_download_url();
  const std::string& download_url() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_download_url(ArgT0&& arg0, ArgT... args);
  std::string* mutable_download_url();
  PROTOBUF_NODISCARD std::string* release_download_url();
  void set_allocated_download_url(std::string* download_url);
  private:
  const std::string& _internal_download_url() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_download_url(const std::string& value);
  std::string* _internal_mutable_download_url();
  public:

  // @@protoc_insertion_point(class_scope:ProjectFiles)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr relative_path_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr download_url_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_rendering_5fjob_2eproto;
};
// -------------------------------------------------------------------

class RenderingJob final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:RenderingJob) */ {
 public:
  inline RenderingJob() : RenderingJob(nullptr) {}
  ~RenderingJob() override;
  explicit PROTOBUF_CONSTEXPR RenderingJob(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  RenderingJob(const RenderingJob& from);
  RenderingJob(RenderingJob&& from) noexcept
    : RenderingJob() {
    *this = ::std::move(from);
  }

  inline RenderingJob& operator=(const RenderingJob& from) {
    CopyFrom(from);
    return *this;
  }
  inline RenderingJob& operator=(RenderingJob&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const RenderingJob& default_instance() {
    return *internal_default_instance();
  }
  static inline const RenderingJob* internal_default_instance() {
    return reinterpret_cast<const RenderingJob*>(
               &_RenderingJob_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(RenderingJob& a, RenderingJob& b) {
    a.Swap(&b);
  }
  inline void Swap(RenderingJob* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(RenderingJob* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  RenderingJob* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<RenderingJob>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const RenderingJob& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const RenderingJob& from) {
    RenderingJob::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(RenderingJob* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "RenderingJob";
  }
  protected:
  explicit RenderingJob(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kFilesFieldNumber = 4,
    kTokenFieldNumber = 1,
    kProjectFileFieldNumber = 5,
    kProjectIdFieldNumber = 2,
    kJobidFieldNumber = 3,
  };
  // repeated .ProjectFiles files = 4;
  int files_size() const;
  private:
  int _internal_files_size() const;
  public:
  void clear_files();
  ::ProjectFiles* mutable_files(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::ProjectFiles >*
      mutable_files();
  private:
  const ::ProjectFiles& _internal_files(int index) const;
  ::ProjectFiles* _internal_add_files();
  public:
  const ::ProjectFiles& files(int index) const;
  ::ProjectFiles* add_files();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::ProjectFiles >&
      files() const;

  // string token = 1;
  void clear_token();
  const std::string& token() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_token(ArgT0&& arg0, ArgT... args);
  std::string* mutable_token();
  PROTOBUF_NODISCARD std::string* release_token();
  void set_allocated_token(std::string* token);
  private:
  const std::string& _internal_token() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_token(const std::string& value);
  std::string* _internal_mutable_token();
  public:

  // .ProjectFiles projectFile = 5;
  bool has_projectfile() const;
  private:
  bool _internal_has_projectfile() const;
  public:
  void clear_projectfile();
  const ::ProjectFiles& projectfile() const;
  PROTOBUF_NODISCARD ::ProjectFiles* release_projectfile();
  ::ProjectFiles* mutable_projectfile();
  void set_allocated_projectfile(::ProjectFiles* projectfile);
  private:
  const ::ProjectFiles& _internal_projectfile() const;
  ::ProjectFiles* _internal_mutable_projectfile();
  public:
  void unsafe_arena_set_allocated_projectfile(
      ::ProjectFiles* projectfile);
  ::ProjectFiles* unsafe_arena_release_projectfile();

  // uint32 project_id = 2;
  void clear_project_id();
  uint32_t project_id() const;
  void set_project_id(uint32_t value);
  private:
  uint32_t _internal_project_id() const;
  void _internal_set_project_id(uint32_t value);
  public:

  // uint32 jobid = 3;
  void clear_jobid();
  uint32_t jobid() const;
  void set_jobid(uint32_t value);
  private:
  uint32_t _internal_jobid() const;
  void _internal_set_jobid(uint32_t value);
  public:

  // @@protoc_insertion_point(class_scope:RenderingJob)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::ProjectFiles > files_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr token_;
    ::ProjectFiles* projectfile_;
    uint32_t project_id_;
    uint32_t jobid_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_rendering_5fjob_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// RenderingJobItem

// int32 frame = 1;
inline void RenderingJobItem::clear_frame() {
  _impl_.frame_ = 0;
}
inline int32_t RenderingJobItem::_internal_frame() const {
  return _impl_.frame_;
}
inline int32_t RenderingJobItem::frame() const {
  // @@protoc_insertion_point(field_get:RenderingJobItem.frame)
  return _internal_frame();
}
inline void RenderingJobItem::_internal_set_frame(int32_t value) {
  
  _impl_.frame_ = value;
}
inline void RenderingJobItem::set_frame(int32_t value) {
  _internal_set_frame(value);
  // @@protoc_insertion_point(field_set:RenderingJobItem.frame)
}

// string working_dir = 2;
inline void RenderingJobItem::clear_working_dir() {
  _impl_.working_dir_.ClearToEmpty();
}
inline const std::string& RenderingJobItem::working_dir() const {
  // @@protoc_insertion_point(field_get:RenderingJobItem.working_dir)
  return _internal_working_dir();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void RenderingJobItem::set_working_dir(ArgT0&& arg0, ArgT... args) {
 
 _impl_.working_dir_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:RenderingJobItem.working_dir)
}
inline std::string* RenderingJobItem::mutable_working_dir() {
  std::string* _s = _internal_mutable_working_dir();
  // @@protoc_insertion_point(field_mutable:RenderingJobItem.working_dir)
  return _s;
}
inline const std::string& RenderingJobItem::_internal_working_dir() const {
  return _impl_.working_dir_.Get();
}
inline void RenderingJobItem::_internal_set_working_dir(const std::string& value) {
  
  _impl_.working_dir_.Set(value, GetArenaForAllocation());
}
inline std::string* RenderingJobItem::_internal_mutable_working_dir() {
  
  return _impl_.working_dir_.Mutable(GetArenaForAllocation());
}
inline std::string* RenderingJobItem::release_working_dir() {
  // @@protoc_insertion_point(field_release:RenderingJobItem.working_dir)
  return _impl_.working_dir_.Release();
}
inline void RenderingJobItem::set_allocated_working_dir(std::string* working_dir) {
  if (working_dir != nullptr) {
    
  } else {
    
  }
  _impl_.working_dir_.SetAllocated(working_dir, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.working_dir_.IsDefault()) {
    _impl_.working_dir_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:RenderingJobItem.working_dir)
}

// -------------------------------------------------------------------

// ProjectFiles

// string relative_path = 1;
inline void ProjectFiles::clear_relative_path() {
  _impl_.relative_path_.ClearToEmpty();
}
inline const std::string& ProjectFiles::relative_path() const {
  // @@protoc_insertion_point(field_get:ProjectFiles.relative_path)
  return _internal_relative_path();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void ProjectFiles::set_relative_path(ArgT0&& arg0, ArgT... args) {
 
 _impl_.relative_path_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:ProjectFiles.relative_path)
}
inline std::string* ProjectFiles::mutable_relative_path() {
  std::string* _s = _internal_mutable_relative_path();
  // @@protoc_insertion_point(field_mutable:ProjectFiles.relative_path)
  return _s;
}
inline const std::string& ProjectFiles::_internal_relative_path() const {
  return _impl_.relative_path_.Get();
}
inline void ProjectFiles::_internal_set_relative_path(const std::string& value) {
  
  _impl_.relative_path_.Set(value, GetArenaForAllocation());
}
inline std::string* ProjectFiles::_internal_mutable_relative_path() {
  
  return _impl_.relative_path_.Mutable(GetArenaForAllocation());
}
inline std::string* ProjectFiles::release_relative_path() {
  // @@protoc_insertion_point(field_release:ProjectFiles.relative_path)
  return _impl_.relative_path_.Release();
}
inline void ProjectFiles::set_allocated_relative_path(std::string* relative_path) {
  if (relative_path != nullptr) {
    
  } else {
    
  }
  _impl_.relative_path_.SetAllocated(relative_path, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.relative_path_.IsDefault()) {
    _impl_.relative_path_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:ProjectFiles.relative_path)
}

// string download_url = 2;
inline void ProjectFiles::clear_download_url() {
  _impl_.download_url_.ClearToEmpty();
}
inline const std::string& ProjectFiles::download_url() const {
  // @@protoc_insertion_point(field_get:ProjectFiles.download_url)
  return _internal_download_url();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void ProjectFiles::set_download_url(ArgT0&& arg0, ArgT... args) {
 
 _impl_.download_url_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:ProjectFiles.download_url)
}
inline std::string* ProjectFiles::mutable_download_url() {
  std::string* _s = _internal_mutable_download_url();
  // @@protoc_insertion_point(field_mutable:ProjectFiles.download_url)
  return _s;
}
inline const std::string& ProjectFiles::_internal_download_url() const {
  return _impl_.download_url_.Get();
}
inline void ProjectFiles::_internal_set_download_url(const std::string& value) {
  
  _impl_.download_url_.Set(value, GetArenaForAllocation());
}
inline std::string* ProjectFiles::_internal_mutable_download_url() {
  
  return _impl_.download_url_.Mutable(GetArenaForAllocation());
}
inline std::string* ProjectFiles::release_download_url() {
  // @@protoc_insertion_point(field_release:ProjectFiles.download_url)
  return _impl_.download_url_.Release();
}
inline void ProjectFiles::set_allocated_download_url(std::string* download_url) {
  if (download_url != nullptr) {
    
  } else {
    
  }
  _impl_.download_url_.SetAllocated(download_url, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.download_url_.IsDefault()) {
    _impl_.download_url_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:ProjectFiles.download_url)
}

// -------------------------------------------------------------------

// RenderingJob

// string token = 1;
inline void RenderingJob::clear_token() {
  _impl_.token_.ClearToEmpty();
}
inline const std::string& RenderingJob::token() const {
  // @@protoc_insertion_point(field_get:RenderingJob.token)
  return _internal_token();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void RenderingJob::set_token(ArgT0&& arg0, ArgT... args) {
 
 _impl_.token_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:RenderingJob.token)
}
inline std::string* RenderingJob::mutable_token() {
  std::string* _s = _internal_mutable_token();
  // @@protoc_insertion_point(field_mutable:RenderingJob.token)
  return _s;
}
inline const std::string& RenderingJob::_internal_token() const {
  return _impl_.token_.Get();
}
inline void RenderingJob::_internal_set_token(const std::string& value) {
  
  _impl_.token_.Set(value, GetArenaForAllocation());
}
inline std::string* RenderingJob::_internal_mutable_token() {
  
  return _impl_.token_.Mutable(GetArenaForAllocation());
}
inline std::string* RenderingJob::release_token() {
  // @@protoc_insertion_point(field_release:RenderingJob.token)
  return _impl_.token_.Release();
}
inline void RenderingJob::set_allocated_token(std::string* token) {
  if (token != nullptr) {
    
  } else {
    
  }
  _impl_.token_.SetAllocated(token, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.token_.IsDefault()) {
    _impl_.token_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:RenderingJob.token)
}

// uint32 project_id = 2;
inline void RenderingJob::clear_project_id() {
  _impl_.project_id_ = 0u;
}
inline uint32_t RenderingJob::_internal_project_id() const {
  return _impl_.project_id_;
}
inline uint32_t RenderingJob::project_id() const {
  // @@protoc_insertion_point(field_get:RenderingJob.project_id)
  return _internal_project_id();
}
inline void RenderingJob::_internal_set_project_id(uint32_t value) {
  
  _impl_.project_id_ = value;
}
inline void RenderingJob::set_project_id(uint32_t value) {
  _internal_set_project_id(value);
  // @@protoc_insertion_point(field_set:RenderingJob.project_id)
}

// uint32 jobid = 3;
inline void RenderingJob::clear_jobid() {
  _impl_.jobid_ = 0u;
}
inline uint32_t RenderingJob::_internal_jobid() const {
  return _impl_.jobid_;
}
inline uint32_t RenderingJob::jobid() const {
  // @@protoc_insertion_point(field_get:RenderingJob.jobid)
  return _internal_jobid();
}
inline void RenderingJob::_internal_set_jobid(uint32_t value) {
  
  _impl_.jobid_ = value;
}
inline void RenderingJob::set_jobid(uint32_t value) {
  _internal_set_jobid(value);
  // @@protoc_insertion_point(field_set:RenderingJob.jobid)
}

// repeated .ProjectFiles files = 4;
inline int RenderingJob::_internal_files_size() const {
  return _impl_.files_.size();
}
inline int RenderingJob::files_size() const {
  return _internal_files_size();
}
inline void RenderingJob::clear_files() {
  _impl_.files_.Clear();
}
inline ::ProjectFiles* RenderingJob::mutable_files(int index) {
  // @@protoc_insertion_point(field_mutable:RenderingJob.files)
  return _impl_.files_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::ProjectFiles >*
RenderingJob::mutable_files() {
  // @@protoc_insertion_point(field_mutable_list:RenderingJob.files)
  return &_impl_.files_;
}
inline const ::ProjectFiles& RenderingJob::_internal_files(int index) const {
  return _impl_.files_.Get(index);
}
inline const ::ProjectFiles& RenderingJob::files(int index) const {
  // @@protoc_insertion_point(field_get:RenderingJob.files)
  return _internal_files(index);
}
inline ::ProjectFiles* RenderingJob::_internal_add_files() {
  return _impl_.files_.Add();
}
inline ::ProjectFiles* RenderingJob::add_files() {
  ::ProjectFiles* _add = _internal_add_files();
  // @@protoc_insertion_point(field_add:RenderingJob.files)
  return _add;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::ProjectFiles >&
RenderingJob::files() const {
  // @@protoc_insertion_point(field_list:RenderingJob.files)
  return _impl_.files_;
}

// .ProjectFiles projectFile = 5;
inline bool RenderingJob::_internal_has_projectfile() const {
  return this != internal_default_instance() && _impl_.projectfile_ != nullptr;
}
inline bool RenderingJob::has_projectfile() const {
  return _internal_has_projectfile();
}
inline void RenderingJob::clear_projectfile() {
  if (GetArenaForAllocation() == nullptr && _impl_.projectfile_ != nullptr) {
    delete _impl_.projectfile_;
  }
  _impl_.projectfile_ = nullptr;
}
inline const ::ProjectFiles& RenderingJob::_internal_projectfile() const {
  const ::ProjectFiles* p = _impl_.projectfile_;
  return p != nullptr ? *p : reinterpret_cast<const ::ProjectFiles&>(
      ::_ProjectFiles_default_instance_);
}
inline const ::ProjectFiles& RenderingJob::projectfile() const {
  // @@protoc_insertion_point(field_get:RenderingJob.projectFile)
  return _internal_projectfile();
}
inline void RenderingJob::unsafe_arena_set_allocated_projectfile(
    ::ProjectFiles* projectfile) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(_impl_.projectfile_);
  }
  _impl_.projectfile_ = projectfile;
  if (projectfile) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:RenderingJob.projectFile)
}
inline ::ProjectFiles* RenderingJob::release_projectfile() {
  
  ::ProjectFiles* temp = _impl_.projectfile_;
  _impl_.projectfile_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old =  reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(temp);
  temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  if (GetArenaForAllocation() == nullptr) { delete old; }
#else  // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArenaForAllocation() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return temp;
}
inline ::ProjectFiles* RenderingJob::unsafe_arena_release_projectfile() {
  // @@protoc_insertion_point(field_release:RenderingJob.projectFile)
  
  ::ProjectFiles* temp = _impl_.projectfile_;
  _impl_.projectfile_ = nullptr;
  return temp;
}
inline ::ProjectFiles* RenderingJob::_internal_mutable_projectfile() {
  
  if (_impl_.projectfile_ == nullptr) {
    auto* p = CreateMaybeMessage<::ProjectFiles>(GetArenaForAllocation());
    _impl_.projectfile_ = p;
  }
  return _impl_.projectfile_;
}
inline ::ProjectFiles* RenderingJob::mutable_projectfile() {
  ::ProjectFiles* _msg = _internal_mutable_projectfile();
  // @@protoc_insertion_point(field_mutable:RenderingJob.projectFile)
  return _msg;
}
inline void RenderingJob::set_allocated_projectfile(::ProjectFiles* projectfile) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete _impl_.projectfile_;
  }
  if (projectfile) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalGetOwningArena(projectfile);
    if (message_arena != submessage_arena) {
      projectfile = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, projectfile, submessage_arena);
    }
    
  } else {
    
  }
  _impl_.projectfile_ = projectfile;
  // @@protoc_insertion_point(field_set_allocated:RenderingJob.projectFile)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::ControlPackageCategory> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::ControlPackageCategory>() {
  return ::ControlPackageCategory_descriptor();
}

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_rendering_5fjob_2eproto