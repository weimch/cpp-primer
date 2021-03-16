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
