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
    return CreateTree(nums, 0, nums.size());
  }

private:
  TreeNode* CreateTree(vector<int>& nums, const int start, const int end) {
    if (start == end) {
      return nullptr;
    }
    int middle = (start + end) / 2;
    TreeNode* node = new TreeNode(nums[middle]);
    node->left = CreateTree(nums, start, middle);
    node->right = CreateTree(nums, middle + 1, end);

    return node;
  }
};
