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

    vector<vector<int>> level_to_values;
    ConstructLevelOrder(root, level_to_values, 0);
    return level_to_values;
  }

private:
  void ConstructLevelOrder(const TreeNode* node , vector<vector<int>>& level_to_values, int level) {
    if (!node) {
      return;
    }
    if (level >= level_to_values.size()) {
      level_to_values.push_back({});
    }
    level_to_values[level].push_back(node->val);
    ConstructLevelOrder(node->left, level_to_values, level + 1);
    ConstructLevelOrder(node->right, level_to_values, level + 1);
  }
};
