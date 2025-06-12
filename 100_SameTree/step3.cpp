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
  bool isSameTree(TreeNode* node, TreeNode* other_node) {
    if (!node && !other_node) {
      return true;
    }
    if (!node || !other_node) {
      return false;
    }
    if (node->val != other_node->val) {
      return false;
    }
    return isSameTree(node->left, other_node->left) && isSameTree(node->right, other_node->right);
  }
};
