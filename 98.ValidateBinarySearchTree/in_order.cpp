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
    if (!root) {
      return true;
    }

    if (root->left) {
      if (root->left->val >= root->val) {
        return false;
      }
      if (!isValidBST(root->left)) {
        return false;
      }
    }

    if (root->right) {
      if (root->right->val <= root->val) {
        return false;
      }
      if (!isValidBST(root->right)) {
        return false;
      }
    }
    return true;
  }
};
