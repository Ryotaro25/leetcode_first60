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
  int minDepth(TreeNode* node) {
    if (node == nullptr) {
      return 0;
    }
    if (node->right == nullptr) {
      return minDepth(node->left) + 1;
    }
    if (node->left == nullptr) {
      return minDepth(node->right) + 1;
    }
    return min(minDepth(node->left), minDepth(node->right)) + 1;
  }
};
