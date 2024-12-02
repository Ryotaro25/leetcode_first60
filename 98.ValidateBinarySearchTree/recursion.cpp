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
  bool isValidBST(TreeNode* root) {
    return CheckIsValidBst(root, LONG_MIN, LONG_MAX);
  }

private:
  bool CheckIsValidBst(TreeNode* node, long long lower_value,long long upper_value) {
    if (!node) {
      return true;
    }
    if(node->val <= lower_value || node->val >= upper_value) {
      return false;
    }
    return CheckIsValidBst(node->left, lower_value, node->val) && CheckIsValidBst(node->right, node->val, upper_value);
  }
};
