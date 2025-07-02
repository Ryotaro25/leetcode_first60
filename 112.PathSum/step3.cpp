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
    queue<NodeAndSum> candidates;
    candidates.emplace(root, 0);
    while (!candidates.empty()) {
      auto [node, sum] = candidates.front();
      candidates.pop();
      if (!node) {
        continue;
      }
      sum += node->val;
      if (!node->left && !node->right && sum == targetSum) {
        return true;
      }
      candidates.emplace(node->left, sum);
      candidates.emplace(node->right, sum);
    }
    return false;
  }

private:
  struct NodeAndSum {
    TreeNode* node;
    int sum;
  };
};
