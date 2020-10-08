### 6.1
形参不具有具体值，仅指明函数传入参数的类型，而实参则是这些类型的具体值实体，此值用于初始化形参

### 6.2
- (a) 返回值不兼容
  ```c++
  string f() {
    string s;
    // ...
    return s;
  }
  ```
- (b) 没有返回值时需要写`void`
  ```c++
  void f2(int i) { /* ... */}
  ```
- (c) 花括号少了，同时形参列表的命名不可一样
  ```c++
  int calc(inv v1, int v2) {/* ... */}
  ```
- (d) 缺少花括号
  ```c++
  double square(double x) { return x * x; }
  ```

### 6.3 [代码](prog3.cc)

### 6.4 [代码](prog4.cc)

### 6.5 [代码](prog5.cc)

### 6.6 [代码](prog6.cc)
形参是函数的输入列表，定义了调用函数时可以作为参数的类型列表，局部变量是存在于块中的变量，随着执行到定义处被创建，离开块作用域时被销毁，局部静态变量则不会随块的结束被销毁，而是在程序执行完毕之后才会被销毁。

### 6.7 [代码](prog6.cc)

### 6.8 [代码](Chapter6.h)

### 6.9 [fact.cc](fact.cc) [factMain.cc](factMain.cc)

### 6.10 [代码](prog10.cc)

### 6.11 [代码](prog11.cc)

### 6.12 [代码](prog12.cc)
更倾向于使用引用的传值，因为更简洁

### 6.13
`void f(T)`表示在函数开始时，通过拷贝构造一个变量在函数中使用，而`void f(&T)`表示在开始时通过引用传递

### 6.14
比如io类，cin和cout就只能是引用类型，因为他们没有拷贝的方法

### 6.15
- s在函数中不被改变，因此应该是常量引用，而occurs在函数执行之后需要被改变作为返回结果的一部分，因此需要是普通引用方便改变
- c在函数中是否是否被改变是外部调用者不关心的，s使用引用是为了减少拷贝大对象的开销
- 如果s是普通引用，如果函数内部改动了s，外部将可能出现未预料的行为，如果领occurs是常量引用，那么occurs在函数内部将不能被赋值，将导致编译出错

### 6.16
局限于常量引用和字符串字面值不能用作函数的实参，应该改为
`bool is_empty(const string &s) { return s.empty(); }`

### 6.17 [代码](prog17.cc)
不一样，第一个使用常量引用，第二个使用普通引用。

### 6.18
- (a) `bool compare(const matrix&, const matrix&)`
- (b) `vector<int>::iterator change_val(int, vector<int>::iterator);`

### 6.19
- (a) 不合法，函数只能传递一个参数
- (b) 合法
- (c) 合法
- (d) 合法

### 6.20
当函数内部不被改变时，使用常量引用，一方面限制了函数的场景，普通引用和字面值均无法作为参数传递，一方面在函数内部改变本不能改变的变量，将会导致未预期的行为

### 6.21
指针类型应该是`const int*`
```c++
int compareRtMax(int a, const int *pb) {
  return a > *pb ? a : *pb;
}
```

### 6.22 [代码](prog22.cc)
```c++
void exchangePtr(const int **a, const int **b) {
  const int *t = *b;
  *b = *a;
  *a = t;
}
```

### 6.23 [代码](prog23.cc)

### 6.24
传递一个包含10个元素的参数，ia，然后依次打印出ia的每个元素，错误地方在于，参数虽然定义成了`const int ia[10]`，但实际上还是`const int *ia`，`[10]`应该作为类型的一部分出现，应该改成`const int (&ia)[10]`或者`const int (*ia)[10]`

### 6.25 [代码](prog25.cc)

### 6.26 [代码](prog26.cc)

### 6.27 [代码](prog27.cc)

### 6.28
类型是`const string &`

### 6.29
应该声明成常量引用类型，因为`initializer_list`里的元素是常量，而无法改变常量的值

### 6.30 [代码](code2.cc)
错误信息是下面这样的
```
code2.cc: In function ‘bool str_subrange(const string&, const string&)’:
code2.cc:11:7: error: return-statement with no value, in function returning ‘bool’ [-fpermissive]
   11 |       return;
      |       ^~~~~~
```

### 6.31
返回函数内部定义的局部变量的引用是无效的，不管是常量还是非常量，当我们希望返回值可以被修改的时候，返回常量引用是无效的

### 6.32
合法，返回arry的第index位的引用，然后对其进行从0到10的赋值

### 6.33 [代码](prog33.cc)

### 6.34
传递负值时候，将永远无法停止递归

### 6.35
`val--`表达式返回的是val在未进行减一操作的副本，此时val本身并未改变，将导致递归无法停止

### 6.36 [代码](prog36.cc)

### 6.37 [代码](prog37.cc)
返回尾置好得多，使得代码更加清晰易懂

### 6.38
```c++
decltype(odd) &arrPtr(int i) {
  return (i%2) ? odd : even;
}
```

### 6.39
- 非法，顶层const不影响传入函数的对象，因此第二个声明无法与第一个声明区分开
- 非法，重载下，函数返回值是不能区分两个函数的
- 合法，输入参数不一样，也不能相互转化

### 6.40
(b)是错误的，参数列表中，给一个形参以默认实参，那么这个形参之后的所有形参都需要指定默认实参

### 6.41
a是非法的，至少要传递ht，b是合法的，c是合法但与初衷不符，因为发生了`wd='*'`

### 6.42 [代码](prog42.cc)

### 6.43
都放在头文件中，因为(a)是内联函数，(b)是函数声明

### 6.44
```c++
inline bool is_shorter(const string &lft, const string &rht)  {
    return lft.size() < rht.size();
}
```

### 6.45
应该是内联函数，内联机制通常被用于优化规模小，流程简单，频繁调用的函数

### 6.46
不能，因为直到程序运行，才可以知道返回的是`true`还是`false`，函数内部，所有形参和返回值都得是字面值

### 6.47 [代码](prog47.cc)

### 6.48
持续执行，直到遇到EOF，此时cin是无效的，assert里cin是false，使用assert不合理，应该改为`assert(sought == s)`

### 6.49
在函数重载的场景中，候选函数是在调用点可见的函数，可行函数是形参与实参的数量相等，并且每个实参类型与形参类型相同，或者能隐式转换成形参类型

### 6.50
- (a) `f(2.56, 42)`具有二义性
- (b) `f(42)`匹配`f(int)`
- (c) `f(42, 0)`匹配`f(int,int)`
- (d) `f(2.56,3.14)`匹配`f(double,double)`

### 6.51 [代码](prog51.cc)

### 6.52
- (a) 整型提升，char提升成为int，级别为3
- (b) 算术类型转化，double转化成int型，级别为4

### 6.53
(c)不合法，顶层const不影响函数的形参类型

### 6.54
```c++
int func(int,int);
vector<int (*)(int, int)>
vector<decltype(func)*>
```

### 6.55&6.56 [代码](prog55.cc)

