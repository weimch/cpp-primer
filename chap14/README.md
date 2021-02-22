### 14.1
我们可以直接调用重载运算符函数。重置运算符与内置运算符有一样的优先级与结合性。

### 14.2 [Sales_data.h](Sales_data.h)

### 14.3
a只是指针间的比较，d使用了string的重载运算符版本，b使用了string的内置运算符版本，c使用了vector的内置运算符版本

### 14.4
- (a) 不需要是成员。
- (b) 是成员。
- (c) 是成员。
- (d) 必须是成员。
- (e) 不需要是成员。
- (f) 不需要是成员。
- (g) 不需要是成员。
- (h) 必须是成员。

### 14.10
- (a) 格式正确。
- (b) 不合法的输入。因为程序试图将 0-210-99999-9 转换为 float。

### 14.11
有错误，没有检查输入流的状态，读取上个练习的输入b将使得price未定义，导致使用未定义的price发生异常

### 14.14
因为用 operator+= 会避免使用一个临时对象，而使得更有效。

### 14.21
缺点：使用了一个 Sales_data 的临时对象，但它并不是必须的。

### 14.33
一个重载的函数调用运算符接受的运算对象应该和该运算符拥有的操作数一样多。

### 14.34
```c++
class CheckIfThenElse {
  void operator()(bool b1, int i1, int i2) {
    if (b1) return b1;
    return b2;
  }
}
```

### 14.35
```c++
class GetInput {
public:
  GetInput(std::istream &i = std::cin) : is(i) {}
  std::string operator()() const {
    std::string str;
    std::getline(is, str);
    return is ? str : std::string();
  }
private:
  std::istream &is;
};
```

### 14.36
```c++
int main() {
  GetInput getInput;
  std::vector<std::string> vec;
  for (std::string tmp; !(tmp = getInput()).empty();) vec.push_back(tmp);
  for (const auto &str : vec) std::cout << str << " ";
  std::cout << std::endl;
}
```

### 14.37 [prog37.cc](prog37.cc)

### 14.38 [prog38.cc](prog38.cc)

### 14.41
使用 lambda 是非常方便的，当需要使用一个函数，而这个函数不常使用并且简单时，使用lambda 是比较方便的选择。

### 14.42
```c++
std::count_if(ivec.cbegin(), ivec.cend(), std::bind(std::greater<int>(), _1, 1024));
std::find_if(svec.cbegin(), svec.cend(), std::bind(std::not_equal_to<std::string>(), _1, "pooh"));
std::transform(ivec.begin(), ivec.end(), ivec.begin(), std::bind(std::multiplies<int>(), _1, 2));
```

### 14.43
```c++
std::any_of(vec.begin(), vec.end(), std::bind(std::modulus<int>(), input, _1));
```

### 14.44 [prog44.cc](prog44.cc)

### 14.47
```c++
struct Integral {
  operator const int(); // 无意义
  operator int() cosnt; // 在转化中，保持对象是const的
};
```

### 14.50
ex1存在二义性的的转换，ex2可以成功转换成int

### 14.51
最佳可行函数是 void calc(int)。

转换的优先级如下：
1. 精确匹配
1. const 转换。
1. 类型提升
1. 算术转换
1. 类类型转换

### 14.52
ld = si + ld; 不合法。ld = ld + si 两个都可以调用，但是第一个调用更精确一些。

### 14.53
不合法，进行如下修改
```c++
SmallInt s1;
double d = s1 + SmallInt(3.14);
```
