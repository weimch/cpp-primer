### 7.1 [prog1.cc](prog1.cc)

### 7.2 [Sales_data.h](Sales_data.h) [Sales_data.cc](Sales_data.cc)

### 7.4 [Person.h](Person.h)

### 7.5 [Person.h](Person.h)
应该是const，因为const的Person对象也需要这些函数

### 7.6&7.7 [Sales_data.cc](Sales_data.cc)

### 7.8
在`read`函数内对`Sales_data`对象进行了修改，因此使用普通引用，而`print`中则没有修改，使用const引用更能提高代码灵活性

### 7.9 [Person.h](Person.h)

### 7.10
先读取`data1`，再读取`data2`，`if`用于判断是否读取成功

### 7.11
- [头文件](prog11.h)
- [cc文件](prog11.cc)

### 7.12 [prog12.h](prog12.h)

### 7.13 [prog13.cc](prog13.cc)

### 7.14
```c++
Sales_data() : units_sold(0) , revenue(0) { }
```

### 7.15 [prog15.cc](prog15.cc)

### 7.16
没有限定，能被使用类代码使用的成员应该定义再public说明符之后，而仅类内部使用的成员定义再private说明符之内。

### 7.17
唯一区别是默认访问级别不同，struct默认是public，class是private

### 7.18
将类的部分成员设置为外部不可见，而提供部分接口给外部，这种行为叫封装，封装隐藏了具体的实现，当我们使用某个抽象数据类型时，只需要考虑它提供什么接口操作，而不用考虑它的具体实现。

### 7.19
- 构造函数和get_name/get_addr声明成public，外部代码可以通过此来访问数据成员
- 数据成员声明成private，因为除了类接口，不想让外部代码来改变

### 7.20
友元在外部函数调用类的private数据成员时候使用，好处是，与当前类有关的接口函数能够直接访问类的私有变量，坏处是破坏了类的封装性

### 7.21 [prog21.h](prog21.h) [prog21.cc](prog21.cc)

### 7.22 [prog22.h](prog22.h)

### 7.23 [prog23.h](prog23.h)

### 7.24 [prog24.h](prog24.h)

### 7.25
可以依赖，因为其内部成员都是内置类型和string，可以安全的使用默认拷贝和赋值操作
动态内存管理类则不能使用默认拷贝和赋值，如果想避免实现自己的拷贝和赋值操作，类成员应该尽可能的使用内置类型或标准库，标准库的拷贝和赋值是已经定义好了的