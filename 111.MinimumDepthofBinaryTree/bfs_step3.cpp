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
  int minDepth(TreeNode* root) {
    if (!root) {
      return 0;
    }

    queue<NodeAndDepth> node_and_depth;
    node_and_depth.push({root, 1});
    int min_depth = std::numeric_limits<int>::max();
    while (!node_and_depth.empty()) {
      auto [node, depth] = node_and_depth.front();
      node_and_depth.pop();
      if (!node->left && !node->right) {
        min_depth = min(min_depth, depth);
      }

      if (node->left) {
        node_and_depth.push({node->left, depth + 1});
      }
      if (node->right) {
        node_and_depth.push({node->right, depth + 1});
      }
    }
    return min_depth;
  }

private:
  struct NodeAndDepth {
    TreeNode* node;
    int depth;
  };
};
