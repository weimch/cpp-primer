### 12.1
都包含4个元素，在代码末尾，b2被析构了，但并不影响b1

### 12.2 [prog2.h](StrBlob.h)

### 12.3
不需要。push_back 和 pop_back 会改变对象的内容。而 const 对象是只读的，因此不需要。

### 12.4
因为`size_t`类型是无符号的类型，值始终大于等于0

### 12.5
构造函数不是 explicit 的，意味着可以从 initializer_list 隐式转换为 StrBlob。在 StrBlob 对象中，只有一个数据成员 data，而 StrBlob 对象本身的含义，也是一个管理字符串的序列。因此，从 initializer_list 到 StrBlob 的转换，在逻辑上是可行的。而这个设计策略的缺点，可能在某些地方我们确实需要 initializer_list，而编译器仍会将之转换为 StrBlob。

### 12.6 [prog6.cc](prog6.cc)

### 12.7 [prog7.cc](prog7.cc)

### 12.8
返回值应该是指针类型`int*`，且指针需要释放

### 12.9
使用new的，当r被q所赋值之后，原始指向的分配内存丢失，引起内存泄漏，而make_shared版本的，在r被q所赋值之后，指向的内存被释放掉

### 12.10
正确

### 12.11
使用普通指针来初始化智能指针，调用process将会创建一个临时的智能指针，在函数执行完毕之后，该指针执行delete操作，将指针指向的对象释放掉。

### 12.12
- (a) 合法，sp拷贝复制，进入函数，引用计数变为2，函数结束之后，临时对象释放，引用计数变为1
- (b) 不合法，普通指针需要显示转化成智能指针
- (c) 不合法，普通指针需要显示转化成智能指针
- (d) 合法，但是在执行process结束之后，p所指向的动态内存将会被释放

### 12.13
动态内存将会被释放2次，造成未定义行为。

### 12.14 & 12.15
```c++
void f(destination &d) {
  connection c = connect(&d);
  shared_ptr<connection> p(&c, [](connection *pc)->{ disconnect(*p); });
}
```

### 12.16 [prog16.cc](prog16.cc)
错误信息如下：
```
prog16.cc:5:29: error: use of deleted function ‘std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = int; _Dp = std::default_delete<int>]’
```
将拷贝构造函数定义成为删除的来达到效果

### 12.17
- (a) 错误，使用非指针来初始化智能指针
- (b) 错误，指针不是new进行分配的，delete不能释放栈空间的内存
- (c) 正确
- (d) 错误，同b
- (e) 正确
- (f) 正确，但是将会引起指针二次释放

### 12.18
因为`unique_ptr`对指针的控制是唯一的所有者，因为当指针从赋予另一个`unique_ptr`，之前的指针必须先要释放其所有权，而`shared_ptr`则不需要

### 12.19 [StrBlobPtr.h](StrBlobPtr.h) [StrBlob.h](StrBlob.h)

### 12.20 [prog20.cc]

### 12.21
第一个版本更好，因为更加清晰

### 12.22
构造函数改为接受 const Strblob & , 然后给 Strblob 类添加两个 const 成员函数 cbegin 和 cend，返回 ConstStrBlobPtr。

### 12.23 [prog23.cc](prog23.cc)

### 12.24 [prog24.cc](prog24.cc)

### 12.25
使用`delete [] pa`来释放

### 12.26 [prog26.cc](prog26.cc)

### 12.27 [prog27.cc](prog27.cc)

### 12.28
倾向于`do while`版本，因为先让用户输入，再判断输入字符串的部分可以放在while循环条件内。

### 12.31
使用vector需要解决行号重复的问题，通常需要遍历整个vector或者至少二分查找，复杂度为O(logn)，而set方法快速插入重复元素。
