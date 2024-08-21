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
    map<int, vector<int>> level_to_values;

    queue<NodeAndDepth> node_and_depth;
    node_and_depth.emplace(root, 0);
    while (!node_and_depth.empty()) {
      auto [node, depth] = node_and_depth.front();
      node_and_depth.pop();

      level_to_values[depth].emplace_back(node->val);
      if (node->left) {
        node_and_depth.emplace(node->left, depth + 1);
      }
      if (node->right) {
        node_and_depth.emplace(node->right, depth + 1);
      }
    }

    vector<vector<int>> values;
    for (const auto& [depth, vals] : level_to_values) {
      values.emplace_back(vals);
    }

    return values;
  }

private:
  struct NodeAndDepth {
    TreeNode* node;
    int depth;
  };
};
