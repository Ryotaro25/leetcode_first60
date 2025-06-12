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
  struct Nodes {
    TreeNode* new_node;
    TreeNode* first_node;
    TreeNode* second_node;
  };

public:
  TreeNode* mergeTrees(TreeNode* node1, TreeNode* node2) {
    if (!node1 && !node2) {
      return nullptr;
    }
    if (!node1) {
      return node2;
    }
    if (!node2) {
      return node1;
    }

    TreeNode* new_root = new TreeNode(node1->val + node2->val);

    queue<Nodes> search_nodes;
    search_nodes.emplace(new_root, node1, node2);

    while (!search_nodes.empty()) {
      const auto [current_node, first_node, second_node] = std::move(search_nodes.front());
      search_nodes.pop();

      // 左の子ノードを処理
      TreeNode* first_left = nullptr;
      TreeNode* second_left = nullptr;
      if (first_node) {
        first_left = first_node->left;
      }
      if (second_node) {
        second_left = second_node->left;
      }
      if (first_left || second_left) {
        int left_val = 0;
        if (first_left) {
          left_val += first_left->val;
        }
        if (second_left) {
          left_val += second_left->val;
        }
        current_node->left = new TreeNode(left_val);
        search_nodes.emplace(current_node->left, first_left, second_left);
      }

      // 右の子ノードを処理
      TreeNode* first_right = nullptr;
      TreeNode* second_right = nullptr;
      if (first_node) {
        first_right = first_node->right;
      }
      if (second_node) {
        second_right = second_node->right;
      }
      if (first_right || second_right) {
        int right_val = 0;
        if (first_right) {
          right_val += first_right->val;
        }
        if (second_right) {
          right_val += second_right->val;
        }
        current_node->right = new TreeNode(right_val);
        search_nodes.emplace(current_node->right, first_right, second_right);
      }
    }

    return new_root;
  }
};
