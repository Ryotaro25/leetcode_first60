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
  bool isSameTree(TreeNode* p, TreeNode* q) {
    queue<NodePair> node_pairs;
    node_pairs.push({p, q});
    while (!node_pairs.empty()) {
      auto [node, other_node] = node_pairs.front();
      node_pairs.pop();

      if (!IsSameNode(node, other_node)) {
        return false;
      }

      // 初手がnullptrの場合のチェック
      if (node && other_node) {
        if (!IsSameNode(node->left, other_node->left)) {
          return false;
        }
        if (node->left && other_node->left) {
          node_pairs.push({node->left, other_node->left});
        }

        if (!IsSameNode(node->right, other_node->right)) {
          return false;
        }
        if (node->right, other_node->right) {
          node_pairs.push({node->right, other_node->right});
        }
      }
    }
    return true;
  }

private:
  struct NodePair {
    TreeNode* node;
    TreeNode* other_node;
  };

  bool IsSameNode (TreeNode* node, TreeNode* other_node) {
    if (!node && !other_node) {
      return true;
    }
    if (!node || !other_node) {
      return false;
    }
    return node->val == other_node->val;
  }
};
