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
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> level_to_values = {};
    if (!root) {
      return level_to_values;
    }

    vector<TreeNode*> current_level_nodes = {root};
    while (!current_level_nodes.empty()) {
      vector<int> values = {};
      vector<TreeNode*> next_level_nodes = {};

      for (const auto node : current_level_nodes) {
        values.emplace_back(std::move(node->val));
        if (node->left) {
          next_level_nodes.emplace_back(node->left);
        }
        if (node->right) {
          next_level_nodes.emplace_back(node->right);
        }
      }
      level_to_values.emplace_back(std::move(values));
      current_level_nodes = std::move(next_level_nodes);
    }

    return level_to_values;
  }
};
