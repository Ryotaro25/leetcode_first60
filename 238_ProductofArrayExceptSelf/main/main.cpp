#include "main.h"
#include <iostream>

// Solution::をつけないとグローバル関数となる
std::vector<int> Solution::productExceptSelf(std::vector<int>& nums) {
  if (nums.size() == 0) {
    return {};
  }
  std::vector<int> products_except_self(nums.size(), 1);
  int prefix_product = 1;
  for (int i = 0; i < nums.size(); i++) {
    products_except_self[i] *= prefix_product;
    prefix_product *= nums[i];
  }

  int suffix_product = 1;
  for (int i = nums.size() - 1; i >= 0; i--) {
    products_except_self[i] *= suffix_product;
    suffix_product *= nums[i];
  }

  return products_except_self;
}

int main() {
  Solution solution;
  std::vector<int> nums = {-1,1,0,-3,3};
  std::vector<int> products = solution.productExceptSelf(nums);
  std::cout << "Output is: ";
  for (int product : products) {
    std::cout << product << " ";
  }
  std::cout << std::endl;
  return 0;
}
