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

