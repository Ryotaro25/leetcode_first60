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
    return IsIdenticalTree(p, q);
  }

private:
  bool IsIdenticalTree(TreeNode* first_node, TreeNode* second_node) {
    if (!first_node && !second_node) {
      return true;
    }
    if (!first_node || !second_node) {
      return false;
    }
    if (first_node->val != second_node->val) {
      return false;
    }
    return IsIdenticalTree(first_node->left, second_node->left) && IsIdenticalTree(first_node->right, second_node->right);
  }
};
