#pragma once

#include <memory>
#include <string>
#include <utility>
#include <algorithm>

class StrVec {
 public:
  StrVec() :
    elements(nullptr), first_free(nullptr), cap(nullptr) { }
  StrVec(std::initializer_list<std::string> il) {
    auto newdata = alloc_n_copy(il.begin(), il.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
  }
  StrVec(const StrVec& s) {
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
  }
  StrVec(StrVec &&s) noexcept : elements(s.elements),
    first_free(s.first_free), cap(s.cap) {
      s.elements = s.first_free = s.cap = nullptr;
  }
  StrVec &operator=(const StrVec &rhs) {
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
  }
  StrVec &operator=(StrVec &&rhs) noexcept {
    if (this != &rhs) {
      free();
      elements = rhs.elements;
      first_free = rhs.first_free;
      cap = rhs.cap;
      rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
  }
  ~StrVec() {
    free();
  }
  void push_back(const std::string &s) {
    chk_n_alloc();
    alloc.construct(first_free++, s);
  }
  void push_back(std::string &&s) {
    chk_n_alloc();
    alloc.construct(first_free++, std::move(s));
  }
  size_t size() const {
    return first_free - elements;
  }
  size_t capacity() const {
    return cap - elements;
  }
  std::string* begin() const {
    return elements;
  }
  std::string* end() const {
    return first_free;
  }
  void resize(size_t n) {
    if (n < size()) {
      --first_free;
      for (; first_free-elements != n; --first_free) {
        alloc.destroy(first_free);
      }
      alloc.destroy(first_free);
      return;
    }
    while (n > capacity()) {
      reallocate();
    }
    for (; first_free-elements !=  n; ++first_free) {
      alloc.construct(first_free);
    }
  }
  void reverse(size_t n) {
    while (capacity() < n) {
      reallocate();
    }
  }

 private:
  static std::allocator<std::string> alloc;
  void chk_n_alloc() {
    if (size() == capacity()) {
      reallocate();
    }
  }
  void free() {
    if (elements) {
      std::for_each(elements, first_free,
        [](std::string* p){ alloc.destroy(p); });
      for (auto p = first_free; p != elements;) {
        alloc.destroy(--p);
      }
      alloc.deallocate(elements, cap-elements);
    }
  }
  void reallocate() {
    auto newcapacity = size() ? 2 * size() : 1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = std::uninitialized_copy(std::make_move_iterator(begin()),
      std::make_move_iterator(end()), newdata);
    // auto elem = elements;
    // for (size_t i = 0; i != size(); ++i) {
    //   alloc.construct(dest++, std::move(*elem++));
    // }
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
  }
  std::pair<std::string*, std::string*>
  alloc_n_copy(const std::string *b, const std::string *e) {
    auto data = alloc.allocate(e-b);
    return {data, std::uninitialized_copy(b, e, data)};
  }
  std::string *elements, *first_free, *cap;
};
