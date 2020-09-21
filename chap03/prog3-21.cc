#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;

int CanculateSize(const vector<int> &vec) {
  decltype(vec.size()) size = 0;
  for (auto it = vec.cbegin(); it != vec.cend(); ++it) {
    cout << " " << *it;
    ++size;
  }
  cout << endl;
  return size;
}

int CanculateSize(const vector<string> &vec) {
  decltype(vec.size()) size = 0;
  for (auto it = vec.cbegin(); it != vec.cend(); ++it) {
    cout << " " << *it;
    ++size;
  }
  cout << endl;
  return size;
}

int main() {
  vector<int> v1;
  cout << "(a) " << CanculateSize(v1);
  
  vector<int> v2(10);
  cout << "(b) " << CanculateSize(v2);
  
  vector<int> v3(10, 42);
  cout << "(c) " << CanculateSize(v3);

  vector<int> v4{10};
  cout << "(d) " << CanculateSize(v4);

  vector<int> v5{10, 42};
  cout << "(e) " << CanculateSize(v5);

  vector<string> v6{10};
  cout << "(f) " << CanculateSize(v6);

  vector<string> v7{10, "hi"};
  cout << "(g) " << CanculateSize(v7);

  return 0;
}