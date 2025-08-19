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
  bool isValidBST(TreeNode* root) {
    queue<NodesAndRanges> nodes_and_ranges;
    nodes_and_ranges.emplace(root, LONG_MIN, LONG_MAX);

    while (!nodes_and_ranges.empty()) {
      const auto [node, lower_value, upper_value] = nodes_and_ranges.front();
      nodes_and_ranges.pop();
      if (node->val <= lower_value || node->val >= upper_value) {
        return false;
      }
      if (node->left) {
        nodes_and_ranges.emplace(node->left, lower_value, node->val);
      }
      if (node->right) {
        nodes_and_ranges.emplace(node->right, node->val, upper_value);
      }
    }
    return true;
  }

private:
  struct NodesAndRange {
    TreeNode* node;
    long long lower_value;
    long long upper_value;
  };
};
