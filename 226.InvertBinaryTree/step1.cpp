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
  TreeNode* invertTree(TreeNode* root) {
    if (!root) {
      return nullptr;
    }
    queue<TreeNode*> traversing_nodes;
    traversing_nodes.push(root);
    while (!traversing_nodes.empty()) {
      TreeNode* node = traversing_nodes.front();
      traversing_nodes.pop();

      TreeNode* temp = node->left;
      node->left = node->right;
      node->right = temp;

      if (node->left) {
        traversing_nodes.push(node->left);
      }
      if (node->right) {
        traversing_nodes.push(node->right);
      }
    }

    return root;
  }
};
