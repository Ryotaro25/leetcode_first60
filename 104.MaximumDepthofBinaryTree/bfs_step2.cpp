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
struct NodeAndDepth {
  TreeNode* node;
  int depth;
};

class Solution {
public:
  int maxDepth(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }

    queue<NodeAndDepth> candidates;
    candidates.push({root, 1});
    int max_depth = 0;
    while (!candidates.empty()) {
      const auto [node, depth] = candidates.front();
      candidates.pop();
      if (node == nullptr) {
        continue;
      }
      max_depth = depth;
      candidates.push({node->left, depth + 1});
      candidates.push({node->right, depth + 1});
    }

    return max_depth;
  }
};
