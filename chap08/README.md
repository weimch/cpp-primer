### 8.1
```c++
std::istream& readStream(std::istream& in) {
  char ch;
  while (in >> ch) {
    std::cout << ch;
  }
  in.clear();
  return in;
}
```

### 8.2 [prog2.cc](prog2.cc)

### 8.3
在遇到eof流结束标识时结束，或者在读操作失败时结束，读操作失败通常发生在比如读取一个期望的`int`但是输入确实`char`型时

### 8.4 [prog4.cc](prog4.cc)

### 8.5 [prog5.cc](prog5.cc)

### 8.6 [prog6.h](prog6.h) [prog6.cc](prog6.cc)

### 8.7 [prog7.cc](prog7.cc)

### 8.8 [prog8.cc](prog8.cc)

### 8.9 [prog9.cc](prog9.cc)

### 8.10 [prog10.cc](prog10.cc)

### 8.11 [prog11.cc](prog11.cc)

### 8.12
因为这里只需要聚合类就够了，所以没有必要在 PersionInfo 中使用类内初始化。

### 8.13 [prog13.cc](prog13.cc)

### 8.14
auto自动推导类型，用引用取代复制效率更高，同时在循环内不改变这些数据，因此使用const
