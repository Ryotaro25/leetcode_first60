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
    int left_depth = minDepth(node->left);
    int right_depth = minDepth(node->right);

    if (node->left != nullptr && node->right == nullptr) {
      return left_depth + 1;
    }
    if (node->right != nullptr && node->left == nullptr) {
      return right_depth + 1;
    }
    return min(left_depth, right_depth) + 1;
  }
};
