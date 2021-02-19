### 13.1
拷贝构造函数能定义从一个对象创建另一个对象的行为，在赋值或者函数参数和返回值非引用时会被调用

### 13.2
传递参数为非引用类型，那么，为了传入一个`Sales_data`的`rhs`，需要进行拷贝构造，将会引起无限的拷贝

### 13.3
当我们拷贝 StrBlob时，会使 shared_ptr 的引用计数加1。当我们拷贝 StrBlobPtr 时，引用计数不会变化。

### 13.4
```c++
Point global;
Point foo_bar(Point arg) { // 参数和返回值使用了拷贝构造
  Point local = arg, *heap = new Point(global); // local=arg和 global被传递进创建Point的时候,使用了拷贝构造函数
  *heap = local;
  Point pa[4] = {local, *heap}; // 这里使用了拷贝构造
  return *heap;
}
```

### 13.5
```c++
HasPtr(const HasPtr& hp) : ps(new string(*hp.ps)), i(hp.i) { }
```

### 13.6
拷贝赋值运算符是一个名为`operator=`的函数。当赋值运算发生时就会用到它。合成拷贝赋值运算符可以用来禁止该类型对象的赋值。如果一个类未定义自己的拷贝赋值运算符，编译器会为它生成一个合成拷贝赋值运算符。

### 13.7
会发生浅层复制。

### 13.8
```c++
HasPtr& operator=(const HasPtr& hp) {
  delete ps;
  ps = new string(*hp.ps);
  i = hp.i;
  return *this;
}
```
### 13.9
析构函数是类的一个成员函数，名字由波浪号接类名构成。它没有返回值，也不接受参数。合成析构函数可被用来阻止该类型的对象被销毁。当一个类未定义自己的析构函数时，编译器会为它生成一个合成析构函数。

### 13.10
当一个 StrBlob 对象被销毁时，shared_ptr 的引用计数会减少。当 StrBlobPtr 对象被销毁时，不影响引用计数。

### 13.11
```c++
~HasPtr() {
  delete ps;
}
```

### 13.12
accum的拷贝构造临时对象1次，item1和item2各一次，共3次

### 13.13 [prog13.cc](prog13.cc)

### 13.14
输出一致的内容

### 13.15
会输出3个不同的数。并且这3个数并不是a、b、c当中的数。

### 13.16
会输出 a、b、c的数。

### 13.17 [prog17-1.cc](prog17-1.cc) [prog17-2.cc](prog17-2.cc) [prog17-3.cc](prog17-3.cc)

### 13.18 [Employee.h](Employee.h)

### 13.19
需要定义，因为在拷贝赋值的时候，也需要保证id递增

### 13.20
成员会被复制。

### 13.21
不需要

### 13.22 [HasPtr.h](HasPtr.h)

### 13.24
如果没有定义析构函数，则资源泄露，如果没有定义拷贝构造函数，则只浅拷贝string的指针

### 13.25
拷贝构造函数和拷贝赋值运算符要重新动态分配内存。因为 StrBlob 使用的是智能指针，当引用计数为0时会自动释放对象，因此不需要析构函数。

### 13.26 [StrBlob.h](StrBlob.h)

### 13.27 [HasPtr2.h](HasPtr2.h)

### 13.28 [prog28.cc](prog28.cc)

### 13.29
这里调用的swap匹配了标准库内的swap，因此不会递归循环

### 13.30 [HasPtr3.h](HasPtr3.h)

### 13.31 [prog31.cc](prog31.cc)

### 13.32
不会。类值的版本利用swap交换指针不用进行内存分配，因此得到了性能上的提升。类指针的版本本来就不用进行内存分配，所以不会得到性能提升。

### 13.33
不定义为`Folder`是因为需要加入将`Message`对象加入对应的`Folder`，而不是其拷贝，不定义为`const Folder&`是因为函数内部改变了`Folder`对象的内容。

### 13.34 [Message.h](Message.h)

### 13.35
将仅拷贝contents和folders成员，而不会将新拷贝的Message加入到对应的Folders中

### 13.36 [Folder.h](Folder.h)

### 13.37 [Message.h](Message.h)
对于动态分配内存的例子来说，拷贝交换方式是一种简洁的设计。而这里的 Message 类并不需要动态分配内存，用拷贝交换方式只会增加实现的复杂度。

### 13.39 [StrVec.h](StrVec.h)

### 13.40 [StrVec.h](StrVec.h)

### 13.41
会出现 unconstructed

### 13.43
```c++
std::for_each(elements, first_free, [](std::string* p){ alloc.destroy(p); });
```
更倾向于函数的写法，因为更清晰

### 13.44 [prog44.cc](prog44.cc)

### 13.45
常规引用被称为左值引用，绑定到右值的引用被称为右值引用。

### 13.46
```c++
int f(); 
vector<int> vi(100);
int &&r1 - f();
int &r2 = vi[0];
int &r3 = r1;
int &&r4 = vi[0] * f();
```

### 13.47 [String.h](String.h)

### 13.48 [prog47.cc](prog47.cc)

### 13.49 [String.h](String.h)

### 13.50 [String.h](String.h) [prog50.cc](prog50.cc)

### 13.51
在这里是移动的操作而不是拷贝操作，因此是合法的。

### 13.52
左值被拷贝，右值被移动。

### 13.53 [HasPtr4.h](HasPtr4.h)
不理想的原因是赋值运算符里，拷贝了对象

### 13.55 [StrBlob.h](StrBlob.h)

### 13.56
死循环递归并最终溢出

### 13.57
没问题。会调用移动版本的sorted函数

### 13.58 [prog58.cc](prog58.cc)
