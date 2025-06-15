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
  TreeNode* invertTree(TreeNode* node) {
    if (!node) {
      return nullptr;
    }

    TreeNode* inverted_left = invertTree(node->left);
    TreeNode* inverted_right = invertTree(node->right);

    node->left = inverted_right;
    node->right = inverted_left;
    return node;
  }
};
