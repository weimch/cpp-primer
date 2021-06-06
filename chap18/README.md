### 18.1
- (a) range_error
- (b) exception
如果(b)写成throw p，则抛出指向局部对象的指针，将发生错误。

### 18.2
对象`v`和`in`将被析构，但是`p`为`int*`类型，无法调用析构函数，引起内存泄漏

### 18.3
- 将p定义为类，并设置析构函数
```c++
struct P {
  int *p = nullptr;
  P(std::size_t n) : p(new int[n]) {}
  ~P() { delete [] p; }
}
```
- 使用智能指针
```c++
std::shared_ptr<int> p(new int[v.size()], [](int*p){delete p});
```

### 18.4
越是位于继承链底端的类，越应该放置于catch的前面
```c++
try {

} catch(overflow_error eboj) {

} catch(const runtime_error &re) {

} catch(exception) {

}
```

### 18.5
```c++
int main() {
  try {

  } catch(...) {
    abort();
  }
}
```

### 18.6
- (a) `throw pet;`
- (b) 可以捕获所有异常
- (c) throw 1;

### 18.10
当出现一个未被捕获的异常时，程序将会执行terminate

### 18.11
waht中如果抛出异常，需要try-catch捕获，再调用what，将会一直循环，直到内存耗尽

### 18.13
在需要在其所在的文件中可见，在其所在的文件外不可见时。

### 18.14
```c++
mathLib::MatrixLib::matrix mathLib::MatrixLib::matrix::operator*(const matrix &, const matrix &);
```

### 18.15
using指示一次性将命名空间的所有声明都提升到当前的作用域中，造成命名空间污染，而using指示可以专门引入几个声明来直接使用，对检测并修改错误大有益处。

### 18.16
using声明
- 位置1，在`ivar`定义出错
- 位置2，在`dvar`定义出错
using指示
- 位置1，在`ivar`使用时出错
- 位置2，在`ivar`使用时出错

### 18.17 [prog17.cc](prog17.cc)

### 18.20
分别使用`string`和`int`的实例化版本

### 18.19
将只使用标准库的swap，如果v1.mem1和v2.mem1为用户自定义类型，将无法使用用户定义的针对该类型的swap。

### 18.20
候选函数，所有函数

可行函数：
```c++
compute(const void*);
compute(int);
compute(double, double=3.4);
compute(char*, char*=0);
```
其中，`compute(int)`为最佳匹配。

如果把using声明放在调用点之前，则`compute(const void*)`为最佳匹配，因为在函数的块作用域内，只有一个`compute`函数，且该函数的参数匹配（`int`转化为`const void*`）。

### 18.21
- (a) Vehicle应该使public继承，这里用成了默认的private继承
- (b) 错误，出现了重复继承
- (c) 正确，以public方式继承了istream和ostream

### 18.22
A->B->C->X->Y->Z->MI

### 18.23
都允许

### 18.24
- pe->print() 正确；
- pe->highlight() 错误；
- pe->toes() 错误；
- pe->duddle() 错误；
- delete pe 正确。

### 18.25
- (a),(b),(c)->MI::print();
- (d),(e),(f)->MI::~MI();

### 18.26 [prog26.cc](prog26.cc)
没有匹配的print调用，当注释void print(std;:vector)时又会出现二义性；故为该函数定义一个新版本。

### 18.27
- (a) Base1中，ival、dval、cval、print；Base2中，fval、print；Derived中，sval、dval、print；MI中，ival，dvec，print、foo。
- (b) 存在，ival、dval、print。
- (c)、(d)、(e)
```c++
void MI::foo(double cval) {
  int dval;
  dval = Base1::dval + Derived::dval;
  Base2::fval = dvec.back();
  sval.at(0) = Base1::cval;
}
```

### 18.28
- 直接访问：ival,bar
- 加限定符：cval,foo

### 18.29
(a) 构造函数顺序和析构函数顺序是相反的，下面只列出构造函数的顺序。
- Class
- Base
- D1
- D2
- MI
- Class
- Final

(b) 1个Base子对象，2个Class子对象

(c) a/b/c均编译错误

### 18.30 [prog30.cc](prog30.cc)
