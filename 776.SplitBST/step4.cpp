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
    TreeNode* node = root;
    TreeNode* smaller_root = new TreeNode();
    auto smaller = smaller_root;

    TreeNode* larger_root = new TreeNode();
    auto larger = larger_root;

    while (node) {
      if (node->val > target) {
        larger->left = node;
        larger = larger->left;
        node = node->left;
        larger->left = nullptr;
      } else {
        smaller->right = node;
        smaller = smaller->right;
        node = node->right;
        smaller->right = nullptr;
      }
    }

    return {smaller_root->right, larger_root->left};
  }
};
