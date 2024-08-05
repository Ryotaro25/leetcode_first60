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
      auto [current_node, first_node, second_node] = search_nodes.front();
      search_nodes.pop();
      if (!first_node && !second_node) {
        return nullptr;
      }

      int current_val = 0;
      if (first_node) {
        current_val += first_node->val;
      }
      if (second_node) {
        current_val += second_node->val;
      }
      current_node->val = current_val;

      // 左の子ノードを処理
      TreeNode* left_first = nullptr;
      if (first_node && first_node->left) {
        left_first = first_node->left;
      }
      TreeNode* left_second = nullptr;
      if (second_node && second_node->left) {
        left_second = second_node->left;
      }
      if (left_first || left_second) {
        current_node->left = new TreeNode();
        search_nodes.emplace(current_node->left, left_first, left_second);
      }

      // 右の子ノードを処理
      TreeNode* right_first = nullptr;
      if (first_node && first_node->right) {
        right_first = first_node->right;
      }
      TreeNode* right_second = nullptr;
      if (second_node && second_node->right) {
        right_second = second_node->right;
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
    TreeNode* current_node;
    TreeNode* first_node;
    TreeNode* second_node;
  };
};
