#pragma once

#include <vector>
#include <memory>
#include <string>
#include <utility>
#include <initializer_list>
#include <stdexcept>

template<typename> class BlobPtr;
template<typename> class Blob;
template<typename T>
bool operator==(const Blob<T>&, const Blob<T> &);

template<typename T>
class Blob {
  friend class BlobPtr<T>;
  friend bool operator==<T>(const Blob<T>&, const Blob<T>&);
 public:
  typedef T value_type;
  typedef typename std::vector<T>::size_type size_type;
  // 构造函数
  Blob();
  Blob(std::initializer_list<T> il);
  template<typename It>
  Blob(It beg, It end);
  // Blob中元素数目
  size_type size() const { return data->size(); }
  bool empty() const { return data->empty(); }
  // 添加和删除元素
  void push_back(const T &t) { data->push_back(t); }
  // 移动版本
  void push_back(const T &&t) { data->push_back(std::move(t)); }
  void pop_back();
  // 元素访问
  T& back();
  T& front();
  T& operator[](size_type i);
 private:
  std::shared_ptr<std::vector<T>> data;
  void check(size_type i, const std::string &msg) const;
};

template<typename T>
void Blob<T>::check(size_type i, const std::string &msg) const {
  if (i >= data->size()) throw std::out_of_range(msg);
}

template<typename T>
T& Blob<T>::back() {
  check(0, "back on empty Blob");
  return data->back();
}

template<typename T>
T& Blob<T>::front() {
  check(0, "front on empty Blob");
  return data[0];
}

template<typename T>
T& Blob<T>::operator[](size_type i) {
  check(i, "subscript out of range");
  return (*data)[i];
}

template<typename T>
void Blob<T>::pop_back() {
  check(0, "pop_back on empty Blob");
  data->pop_back();
}

template<typename T>
Blob<T>::Blob() : data(std::make_shared<std::vector<T>>()) { }

template<typename T>
Blob<T>::Blob(std::initializer_list<T> il) :
  data(std::make_shared<std::vector<T>>(il)) { }

template<typename T>
template<typename It>
inline Blob<T>::Blob(It beg, It end) :
  std::make_shared<std::vector<T>>(beg, end) { }
