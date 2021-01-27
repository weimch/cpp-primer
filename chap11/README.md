### 11.1
map使用下标运算符时，下标可以是字符串或者其他类类型，而vector的下标仅能为数字

### 11.2
- list: 双向链表，适合频繁插入删除元素的场景
- vector: 适合频繁访问元素的场景
- deque: 双端队列，适合频繁在头尾插入删除元素的场景
- map: 字典
- set: 适合有序不重复的元素的场景

### 11.3 [prog3.cc](prog3.cc)

### 11.4 [prog4.cc](prog4.cc)

### 11.5
map用于键-值的关联对，通过键快速得到值，而set用于判断键是否唯一

### 11.6
set 是有序不重复集合，底层实现是红黑树，而 list 是无序可重复集合，底层实现是链表。

### 11.7 [prog7.cc]
```c++
map<string, vector<string>> m;
for (string ln; cout << "Last name:\n", cin >> ln && ln != "@q";)
    for (string cn; cout << "|-Children's names:\n", cin >> cn && cn != "@q";)
        m[ln].push_back(cn);
```

### 11.8
使用set可以在常数时间内判断容器内的一个元素是否唯一

### 11.9
```c++
std::map<std::string, std::list<std::size_t>> m;
```

### 11.10
可以定义`vector<int>::iterator`到`int`的`map`，但是不能定义`list<int>::iterator`到`int`的`map`。因为`map`的键必须实现`<`操作，`list`的迭代器不支持比较运算。

### 11.11
```c++
multiset<Sales_data, bool (pf*)(const Sales_data&, const  Sales_data&)> bookstore(compareIsbn);
```

### 11.12 [prog12.cc]

### 11.13 [prog13.cc]
使用列表初始化的形式最简单。

### 11.14 [prog14.cc]

### 11.15
- `mapped_type`: `vector<int>`
- `key_type`: `int`
- `value_type`: `pair<const int, vector<int>`

### 11.16
```c++
std::map<int, string>::iterator it = m.begin();
it->second = "hello";
```

### 11.17
第二个调用不合法，因为 multiset 没有 push_back 方法。其他调用都合法。

### 11.18
`map<string, size_t>::const_iterator map_it = word_count.cbegin();`

### 11.19
`multiset<Sales_data, bool (*)(const Sales_data&, const Sales_data&)>::iterator it = bookstore.begin();`

### 11.20
```c++
map<string, size_t> word_count;
string word;
while (cin >> word) {
  auto ret = word_count.insert({word, 1});
  if (!ret.second) {
    ++ret.first->second;
  }
  for (const auto &w : word_count) {
    cout << w.first << " occurs " << w.second
         << ((w.second > 1) ? " times" : " time") << endl;
  }
}
```
使用下标运算符的最简单，因为当元素不存在时，则创建一个元素

### 11.21
若insert成功：先添加一个元素，然后返回一个 pair，pair 的 first 元素是一个迭代器。这个迭代器指向刚刚添加的元素，这个元素是 pair ，然后递增 pair 的 second 成员。 若insert失败：递增已有指定关键字的元素的 second 成员。

### 11.22
- 参数类型：`pair<string, vector<int>>`
- 返回类型：`pair<map<string, vector<int>>::iterator, bool>`

### 11.23 [prog23.cc]

### 11.24
插入一个关键字为0的元素，关联值进行值初始化；然后将1赋予它

### 11.25
v是空的数组，执行v[0]将会出错

### 11.26
使用`map`的`key_type`类型进行下标操作，进行下标操作返回类型是`mapped_type`，比如对于`map<string, int>`，能进行下标操作的是`string`类型，其返回类型是`int`

### 11.27
对于仅需要判断元素是否存在的，使用find来解决，对于需要得出元素有多少个的使用count来解决，尤其是对于multiset和multimap的情况

### 11.28
`map<string, vector<int>>::iterator fi = m.find(word);`

### 11.29
`upper_bound`和`lower_bound`将会返回第一个大于给定关键字的元素，且二者相等，`equal_range`将会返回一个`pair`，`pair`的第一个元素是`lower_bound`的结果，第二个元素是`upper_bound`的结果

### 11.30
`first`得到一个找到元素的`pair`，然后使用`->second`得到map对象的`mapped_type`的对象引用

### 11.31 [prog31.cc](prog31.cc)

### 11.32 [prog32.cc](prog32.cc)

### 11.33 [prog33.cc](prog33.cc)

### 11.34
将会编译失败，因为传递进来的`map`对象是`const`的

### 11.35
当一个转换规则的关键字多次出现的时候，使用下标运算符会保留最后一次添加的规则，而用insert则保留第一次添加的规则。

### 11.36
将会抛出无此转换规则的异常。

### 11.37
无序容器拥有更好的性能，有序容器使得元素始终有序。
