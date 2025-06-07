/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    if (nums.empty()) {
      return nullptr;
    }
    return GenerateBST(nums, 0, nums.size() - 1);
  }

private:
  TreeNode* GenerateBST(const vector<int>& nums, int left, int right) {
    if (left > right) {
      return nullptr;
    }
    int middle = left + (right - left) / 2;
    TreeNode* middle_node = new TreeNode(nums[middle]);
    middle_node->left = GenerateBST(nums, left, middle - 1);
    middle_node->right = GenerateBST(nums, middle + 1, right);
    return middle_node;
  }
};
