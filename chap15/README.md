### 15.1
对于某些函数，基类希望它的派生类各自定义适合自身的版本，此时基类就将这些函数声明成虚函数。

### 15.2
定义为protected和private的成员均不可从外部直接访问，在继承关系中，protected的成员可被派生类访问，而private的成员则不可以

### 15.3 [Quote.h](Quote.h)

### 15.4
- (a) 不正确，基类未定义完全，不可继承自己
- (b) 不正确，这是定义而非声明。
- (c) 不正确，此处只是类声明，类声明不能包含类派生列表的定义部分

### 15.5 [Bulk_quote.h](Bulk_quote.h)

### 15.6 [prog6.cc](prog6.cc)

### 15.7 [Bulk_quote2.h](Bulk_quote2.h)

### 15.8
表达式的静态类型在编译时总是已知的，它是变量声明时的类型或表达式生成的类型。动态类型则是变量或表达式表示的内存中的对象的类型。动态类型直到运行时才可知。

### 15.9
基类的指针或引用的静态类型可能与其动态类型不一致。

### 15.10
`std::ifstream`是`std::istream`的派生基类，因此 read 函数能够正常工作。

### 15.11 [Quote.h](Quote.h) [Bulk_quote.h](Bulk_quote.h)

### 15.12
可以的，声明为override说明该函数覆盖了直接基类的虚函数，声明为final意味着，以该类作为基类的派生类不可覆盖此虚函数

### 15.13
有问题，派生类的print(os)将会导致调用自身无限递归，将其改为 base::print(os);

### 15.14
基类：a, c, d, e
派生类：b, f

### 15.15 [Disc_quote.h](Disc_quote.h) [Bulk_quote3.h](Bulk_quote3.h)

### 15.17 [prog17.cc](prog17.cc)
```
prog17.cc:4:14: error: cannot declare variable ‘dq’ to be of abstract type ‘Disc_quote’
    4 |   Disc_quote dq("123", 0.1, 1, 0.1);
      |              ^~
In file included from prog17.cc:1:
```

### 15.19
合法：Pub_Derv、Priv_Derv、Prot_Derv、Derived_from_Public、Derived_from_Protected
不合法：Derived_from_Private

### 15.23
移除fcn的int参数即可

### 15.24
因为Disc_quote的默认构造函数会运行Quote的默认构造函数，而Quote默认构造函数会完成成员的初始化工作。 如果去除掉该构造函数的话，Bulk_quote的默认构造函数而无法完成Disc_quote的初始化工作。

### 15.25 [Quote2.h](Quote2.h) [Bulk_quote4.h](Bulk_quote4.h)

### 15.28 [prog28.cc](prog28.cc)

### 15.29 [prog29.cc](prog29.cc)

### 15.30 [Basket.h](Basket.h) [prog30.cc](prog30.cc)

### 15.31
- a) OrQuery, AndQuery, NotQuery, WordQuery
- b) OrQuery, AndQuery, NotQuery, WordQuery
- c) OrQuery, AndQuery, WordQuery

### 15.32
**拷贝：**当被拷贝时，合成的拷贝构造函数被调用。它将拷贝两个数据成员至新的对象。而在这种情况下，数据成员是一个智能指针，当拷贝时，相应的智能指针指向相同的地址，计数器增加1.
**移动：**当移动时，合成的移动构造函数被调用。它将移动数据成员至新的对象。这时新对象的智能指针将会指向原对象的地址，而原对象的智能指针为 nullptr，新对象的智能指针的引用计数为 1.
**赋值：**合成的赋值运算符被调用，结果和拷贝的相同的。
**销毁：**合成的析构函数被调用。对象的智能指针的引用计数递减，当引用计数为 0 时，对象被销毁。

### 15.33
由合成的版本来控制。然而 Query_base 是一个抽象类，它的对象实际上是它的派生类对象。

### 15.35 [Query.h](Query.h) [Query_base.h](Query_base.h)

### 15.38
1. 不合法。因为 BinaryQuery 是抽象类。
1. 不合法。& 操作返回的是一个 Query 对象。
1. 不合法。& 操作返回的是一个 Query 对象。
