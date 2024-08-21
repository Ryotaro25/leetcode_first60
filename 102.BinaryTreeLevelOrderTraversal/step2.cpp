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

    queue<TreeNode*> same_level_nodes;
    same_level_nodes.emplace(root);
    while (!same_level_nodes.empty()) {
      int nodes_num = same_level_nodes.size();
      vector<int> values = {};
      for (int i = 0; i < nodes_num; i++) {
        auto node = same_level_nodes.front();
        same_level_nodes.pop();

        if (!node) {
          continue;
        }
        values.emplace_back(node->val);
        same_level_nodes.emplace(node->left);
        same_level_nodes.emplace(node->right);
      }
      
      if (!values.empty()) {
        level_to_values.emplace_back(values);
      }
    }

    return level_to_values;
  }
};
