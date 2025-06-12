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
  bool isSameTree(TreeNode* p, TreeNode* q) {
    // pとqをそれぞれinorderで探索し、vectorの値が同じか確認する
    vector<int> first_tree_nums;
    PushNumsByInorder(first_tree_nums, p);
    vector<int> second_tree_nums;
    PushNumsByInorder(second_tree_nums, q);

    if (first_tree_nums.size() != second_tree_nums.size()) {
      return false;
    }
    for (int i = 0; i < first_tree_nums.size(); i++) {
      if (first_tree_nums[i] != second_tree_nums[i]) {
        return false;
      }
    }
    return true;
  }

private:
  void PushNumsByInorder(vector<int>& nums, TreeNode* node) {
    if (!node) {
      return;
    }
    PushNumsByInorder(nums, node->left);
    nums.push_back(node->val);
    PushNumsByInorder(nums, node->right);
  }
};
