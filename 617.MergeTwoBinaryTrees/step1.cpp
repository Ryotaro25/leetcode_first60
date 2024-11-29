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
  struct TwoNodes {
    TreeNode* first_node;
    TreeNode* second_node;
  };

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

    queue<TwoNodes> search_nodes;
    search_nodes.emplace(node1, node2);
    while (!search_nodes.empty()) {
      auto [first_node, second_node] = std::move(search_nodes.front());
      search_nodes.pop();

      first_node->val += second_node->val;

      if (first_node->left && second_node->left) {
        search_nodes.emplace(first_node->left, second_node->left);
      } else if (second_node->left) {
        first_node->left = second_node->left;
      }

      if (first_node->right && second_node->right) {
        search_nodes.emplace(first_node->right, second_node->right);
      } else if (second_node->right) {
        first_node->right = second_node->right;
      }
    }

    return node1;
  }
};
