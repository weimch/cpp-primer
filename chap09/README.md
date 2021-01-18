### 9.1
- (a) list，因为按照字典序插入时，会有大量的中间插入操作
- (b) dequeue，可以头尾操作
- (c) vector，可以遍历打印出来，dequeue不可以遍历

### 9.2
```c++
list<dequeue<int>> ls;
```

### 9.3
构成范围的迭代器必须要是同一个容器对象的迭代器，且begin必须在end之前

### 9.4
```c++
bool findFromVector(vector<int>::iterator begin, vector<int>::iterator end, int num) {
  while (begin != end) {
    if (*begin == num) return true;
    ++begin;
  }
  return false;
}
```

### 9.5
```c++
vector<int>::iterator findFromVector(vector<int>::iterator begin, vector<int>::iterator end, int num) {
  while (begin != end) {
    if (*begin == num) return begin;
    ++begin;
  }
  return end;
}
```

### 9.6
迭代器不能比较大小
```c++
list<int> lst1;
list<int>::iterator iter1 = lst1.begin(), iter2 = lst.end();
while (iter1 < iter2) /* ... */
```

### 9.7
应该使用`vector<int>::size_type`类型

### 9.8
仅读取可以使用`vector<int>::const_iterator`，读写可以使用`vector<int>::iterator`

### 9.9
begin返回的迭代器可以读写，cbegin返回的迭代器只能读

### 9.10
auto将始终推导成为同类型，因此it2放在此处不合适，应该修改如下
```c++
auto it1 = v1.begin();
auto it2 = v2.begin(), it3 = v1.cbegin(), it4 = v2.cbegin();
```
- it1 ==> vector<int>::iterator
- it2,it3,it4 ==> vector<int>::const_iterator

### 9.11
```c++
vector<int> v1; // 空的vector
vector<int> v2(v1); // 拷贝v1
vector<int> v3{1, 2, 3}; // 1,2,3
vector<int> v4(v3.begin()+1, v3.end()); // 2,3
vector<int> v5(10); // 10个0
vector<int> v6(10, 1);  // 10个1
```

### 9.12
接受一个容器创建其拷贝的构造函数，要求容器类型和元素类型都一致，而接收两个迭代器的构造函数的元素类型可以不一致，只要可以转化即可

### 9.13 [prog13.cc](prog13.cc)

### 9.14 [prog14.cc](prog14.cc)

### 9.15
```c++
std::vector<int> v1{1, 2, 3};
std::vector<int> v2{3, 2, 1};
std::cout << "v1 == v2 ? " << (v1 == v2) << std::endl;
return 0;
```

### 9.16
两个不同类型的容器之间不可以使用比较运算符进行比较，需要做相应转化
```c++
std::list<int> l1{1, 2, 3};
std::vector<int> v1{1, 2, 3};
std::cout << "v1 == l1 ? " << (std::vector<int>(l1.begin(), l1.end()) == v1) << std::endl;
```

### 9.17
需要c1和c2是同类型，且元素的`<`是有定义的。

### 9.18 [prog18.cc](prog18.cc)

### 9.19
将deque换位list即可，其他地方不用改变

### 9.20
```c++
list<int> ls{1,2,3,4};
deque<int> d1, d2;
for (auto const &e : ls) {
  if (e % 2 == 0) {
    d1.push_back(e);
  } else {
    d2.push_back(e);
  }
}
```

### 9.21
一样的

### 9.22
`iv`在`insert`之后，其迭代器`iter`和`mid`将会失效，应该修改为
```c++
while (iter != mid) {
  if (*iter == some_val) {
    iter = v.insert(iter, 2 * some_val);
    ++iter;
  }
  ++iter;
}
```

### 9.23
都是同一个值

### 9.24 [prog24.cc](prog24.cc)

### 9.25
如果elem1和elem2相等，那么将没有元素被删除，如果elem2是尾后迭代器，那么将会删除从elem1开始到末尾的所有元素，两者都是尾后迭代器，什么也不会发生。

### 9.26 [prog26.cc](prog26.cc)

### 9.27 [prog27.cc](prog27.cc)

### 9.28 [prog28.cc](prog28.cc)

### 9.29
`vec.resize(100)`将会在vec后面新增加75个0，`vec.resize(10)`将会将vec尾部的90个元素删除。

### 9.30
如果是类的话，需要该类提供默认构造函数

### 9.31
```c++
iter += 2;
```
因为复合赋值语句只能用于 string、vector、deque、array，所以要改为：
```c++
++iter;
++iter;
```
而对于`forward_list`来说，需要调用`insert_before`，因此，需要更改为
```c++
auto prev = flst.before_begin();
//...
curr == flst.insert_after(prev, *curr);
++curr; ++curr;
++prev; ++prev;
```

### 9.32
不合法。因为参数的求值顺序是未指定的。

### 9.33 [prog33.cc](prog33.cc)
begin将会失效，因为插入使得插入元素之后的迭代器都失效了

### 9.34 [prog34.cc](prog34.cc)
一直往vi从前往后数的第一个奇数的前面插入数据，循环将永远不会结束。

### 9.35
`capacity`表示容器内部的容量大量，这个值大于或者等于容器中存储的元素数量`size`

### 9.36
不可能

### 9.37
因为list不需要通过下标快速计算出实际元素的位置，从而获取元素，而array只能是固定的大小

### 9.38 [prog38.cc](prog38.cc)
当元素个数size到超过一半的时候，对capacity进行翻倍
```
size:1 capacity:1
size:2 capacity:2
size:3 capacity:4
size:4 capacity:4
size:5 capacity:8
size:6 capacity:8
size:7 capacity:8
size:8 capacity:8
size:9 capacity:16
size:10 capacity:16
size:11 capacity:16
size:12 capacity:16
size:13 capacity:16
size:14 capacity:16
size:15 capacity:16
size:16 capacity:16
size:17 capacity:32
```

### 9.39
```c++
vector<string> svec;
svcec.reserve(1024); // 设定容器至少需要有保存1024个元素的capacity
string word;
while (cin >> word)
  svec.push_back(word);
svec.resize(svec.size() + svec.size()/2); // 将元素数量变为原来的1.5倍，如果元素个数如果超过capacity将会触发新空间的创建和旧数据的拷贝复制
```

### 9.40
256时候是512；512的时候是1024，1000个的时候是1024，1048的时候是2048

### 9.41
```c++
vector<char> v{'h', 'e', 'l', 'l', 'o'};
string str(v.cbegin(), v.cend());
```

### 9.42
可以先使用`reverse(100)`来预先保留分配100个元素

### 9.43 [prog43.cc](prog43.cc)

### 9.44 [prog44.cc](prog44.cc)

### 9.45 [prog45.cc](prog45.cc)

### 9.46 [prog46.cc](prog46.cc)

### 9.47 [prog47.cc](prog47.cc)

### 9.48
返回numbers中存在的第一个name字符字串的位置，但是此处不存在，返回`string::npos`

### 9.49 [prog49.cc](prog49.cc)

### 9.50 [prog50.cc](prog50.cc)

### 9.51 [prog51.cc](prog51.cc)

### 9.52 [prog52.cc](prog52.cc)
