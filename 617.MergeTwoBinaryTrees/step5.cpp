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
  TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    if (!root1 && !root2) {
      return nullptr;
    }
    if (!root1) {
      return root2;
    }
    if (!root2) {
      return root1;
    }
    queue<pair<TreeNode*, TreeNode*>> node_pairs;
    node_pairs.push({root1, root2});
    while (!node_pairs.empty()) {
      auto [node1, node2] = node_pairs.front();
      node_pairs.pop();

      if (!node1 || !node2) {
        continue;
      }
      node1->val += node2->val;
      if (!node1->left) {
        node1->left = node2->left;
      } else {
        node_pairs.push({node1->left, node2->left});
      }
      if (!node1->right) {
        node1->right = node2->right;
      } else {
        node_pairs.push({node1->right, node2->right});
      }
    }
    return root1;
  }
};
