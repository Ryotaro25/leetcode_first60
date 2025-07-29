class Solution {
public:
  int maxProduct(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }
    int max_product = nums[0];
    int current_max = nums[0];
    int current_min = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      // current_maxの数字は次の行で使うので一旦退避
      int temp = max({nums[i], current_max * nums[i], current_min * nums[i]});
      current_min = min({nums[i], current_max * nums[i], current_min * nums[i]});
      
      current_max = temp;
      max_product = max(max_product, current_max);
    }

    return max_product;
  }
};
