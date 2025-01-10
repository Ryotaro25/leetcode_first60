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
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> level_to_values = {};
    if (!root) {
      return level_to_values;
    }
    vector<TreeNode*> current_nodes = {root};
    int level = 0;

    while (!current_nodes.empty()) {
      vector<int> values = {};
      vector<TreeNode*> next_level_nodes = {};
      for (const auto node : current_nodes) {
        if (level % 2 == 0) {
          values.emplace_back(node->val);
        } else {
          values.insert(values.begin(), node->val);
        }

        if (node->left) {
          next_level_nodes.emplace_back(std::move(node->left));
        }
        if (node->right) {
          next_level_nodes.emplace_back(std::move(node->right));
        }
      }
      level++;
      current_nodes = next_level_nodes;
      level_to_values.emplace_back(std::move(values));
    }

    return level_to_values;
  }
};
