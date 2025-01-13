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
  vector<TreeNode*> splitBST(TreeNode* root, int target) {
    TreeNode* left;
    TreeNode* right;

    splitBSTHelper(root, target, left, right);
    return {left, right};
  }

private:
  void splitBSTHelper(TreeNode* node, int target, TreeNode*& left, TreeNode*& right) {
    if (!node) {
      return;
    }

    if (node->val > target) {
      right = node;
      node = node->left;
      left = nullptr;
      splitBSTHelper(node, target, left, right->left);
    } else {
      left = node;
      node = node->right;
      right = nullptr;
      splitBSTHelper(node, target, left->right, right);
    }
  }
};
