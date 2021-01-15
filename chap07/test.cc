#include <string>

class Sales_data {
 public:
  explicit Sales_data(std::string d) : data(d) {}
 private:
  std::string data;
};


int main() {
  std::string null_isbn("999");
  Sales_data item1(null_isbn);
  Sales_data item2("999");
  return 0;
}
