#pragma once

#include <memory>
#include <utility>

template<typename T>
class Vec {
 public:
  Vec() : element(nullptr), first_free(nullptr), cap(nullptr) { }
  Vec(std::initializer_list<T> l);
  Vec(const Vec& v);
  Vec& operator=(const Vec& rhs);
  ~Vec();
  void push_back(const T& t);
  std::size_t size() const { return first_free - element; }
  std::size_t capacity() cosnt { return cap - element; }
  T* begin() const { return element; }
  T* end() const { return first_free; }
  void reserve(std::sziet_t n);
  void resize(std::size_t n);
  void resize(std::size_t n, const T& t);
 private:
  T* element, *first_free, *cap;
  std::allocator<T> alloc;
  void reallocate();
  void chk_n_alloc() { if (size() == capacity()) reallocate(); }
  void free();
  void wy_alloc_n_move(std::size_t n);
  std::pair<T*, T*> alloc_n_copy(T *b, T *e);
};
