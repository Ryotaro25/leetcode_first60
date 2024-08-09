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
  TreeNode* mergeTrees(TreeNode* node1, TreeNode* node2) {
    TreeNode* new_root = new TreeNode();
    queue<Nodes> search_nodes;
    search_nodes.emplace(new_root, node1, node2);

    while (!search_nodes.empty()) {
      auto [current_node, left_child, right_child] = search_nodes.front();
      search_nodes.pop();
      if (!left_child && !right_child) {
        return nullptr;
      }

      int current_val = 0;
      if (left_child) {
        current_val += left_child->val;
      }
      if (right_child) {
        current_val += right_child->val;
      }
      current_node->val = current_val;

      // 左の子ノードを処理
      TreeNode* left_first = nullptr;
      if (left_child && left_child->left) {
        left_first = left_child->left;
      }
      TreeNode* left_second = nullptr;
      if (right_child && right_child->left) {
        left_second = right_child->left;
      }
      if (left_first || left_second) {
        current_node->left = new TreeNode();
        search_nodes.emplace(current_node->left, left_first, left_second);
      }

      // 右の子ノードを処理
      TreeNode* right_first = nullptr;
      if (left_child && left_child->right) {
        right_first = left_child->right;
      }
      TreeNode* right_second = nullptr;
      if (right_child && right_child->right) {
        right_second = right_child->right;
      }
      if (right_first || right_second) {
        current_node->right = new TreeNode();
        search_nodes.emplace(current_node->right, right_first, right_second);
      }
    }

    return new_root;
  }

private:
  struct Nodes {
    TreeNode* node;
    TreeNode* left_child;
    TreeNode* right_child;
  };
};
