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
    return CheckIsValidBst(root, numeric_limits<int64_t>::min(), numeric_limits<int64_t>::max());
  }

private:
  bool CheckIsValidBst(TreeNode* node, int64_t lower_value, int64_t upper_value) {
    if (!node) {
      return true;
    }
    if(node->val <= lower_value || node->val >= upper_value) {
      return false;
    }
    return CheckIsValidBst(node->left, lower_value, node->val) && CheckIsValidBst(node->right, node->val, upper_value);
  }
};
