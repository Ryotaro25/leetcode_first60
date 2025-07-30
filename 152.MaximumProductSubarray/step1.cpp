class Solution {
public:
  int maxProduct(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }
    int max_product = nums[0];
    int max_product_so_far = nums[0];
    int min_product_so_far = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      int temp_max_so_far = max(nums[i], max(max_product_so_far * nums[i], min_product_so_far * nums[i]));
      min_product_so_far = min(nums[i], min(max_product_so_far * nums[i], min_product_so_far * nums[i]));
      max_product_so_far = temp_max_so_far;
      max_product = max(max_product, max_product_so_far);
    }

    return max_product;
  }
};
