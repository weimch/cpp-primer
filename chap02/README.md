2.1
- int/long/long long/short都是表示整型，但他们所占据的字节不一样，也即，数值范围不一样
- 无符号类型一定大于0，有符号类型最高比特位为符号位，因此，只要你所需要的整数取值大于0，应该使用无符号类型可表示的数值越大
- float和double也是占的比特不同，精度也不一样，但是他们两的运算速度是相同的，在使用中，float精度不够，而通常优先考虑double

2.2 使用浮点型，double或者float

2.3 & 2.4 [代码](prog2-4.cc)
- u2 - u = 32
- u - u2 = 4294967264
- i2 - i = 32
- i - i2 = -32
- i - u = 0
- u - i = 0

2.5 
- 'a'(char), L'a'(wchar_t), "a"(字符串字面值), L"a"(宽字符串字面值)
- 10(int), 10u(unsigned int), 10L(long), 10uL(unsigned long), 012(int 8进制字面值), 0xC(int 16进制字面值)
- 3.14(double), 3.14f(float), 3.14L(long double)
- 10(int), 10u(unsigned int), 10.(double), 10e-2(double 科学计数法)

2.6 有区别，第一组是以10进制字面值，而第二组是8进制字面值，赋的值不一样

2.7 
- 字符串字面值，`\145`表示以8进制为基础对应的字符`e`，`\012`对应换行符，因此字面值为`"Who goes with Fergus?\n"`
- 3.14e1L(long double)
- 1024f无效，`f`仅能用于修饰浮点型，`1024`是整数类型
- 3.14L(3.14的long double类型)

2.8 [代码](prog2-8.cc)

2.9
- (a) std::cin >> int input_value; int input_value; std::cin >> input_value
- (b) int i = {3.14}; 列表初始化时候，如果信息丢失，编译器将报错 double i = {3.14}
- (c) double salary = wage = 9999.99; wage未定义, double wage = 9999.99, salary = wage;
- (d) int i = 3.14; 没问题，但小数部分会被截断

2.10 `global_str`值是`""`, `global_int`是`0`, `local_int`未定义而`local_str`使用了默认构造器值为`""`

2.11 (a)定义 (b)定义 (c)声明

2.12 a, c, d 非法

2.13 j = 100

2.14 100 45

2.15
- int ival = 1.01 合法
- int &rval1 = 1.01 不合法，字面值不是对象，不可引用
- int &rval2 = ival 合法，引用类型和原始类型严格匹配
- int &rval3; 不合法，引用类型必须初始化

2.16
- 合法，将d赋值为3.14159
- 合法，将i赋值double类型的0
- 合法，将i赋值double类型的0
- 合法，将i赋值double类型的0

2.17 [代码](prog2-17.cc)，结果是输出10

2.18 [代码](prog2-18.cc)

2.19 指针和引用都是符合类型，用于某一对象的间接访问，不同的是，指针是一个对象，存储对象的地址，并可以改变所指向的对象，但是引用只是别名，不是一个对象，一经初始化之后，就不可绑定到其他对象

2.20 将i的值变成42*42

2.21
- (a) 非法，指针绑定类型和赋值类型不同
- (b) 非法，不能直接将int类型赋值给指针，需要加`&`取地址符号
- (c) 合法

2.22 判断指针是否为空，以及判断指针所指对象是否不为0

2.23 不能知道是否指向合法的对象，顶多只能判断其是否为空

2.24 `void*`可以绑定任意类型的数据，`long *lp`只能以`long`类型的对象来取地址赋值

2.25
- 指向int类型的指针pi，int类型的i，int类型的引用r
- int类型的i，指向int的指针pi，并将pi初始化为空指针
- int类型的指针ip，int类型的ip2

2.26 
- 不合法，const必须初始化
- 合法
- 合法
- 不合法，sz是常量，常量不可改变

2.27
```c++
int i = -1, &r = 0;         // 不合法, r 必须引用一个对象
int *const p2 = &i2;        // 合法
const int i = -1, &r = 0;   // 合法
const int *const p3 = &i2;  // 合法
const int *p1 = &i2;        // 合法
const int &const r2;        // 不合法, r2 是引用，引用没有顶层 const
const int i2 = i, &r = i;   // 合法
```

2.28
```C++
int i, *const cp; // cp是一个常量指针，不合法，作为常量必须初始化
int *p1, *const p2; // 不合法，理由同上
const int ic, &r = ic; // 不合法，const int必须初始化
const int *const p3; //不合法
const int *p; // 合法，指向常量的指针
```

2.29
- i=ic; 合法
- p1 = p3; 不合法，指向常量的指针赋值给指向非常量的指针
- p1 = &ic; 不合法
- p3 = &ic; 合法
- p2 = p1; 合法
- ic = *p3; 合法

2.30 v2是顶层，p2是底层，p3是顶层和底层，r2是底层

2.31
```C++
r1 = v2; // 合法
p1 = p2; // 不合法，底层const不一样
p2 = p1; // 合法，int*可以转化为const int*
p1 = p3; // 不合法
p2 = p3; // 合法，底层cosnt是一样的
```

2.32 不合法，将int变量赋值给指针，即使他的值是常量，也是错误的，应该改成下面这样
```c++
int null = 0, *p = 0;
```

2.33
```c++
a=42; // a是一个int
b=42; // b是一个int，位于顶层的const被忽略
c=42; // c是一个int
d=42; // d是一个int*，非法语句
e=42; // e是一个const int*，非法语句
f=42; // f是const int，非法赋值语句
g=42; // g是const int &，非法赋值语句
```

2.34 [代码](prog2-34.cc)

2.35 [代码](prog2-35.cc)

2.36 c是int，d是引用类型，引用对象是a，结束时候，a=4，b=4，c=4，d=4

2.37 c是int类型，d是引用类型，a=c=d=3，b=4

2.38 正常变量的情况下，由decltype组成的类型，顶层const和引用将会被保留，而auto则不会保留，比如下面
```C++
// 不一样的
const int a = 1;
auto b = a; // b 是int型
decltype(a) c = a; // c是const
int &d = a; // d是a的引用
auto e = d; // e是int型
decltype(d) f = a; // f是a的引用
// 一样的
int a = 1;
auto b = a;
decltype(a) c = a; // c和b都是int类型
```

2.39 [代码](prog2-39.cc)，如果忘记写分号，将会报错如下
```
.\prog2-39.cc:1:15: error: expected ';' after struct definition
 struct Foo { }
               ^
               ;
```

2.40 [代码](Sales_data.h)




