### 19.1
```c++
void *operator new(size_t size) {
  if (void *mem = malloc(size))
    return mem;
  else
    throw std::bad_alloc();
}
void operator delete(void *mem) noexcept {
  free(mem);
}
```

### 19.3
- (a) 成功
- (b) 失败，pb是指向B的指针，不能转化为指向C的指针
- (c) 失败，A*pa=new D具有二义性。

### 19.5
```c++
我们想使用基类对象的指针或引用执行某个派生类操作并且该操作不是虚函数，则可以使用RTTI运算符（该类类型应该含有虚函数）。
```

### 19.9 [prog9.cc](prog9.cc)

### 19.10 [prog10.cc](prog10.cc)
```
P1A
P1A
1A
```

### 19.11
普通的数据指针指向一个对象，类成员指针指向类的非静态成员，当初始化一个指针时，我们令其指向类的某个成员，但是不指向该成员所属的对象，直到使用成员指针时，才提供所属对象

### 19.12 [prog12.cc](prog12.cc)

### 19.13
```c++
const std::string Sales_data::*pdata;
```

### 19.14
不合法，两个函数返回值不同

### 19.15
和普通函数指针不同的是，在成员函数和指向该成员的指针之间不存在自动转换规则。

### 19.16
```c++
using AvgPrice = double (Sales_data::*)() const;
```

### 19.18 [prog18.cc](prog18.cc)

### 19.21 [prog21.cc](prog21.cc)

### 19.26
不合法，C语言不支持函数重载。
