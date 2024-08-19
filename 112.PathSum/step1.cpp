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
  bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) {
      return false;
    }

    queue<NodeAndSum> candidates;
    candidates.emplace(root, root->val);
    while (!candidates.empty()) {
      auto [node, sum] = candidates.front();
      candidates.pop();

      if (!node->left && !node->right && sum == targetSum) {
        return true;
      }
      if (node->left) {
        candidates.emplace(node->left, sum + node->left->val);
      }
      if (node->right) {
        candidates.emplace(node->right, sum + node->right->val);
      }
    }
    return false;
  }

private:
  struct NodeAndSum {
    TreeNode* node;
    int sum;
  };
};
