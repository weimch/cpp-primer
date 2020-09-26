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

