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
  vector<TreeNode*> splitBST(TreeNode* node, int target) {
    if (!node) {
      return {nullptr, nullptr};
    }

    if (node->val <= target) {
      // 左側はtargetより小さいので右側を探索する
      vector<TreeNode*> right_child = splitBST(node->right, target);
      node->right = right_child[0];
      return {node, right_child[1]}
    } else {
      vector<TreeNode*> left_child = splitBST(node->left, target);
      node->left = left_child[1];
      return {left_child[0], node}
    }
  }
};
