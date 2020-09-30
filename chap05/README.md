### 5.1
空语句就是不执行任何操作的语句，一般以单纯的`;`作为空语句，在循环仅需判定条件，而循环体内不需要执行任何语句的情况下，可以放置空语句

### 5.2
块是以一组`{}`括起来的部分，`{}`内包含若干以`;`结尾的语句，在逻辑上需要多条语句的地方可以使用块

### 5.3
可读性降低了
```c++
while (val <=10)
  sum += val, ++val;
```

### 5.4
- 遍历string，应该在循环外部声明一个iter，然后循环内递增
```c++
string::iterator iter = s.begin();
while (iter != s.end()) {
  ++iter;
}
```
- 循环直到找到某个单词
```c++
while (bool status = find(word)) {
  if (!status) {}
}
```
### 5.5 [代码](prog5.cc)

### 5.6 [代码](prog6.cc)

### 5.7
```c++
// (a)
if (ival != ival2)
  ival1 = ival2;
else
  ival1 = ival2 = 0;
// (b)
if (ival < minval) {
  minval = ival;
  occurs = 1;
}
// (c)
if (int ival = get_value()) {
  cout << "ival = " << ival << endl;
else
  cout << "ival = 0\n";
}
// (d)
if (ival == 0)
  ival = get_value();
```

### 5.8
悬挂else是多个if语句中，出现的else语句，C++语言让else匹配离得最近的尚未匹配else的if

### 5.9 [代码](prog9.cc)

### 5.10 [代码](prog10.cc)

### 5.11 [代码](prog11.cc)

### 5.12 [代码](prog12.cc)

### 5.13
- case结束之后没有break语句，应该加上break语句
  ```c++
  unsigned aChnt = 0, eCnt = 0, iouCnt = 0;
  char ch = next_text();
  switch (ch) {
    case 'a':
      aCnt++;
      break;
    case 'b':
      bCnt++;
      break;
    default:
      iouCnt++;
      break;
  }
  ```
- case1中初始化的ix在default中被使用了
  ```c++
  unsigned index = some_value();
  switch (index) {
    case 1:
    {
      int ix = get_value();
      ivec[ix] = index;
    }
    break;
    default:
    {
      int ix = ivec.size() - 1;
      ivec[ix] = index;
    }
  }
  ```
- 不应该用逗号运算符，而应该用`:`分隔执行相同动作的case
  ```C++
  unsigned evenCnt = 0, oddCnt = 0;
  int digit = get_num() % 10;
  switch (digit) {
    case 1 : case 3 : case 5 : case 7 : case 9:
      oddCnt++;
      break;
    case 2 : case 4 : case 6 : case 8 : case 10:
      evenCnt++;
      break;
  }
  ```
- 不能使用变量在case处，只能使用整型常量表达式
  ```c++
  constexpr unsigned ival = 512, jval = 1024, kval = 4096;
  unsigned bufsize;
  unsigned swt = get_bufCnt();
  switch (swt) {
    case ival:
      bufsize = ival * sizeof(int);
      break;
    case jval:
      bufsize = jval * sizeof(int);
      break;
    case kval:
      bufsize = kval * sizeof(int);
      break;
  }
  ```

### 5.14 [代码](prog14.cc)

### 5.15
- (a) for循环在init-statement中定义的变量，不能在for循环的作用域范围外使用
  ```c++
  int ix = 0
  for (; ix != si; ++i) {/* ... */}
  if (ix != sz)
      // ...
  ```
- (b) 没有condition的部分，语法错误
  ```c++
  int ix;
  for (;ix != sz; ++ix) {/* ... */}
  ```
- (c) 循环永远不会终止
  ```c++
  for (int ix = 0; ix != sz; ++ix) {/* ... */}
  ```

### 5.16
我更倾向于`while`循环，因为他更简洁。
```c++
// 读入数据
for (int i = 0; cin >> i;)
int i = 0;
while (cin >> i)
// 循环遍历
for (; i < sz; ++i)
while (i < sz) {
  ++i;
}
```

### 5.17 [代码](prog17.cc)

### 5.18
- (a) 少了花括号，do和while之间的应该是一个块
  ```c++
  do {
    int v1, v2;
    cout << "Please enter two numbers to sum:";
    if (cin >> v1 >> v2) {
      cout << "Sum is: " << v1 + v2 << endl;
    }
  } while (std::cin)
  ```
- (b) while用于判断的条件表达式的变量应该在while循环之外定义
  ```c++
  int ival = 0;
  do {
    // ...
  } while (val = get_response());
  ```
- (c) 同(b)的错误
  ```c++
  int ival = 0;
  do {
    ival = get_response();
  } while (ival);
  ```

### 5.19 [代码](prog19.cc)

### 5.20 [代码](prog20.cc)

### 5.21
```c++
string buf;
while (cin >> buf && !buf.empty()) {
  if (!isupper(buf[0]))
    continue;
  // handle word with initial word in uppper case
}
```
### 5.22
```c++
int sz = 0;
do {
  sz = get_size();
} while (sz <= 0>);
```

### 5.23 [代码](prog23.cc)

### 5.24
将会出现`Floating point exception`的异常

### 5.25 