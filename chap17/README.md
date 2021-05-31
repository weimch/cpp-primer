### 17.1
```c++
tuple<int, int, int> t(10, 20, 30);
```

### 17.2
```c++
tule<string, vector<string>, pair<string, int>> t("123", {"123", "456"}, {"123", 456});
```

### 17.3
第一种设计更好，第二种设计更容易实现，但不容易重构。

### 17.4 [prog4.cc](prog4.cc)

### 17.7
tuple版本的findBook，更简洁

### 17.8
返回的的结果的Isbn为空，因为第三个参数是初始值。

### 17.9
- (a) 用unsigned值初始化：0000000000000000000000000000000000000000000000000000000000100000;
- (b) 用unsigned值初始化：00000000000011110110100110110101;
- (c) 用string初始化：取决输入，有8个bit的长度。

### 17.10 [prog10.cc](prog10.cc)

### 17.11
```c++
template <unsigned N>
class quiz {
 public:
  quiz(std::string &s) : bset(s) {}
 private:
  std::bitset<N> bset;
}
```

### 17.12
```c++
template <unsigned N>
class quiz {
 public:
  quiz(std::string &s) : bset(s) {}
  void update(unsigned qn, bool correct) {
    if (qn > N) {
      std::cerr << "Error question number" << std::endl;
      return ;
    }
    bset.set(qn, correct);
  }
 private:
  std::bitset<N> bset;
}
```

### 17.15 [prog15.cc](prog15.cc)

### 17.16
只有包含ei，同时之前无c的字符串才会被匹配。

### 17.17 [prog17.cc](prog17.cc)

### 17.28 [prog28.cc](prog28.cc)

### 17.31
将会导致每次的随机结果都一样

### 17.32
编译错误，未在循环外定义resp
