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
    vector<vector<int>> level_to_zigzag_values = {};
    if (!root) {
      return level_to_zigzag_values;
    }

    int level = 0;
    deque<TreeNode*> current_level_nodes = {root};
    while (!current_level_nodes.empty()) {
      vector<int> values = {};
      int num_nodes = current_level_nodes.size();
      for (int i = 0; i < num_nodes; i++) {
        if (level % 2 == 0) {
          if (current_level_nodes.back()->left) {
            current_level_nodes.push_front(current_level_nodes.back()->left);
          }
          if (current_level_nodes.back()->right) {
            current_level_nodes.push_front(current_level_nodes.back()->right);
          }

          values.emplace_back(current_level_nodes.back()->val);
          current_level_nodes.pop_back();

        } else {
          if (current_level_nodes.front()->right) {
            current_level_nodes.push_back(current_level_nodes.front()->right);
          }

          if (current_level_nodes.front()->left) {
            current_level_nodes.push_back(current_level_nodes.front()->left);
          }

          values.emplace_back(current_level_nodes.front()->val);
          current_level_nodes.pop_front();
        }
      }
      level++;
      level_to_zigzag_values.emplace_back(values);
    }

    return level_to_zigzag_values;
  }
};
