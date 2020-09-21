#include <iostream>
#include <vector>

bool array_equal(const int *pb1, const int *pe1, const int *pb2, const int *pe2) {
  if (pe1 - pb1 != pe2 - pb2) {
    return false;
  }
  for (auto i = pb1, j = pb2; i != pe1; ++i, ++j) {
    if (*i != *j) {
      return false;
    }
  }
  return true;
}

bool vector_equal(std::vector<int> &v1, std::vector<int> &v2) {
  return v1 == v2;
}

int main() {
  int arr1[] = {1, 2, 3, 4};
  int arr2[] = {1, 2, 3, 3};
  std::vector<int> v1{1, 2, 3, 4};
  std::vector<int> v2{1, 2, 3, 4, 5};
  std::cout << array_equal(std::begin(arr1), std::end(arr1), std::begin(arr2), std::end(arr2)) << std::endl;
  std::cout << vector_equal(v1, v2) << std::endl;
}