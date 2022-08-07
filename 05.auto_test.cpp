#include <iostream>
#include <vector>
std::vector<int>& addOne(std::vector<int> &v) {
  for(auto& it : v) {
    it += 1;
  }
  return v;
}

int main() {
  // C++11 的 std::vector 初始化寫法
  std::vector<int> x = {12, -3, 6, 19};

  auto y = addOne(x);
  for (auto& it : y) {
    std::cout << it << ' ';
  }
  std::cout << std::endl;
  return 0;
}