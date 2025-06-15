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
    TreeNode* smaller_head = new TreeNode();
    auto smaller = smaller_head;

    TreeNode* larger_head = new TreeNode();
    auto larger = larger_head;

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

    return {smaller_head->right, larger_head->left};
  }
};
