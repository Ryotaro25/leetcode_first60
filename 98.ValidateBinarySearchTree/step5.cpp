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
    if (!root) {
      return false;
    }
    queue<NodeAndBounds> node_and_bounds;
    node_and_bounds.emplace(root, std::numeric_limits<int64_t>::min(), std::numeric_limits<int64_t>::max());
    while (!node_and_bounds.empty()) {
      auto [node, lower_bound, upper_bound] = node_and_bounds.front();
      node_and_bounds.pop();

      if (!(lower_bound < node->val && node->val < upper_bound)) {
        return false;
      }
      if (node->left) {
        node_and_bounds.emplace(node->left, lower_bound, node->val);
      }
      if (node->right) {
        node_and_bounds.emplace(node->right, node->val, upper_bound);
      }
    }
    return true;
  }

private:
  struct NodeAndBounds {
    TreeNode* node;
    int64_t lower_bound;
    int64_t upper_bound;
  };
};
