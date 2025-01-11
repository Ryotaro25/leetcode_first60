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
    TreeNode* smaller_node = smaller_head;

    TreeNode* larger_head = new TreeNode();
    TreeNode* larger_node = larger_head;

    while (node) {
      if (node->val <= target) {
        smaller_node->right = node;
        smaller_node = smaller_node->right;
        node = node->right;
        smaller_node->right = nullptr;
      } else {
        larger_node->left = node;
        larger_node = larger_node->left;
        node = node->left;
        larger_node->left = nullptr;
      }
    }

    return {smaller_head->right, larger_head->left};
  }
};
