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
    if (nums.size() == 0) {
      return nullptr;
    }
    TreeNode* new_root = CreateTree(nums, 0, nums.size() - 1);
    return new_root;
  }

private:
  TreeNode* CreateTree(vector<int>& nums, int start, int end) {
    if (start > end) {
      return nullptr;
    }
    int middle = (start + end) / 2;
    TreeNode* node = new TreeNode(nums[middle]);
    node->left = CreateTree(nums, start, middle - 1);
    node->right = CreateTree(nums, middle + 1, end);

    return node;
  }
};
