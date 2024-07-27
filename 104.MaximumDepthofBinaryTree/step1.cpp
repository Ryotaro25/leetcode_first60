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
  int MeasureDepth(TreeNode* node) {
    if (node == nullptr) {
      return 0;
    }
    int left_depth = MeasureDepth(node->left);
    int right_depth = MeasureDepth(node->right);

    return max(left_depth, right_depth) + 1;
  }

  int maxDepth(TreeNode* root) {
    int depth = MeasureDepth(root);
    return depth;
  }
};
