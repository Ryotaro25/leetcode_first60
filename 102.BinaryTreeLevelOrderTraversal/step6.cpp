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
    if (!root) {
      return {};
    }

    vector<vector<int>> level_orderd_values;
    queue<TreeNode*> current_level_nodes;
    current_level_nodes.push(root);

    while (!current_level_nodes.empty()) {
      queue<TreeNode*> next_level_nodes;
      vector<int> same_level_values;
      int current_level_size = current_level_nodes.size();
      for (int i = 0; i < current_level_size; i++) {
        auto node = current_level_nodes.front();
        current_level_nodes.pop();

        same_level_values.push_back(node->val);
        if (node->left) {
          next_level_nodes.push(node->left);
        }
        if (node->right) {
          next_level_nodes.push(node->right);
        }
      }
      current_level_nodes = next_level_nodes;
      level_orderd_values.push_back(std::move(same_level_values));
    }
    return level_orderd_values;
  }
};
