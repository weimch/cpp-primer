### 10.1 [prog1.cc](prog1.cc)

### 10.2 [prog2.cc](prog2.cc)

### 10.3 [prog3.cc](prog3.cc)

### 10.4
没有错误，double类型在相加时会强制转化为int类型，造成精度丢失。

### 10.5
c风格的字符串是使用指针来表示的，因此在比较时将会比较两个元素的地址。

### 10.6 [prog6.cc](prog6.cc)

### 10.7
对vec的改变大小操作，应该使用back_inserter(vec)迭代器。

### 10.8
`back_inserter(vec)`返回的尾后迭代器，重新定义了`=`操作，使其在调用`=`运算之前，使用push_back

### 10.9 [prog9.cc](prog9.cc)

### 10.10
算法接口的输入都是迭代器，迭代器只能改变容器内的值，而不能改变大小(back_inserter属于重新定义了迭代器的赋值操作，使其操作改变了容器大小的，而不是算法导致的)

### 10.11 [prog10.cc](prog10.cc)

### 10.13 [prog13.cc](prog13.cc)

### 10.14 [prog14.cc](prog14.cc)

### 10.15
```c++
int x = 10;
auto f = [x](int i) { return x + i; }
```

### 10.16 [prog16.cc](prog16.cc)

### 10.18 [prog18.cc](prog18.cc)

### 10.19 [prog19.cc](prog19.cc)

### 10.20 [prog20.cc](prog20.cc)

### 10.21 [prog21.cc](prog21.cc)

### 10.22 [prog22.cc](prog22.cc)

### 10.23
假设被绑定的函数接受 n 个参数，那么bind 接受 n + 1 个参数。

### 10.24 [prog24.cc](prog24.cc)

### 10.24 [prog25.cc](prog25.cc)

### 10.26
不同之处在于插入的位置不同，`back_inserter`总是调用并要求容器具有`push_back`，`front_inserter`总是调用并要求容器具有`push_front`，`inserter`总是调用并要求容器具有`insert`

### 10.27 [prog27.cc](prog27.cc)

### 10.28 [prog28.cc](prog28.cc)

### 10.29 [prog29.cc](prog29.cc)

### 10.30 [prog30.cc](prog30.cc)

### 10.31 [prog31.cc](prog31.cc)

### 10.33 [prog33.cc](prog33.cc)

### 10.34 [prog34.cc](prog34.cc)

### 10.35 [prog35.cc](prog35.cc)

### 10.36 [prog36.cc](prog36.cc)

### 10.37 [prog37.cc](prog37.cc)

### 10.38
- 输入迭代器：`==`, `!=`, `++`, `*`, `--`
- 输出迭代器：`++`, `*`
- 前向迭代器：`==`, `!=`, `++`, `*`, `->`
- 双向迭代器：`==`, `!=`, `++`, `--`, `*`, `->`
- 随机访问迭代器：`==`, `!=`, `<`, `<=`, `>`, `>=`, `++`, `--`, `+`, `+=`, `-`, `-=`, `*`, `->`, `iter[n]==*(iter[n])`

### 10.39
list上的属于双向迭代器，vector上的属于随机访问迭代器。

### 10.40
- copy需要两个输入迭代器，一个输出迭代器
- reverse需要双向迭代器
- unique需要随机访问迭代器

### 10.41
- `replace(beg, end, old_val, new_val)` 将序列中的old_val替换成为new_val
- `replace_if(beg, end, pred, new_val)` 如果序列中的值满足pred谓词所定的条件，则将其替换成new_val
- `replace_copy(beg, end, dest, old_val, new_val)` 将序列中的old_val替换成为new_val之后的序列写入到dest中
- `replace_copy_if(beg, end, dest, pred, new_val)` 替换时使用谓词所定的条件作为替换的判定

### 10.42 [prog42.cc](prog42.cc)
