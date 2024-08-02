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
private:
  struct NodeAndDepth {
    TreeNode* node;
    int depth;
  };

public:
  int minDepth(TreeNode* root) {
    if (!root) {
      return 0;
    }

    queue<NodeAndDepth> candidates;
    candidates.emplace(root, 1);
    while (true) {
      auto [node, depth] = std::move(candidates.front());
      candidates.pop();

      if (!node->left && !node->right) {
        return depth;
      }
      if (node->left) {
        candidates.emplace(node->left, depth + 1);
      }
      if (node->right) {
        candidates.emplace(node->right, depth + 1);
      }
    }
  }
};
