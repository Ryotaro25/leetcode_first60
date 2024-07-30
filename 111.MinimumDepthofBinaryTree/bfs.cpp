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
    if (root == nullptr) {
      return 0;
    }

    queue<NodeAndDepth> candidates;
    candidates.emplace(root, 1);
    while (!candidates.empty()) {
      auto [node, depth] = std::move(candidates.front());
      candidates.pop();

      if (node->left == nullptr && node->right == nullptr) {
        return depth;
      }
      if (node->left != nullptr) {
        candidates.emplace(node->left, depth + 1);
      }
      if (node->right != nullptr) {
        candidates.emplace(node->right, depth + 1);
      }
    }
    return 0;
  }
};
