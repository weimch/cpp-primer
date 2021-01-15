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

### 7.26 [prog26.h](prog26.h)

### 7.27 [Screen.h](prog27.h) [prog27.c](prog27.c)

### 7.28 & 7.29
move函数将不会成功，set函数将会设置第一个字符为'#'，dispaly将会展示该修改后的副本，原始的myScreen将不会被改变
XXXXXXXXXXXXXXXXXXXX#XXXX
XXXXXXXXXXXXXXXXXXXXXXXXX

### 7.30
优点是显示地指明了该成员是类成员，且函数的参数可以与成员同名，缺点是略显冗杂

### 7.31 [prog31.h](prog31.h)

### 7.32 [prog32.h](prog32.h)

### 7.33
未定义标识符 pos，应该修改成为
```c++
Screen::pos Screen::size() const {
  return height * width;
}
```

### 7.34
会使得`dummy_fcn(pos height)`函数出现**未定义的标识符pos**

类型名的定义通常出现在类的开始指出，这样就能确保所有使用该类型的成员都出现在类名的定义之后。

### 7.35
```c++
typedef string Type;
Type intVal(); // 使用了string定义
class Exercise {
 public:
  typedef double Type; // 使用了double定义
  Type setVal(Type); // 使用了double定义
  Type initVal(); // 使用了double定义
 private:
  int val;
};
Type Exercise::setVal(Type parm) { // 返回值使用了string定义, 参数表使用了double定义, 因此类中并未定义该函数报错, 更正方法是将返回值类型变成 Exercise::Type
  val = parm + initVal();
  return val;
}
```

### 7.36
```c++
struct X {
  X (int i, int j) : base(i), rem(base % j) {}
  int rem, base; // 先是rem进行初始化，才是base进行初始化，因此，将此处声明的rem和base调换顺序即可
}
```

### 7.37
构造函数为：
```c++
class Sales_data {
 public:
  Sales_data(std::string s = "") : bookNo(s) {} //1
  Sales_data(std::string s, unsigned cnt, double rev) : bookNo(s), units_sold(cnt), revenue(rev*cnt) {} // 2
  Sales_data(std::istream &is) { read(is, *this); } //3
}
```
初始化时使用了哪个构造函数
```c++
Sales_data first_item(cin); // 3 值为输入的值
int main() {
  Sales_data next; // 1 值为空白字符
  Sales_data last("9-999-99999-9); // 1 值为9-999-99999-9
}
```

### 7.38
```c++
Sales_dta(std::istream &is = std::cin) { read(is, *this); };
```

### 7.39
不合法，因为此时当不传入参数的时候，就不知道应该调用哪个构造函数的重载了

### 7.40
开放式回答，选择Book
```c++
class Book {
 public:
  Book(std::string isbn, std::string title, std::string author) : isbn_(isbn), title_(title), author_(author) {}
  explicit Book(std::istream &in) { 
    in >> isbn_ >> title_ >> author_;
  }
 private:
  std::string isbn_, title_, author_;
}
```

### 7.41 [prog41.h](prog41.h)


### 7.42
```c++
class Book {
 public:
  Book(std::string isbn, std::string title, std::string author) : isbn_(isbn), title_(title), author_(author) {}
  explicit Book(std::istream &in) : Book("", "", "") {
    in >> isbn_ >> title_ >> author_;
  }
 private:
  std::string isbn_, title_, author_;
}
```

### 7.43 [prog43.cc](prog43.cc)

### 7.44
不合法，因为NoDefault没有默认构造函数

### 7.45
合法，因为C有默认构造函数

### 7.46
- (a) 不正确，可以不提供构造函数，由编译器为其自动生成一个默认构造函数
- (b) 不完全正确，为每个参数都提供了初始值的构造函数也是默认构造函数
- (c) 不正确，哪怕没有意义，也要进行初始化
- (d) 不正确。只有当一个类没有定义任何构造函数的时候，编译器才会生成一个默认构造函数。

### 7.47
应该是explicit，这样可以抑制构造函数定义的隐式转换

### 7.48
这些定义和是不是explicit的无关，并未发生隐式转换

### 7.49
如果有包含string参数的构造函数，那么将会隐式转换string成为Sales_data对象，如果此时用explicit来声明构造函数，则此时将会编译失败

### 7.51
vector不用explicit的话，那么隐式转换将仅创建一个空的动态数组，没有意义，而凡是在需要用到string 的地方都可以用 const char * 来代替

### 7.52
聚合类要求所有成员都是public的，没有定义构造函数，没有类内初始值，没有virtual函数，因此应该修改为
```c++
struct Sales_data {
  std::string bookNo;
  unsigned units_sold;
  double revenue;
};
```

### 7.53 [prog53.h](prog53.h)

### 7.54
不可以，因为将会修改成员的值，而如果声明成了constexpr，需要返回一个常量表达式

### 7.55
不是。因为 std::string 不是字面值类型。

### 7.56
类的静态成员是和类相关联的成员，并不属于类对象的一部分，可以通过类域运算符和类对象的引用和指针访问，在使用前必须先被定义，比起普通成员来说，类静态成员可以是不完全类型，而普通成员必须要是完全类型，同时类静态成员可以作为默认实参，而普通成员则不可以。

### 7.57 [prog57.h](prog57.h) [prog57.cc](prog57.cc)

### 7.58
```c++
// example.h
class Example {
 public:
  static double rate = 6.5; // 静态数据成员定义在类内部初始化时，需要是const或者constexpr
  static const int vecSize = 20;
  static vector<double> vec(vecSize); //而类内只能初始化整型类型的静态常量，所以不能在类内初始化vec。
}
// exmpale.cc
#include "example.h"
double Example::rate;
vector<double> Example::vec;
```
因此应该改成
```c++
// example.h
class Example {
 public:
  static constexpr double rate = 6.5;
  static const int vecSize = 20;
  static vector<double> vec;
}
// exmpale.cc
#include "example.h"
constexpr double Example::rate;
vector<double> Example::vec(Example::vecSize);
```