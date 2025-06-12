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
    if (!node1 && !node2) {
      return nullptr;
    }
    TreeNode* new_root = new TreeNode();
    queue<MergedAndOriginalNodes> search_nodes;
    search_nodes.push({new_root, node1, node2});

    while (!search_nodes.empty()) {
      auto [current_node, first_node, second_node] = search_nodes.front();
      search_nodes.pop();

      int current_val = 0;
      if (first_node) {
        current_val += first_node->val;
      }
      if (second_node) {
        current_val += second_node->val;
      }
      current_node->val = current_val;

      // 左の子ノードを処理
      TreeNode* first_left = nullptr;
      if (first_node) {
        first_left = first_node->left;
      }
      TreeNode* second_left = nullptr;
      if (second_node) {
        second_left = second_node->left;
      }
      if (first_left || second_left) {
        current_node->left = new TreeNode();
        search_nodes.emplace(current_node->left, first_left, second_left);
      }

      // 右の子ノードを処理
      TreeNode* first_right = nullptr;
      if (first_node) {
        first_right = first_node->right;
      }
      TreeNode* second_right = nullptr;
      if (second_node) {
        second_right = second_node->right;
      }
      if (first_right || second_right) {
        current_node->right = new TreeNode();
        search_nodes.push({current_node->right, first_right, second_right});
      }
    }

    return new_root;
  }

private:
  struct MergedAndOriginalNodes {
    TreeNode* node;
    TreeNode* left_child;
    TreeNode* right_child;
  };
};
