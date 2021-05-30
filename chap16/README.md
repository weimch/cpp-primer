### 16.1
当编译器实例化一个模版时，它使用实际的模版参数代替对应的模版参数来创建出模版的一个新“实例”。

### 16.2 [prog2.cc](prog2.cc)

### 16.3
```
prog2.cc:6:10: error: no match for ‘operator<’ (operand types are ‘const Sales_data’ and ‘const Sales_data’)
    6 |   if (t1 < t2) return 1;
      |       ~~~^~~~
```

### 16.4
```c++
template<typename Iterator, typename Value>
Iterator find(Iterator first, Iterator last, const Value& v)
{
	for ( ; first != last && *first != value; ++first);
	return first;
}
```

### 16.5
```c++
template<typename Array>
void print(const Array &arr) {
  for (auto elem : arr) {
    cout << elem << endl;
  }
}
```

### 16.6
```c++
template<typename T, unsigned U>
T* begin(const T (&arr)[U]) {
  return arr;
}
template<typename T, unsigned U>
T* end(const T (&arr)[U]) {
  return arr + N;
}
```

### 16.7
```c++
template<typename T, unsigned N> constexpr
unsigned size(const T (&arr)[N]) {
	return N;
}
```

### 16.8
因为大多数类只定义了 != 操作而没有定义 < 操作，使用 != 可以降低对要处理的类型的要求。

### 16.9
一个函数模板就是一个公式，可以用来生成针对特定类型的函数版本。类模板是用来生成类的蓝图，与函数模板不同之处在于，编译器不能为类模板推断模板参数类型。如我们已经多次看到，为了使用类模板，必须在尖括号后提供额外信息。

### 16.10
一个类模板的每个实例都形成一个独立的类

### 16.11
```c++
template<typename elemType> class ListItem;
template<typename elemType> class List {
 public:
  List();
  List(const List&);
  List& operator=(const List<elemType>&);
  ~List();
  void insert(ListItem<elemType> *ptr, elemType value);
 private:
  ListItem<elemType> *front, *end;
};
```

### 16.12 [prog12-Blob.h](prog12-Blob.h) [prog12-BlobPtr.h](prog12-BlobPtr.h)

### 16.13
选择一对一友好关系

### 16.14&16.15 [prog14-Screen.h]
类的 operator<< 和 operator>> 应该是类的友元。

### 16.16 [Vec.h](Vec.h)

### 16.17
没有什么不同，当我们需要通知编译器一个名字表示类型时候，必须使用关键字typename，而不能使用class

### 16.18
- a) 非法，`template <typename T, typename U, typename V> void f1(T, U, V);`
- b) 非法，`template <typename T> T f2(T&);`
- c) 非法，`template <typename T> inline T foo(T, unsigned int*);`
- d) 非法，`template <typename T> void f4(T, T);`
- e) 非法，Ctype 被隐藏了

### 16.19 [prog19.cc](prog19.cc)

### 16.20 [prog20.cc](prog20.cc)

### 16.21 [prog21-DebugDelete.h](prog21-DebugDelete.h)

### 16.24 [prog24-Blob.h](prog24-Blob.h)

### 16.25
前者是模板声明，后者是实例化的定义

### 16.26
对vector的有些初始化函数来说是不可以的，比如传递一个给定vector大小的数值的构造函数，需要调用模板实例的默认构造函数

### 16.27
(a)、(b)、(c)、(f) 都发生了实例化，(d)、(e) 没有实例化。

### 16.32
在模板参数实参推断过程中，编译器使用函数调用中的实参类型来寻找模板实参，使用这些实参生成的函数版本与给定的函数调用最匹配

### 16.33
- a) 不合法，compare(const char (&str)[2], const char (&str)[4])
- b) 合法，compare(const char (&str)[3], const char (&str)[3])

### 16.34
从非const到const的转换，从数组或函数到指针的转换，其中数组转换为指向首元素的指针，函数转换为函数指针

### 16.35
- a) 合法，类型是char
- b) 合法，类型是double
- c) 合法，类型是char
- d) 不合法

### 16.36
- a) f1(int*,int*)
- b) f2(int*,int*)
- c) f1(const int*,const int*)
- d) f2(const int*,const int*)
- e) 不合法，类型不匹配
- f) f2(int*,const int*)

### 16.37
可以提供显示的模板实参来调用

### 16.38
如果不显示提供模版实参，那么make_shared无法推断要分配多大内存空间。

### 16.39
```c++
compare<std::string>("hello", "world")  
```

### 16.40
合法，返回一个右值引用，传入的实参类型需要支持+的操作

### 16.41
```c++
template<typename T>
auto sum(T lhs, T rhs) -> decltype(lhs + rhs) {
  return lhs + rhs;
}
```
### 16.42
- val类型为`int&`，T类型为`int&`
- val类型为`const int&`，T类型为`const int&`
- val类型为`int`，T类型为`int&&`

### 16.43
`i=ci`将会返回指向i的引用类型`int&`，因此，g的模板参数为`int&`

### 16.44
如果g的参数声明为`T`，则
- (a) int  
- (b) const int
- (c) int

如果为const T&，则
- (a) int  
- (b) int
- (c) int

### 16.45
`42`字面值常量调用g，和传递一个右值引用现象一致，T的值被解析为int

而当使用一个`int类型的变量`时，T为`int&`，发生引用折叠，最终val类型为`int&`，使得`vector<int&>`将会发生编译错误。

### 16.46
在每个循环种，对elem的解引用操作*当中，会返回一个左值，`std::move`函数将该左值转换为右值，提供给`construct`函数。

### 16.47
```c++
template<typename F, typename T1, typename T2>
void filp(F f, T1&& t1, T2&& t2) {
  f(std::forward<T2>(t2), std::forward<T1>(t1));
}
```

### 16.48
```c++
template<typename T> std::string debug_rep(const T& t) {
  std::ostringstream ret;
  ret << t;
  return ret.str();
}

template<typename T> std::string debug_rep(T* p) {
  std::ostringstream ret;
  ret << "pointer: " << p;
  if (p) 
    ret << " " << debug_rep(*p);
  else
    ret << " null ponter";
  return ret.str();
}
```

### 16.49
- g(42);  // g(T);
- g(p);   // g(T*);
- g(ci);  // g(T);
- g(p2);  // g(T*);
- f(42);  // f(T);
- f(p);   // f(T);
- f(ci);  // f(T);
- f(p2);  // f(const T*);

### 16.53 [prog53.cc](prog53.cc)

### 16.54
将会发生编译错误。

### 16.55
将会无限递归，导致以下编译错误。
```bash
error: no matching function for call to ‘print(std::ostream&)’
```

### 16.56
```c++
template<typename... Args>
ostream &errorMsg(ostream &os, const Args&... rest) {
  return print(os, debug_rep(rest)...);
}
```

### 16.57
可变参数版本有更好的灵活性，可变参数部分不限于同一种类型。

### 16.59
会在 construst 函数中转发扩展包。

### 16.60
make_shared 是一个可变模版函数，它将参数包转发然后构造一个对象，再然后一个指向该对象的智能指针。

### 16.61
```c++
template<typename T, typename... Args>
auto make_shared(Args&&... args) -> std::shared_ptr<T> {
  return std::shared_ptr<T>(new T(std::forward<Args>(args)...));
}
```
### 16.62 [prog62.h](prog62.h)

### 16.63 [prog63.cc](prog63.cc)

### 16.66
会改变函数匹配顺序，几个函数都提供同样好的匹配的情况下，编译器会选择非模板版本。

### 16.67
不会改变，特例化模板函数不会重载函数，不会影响函数匹配顺序。
