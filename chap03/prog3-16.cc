#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;

int main() {
  vector<int> v1;
  cout << "(a) " << v1.size() << endl;
  
  vector<int> v2(10);
  cout << "(b) " << v2.size();
  for (const auto &v : v2) {
    cout << " " << v;
  }
  cout << endl;
  
  vector<int> v3(10, 42);
  cout << "(c) " << v3.size();
  for (const auto &v : v3) {
    cout << " " << v;
  }
  cout << endl;

  vector<int> v4{10};
  cout << "(d) " << v4.size();
  for (const auto &v : v4) {
    cout << " " << v;
  }
  cout << endl;

  vector<int> v5{10, 42};
  cout << "(e) " << v5.size();
  for (const auto &v : v5) {
    cout << " " << v;
  }
  cout << endl;

  vector<string> v6{10};
  cout << "(f) " << v6.size();
  for (const auto &v : v6) {
    cout << " " << v;
  }
  cout << endl;

  vector<string> v7{10, "hi"};
  cout << "(g) " << v7.size();
  for (const auto &v : v6) {
    cout << " " << v;
  }
  cout << endl;

  return 0;
}