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
  struct TwoNodes {
    TreeNode* first_node;
    TreeNode* second_node;
  };

  void MergeOrPushQueue(queue<TwoNodes> &search_nodes, TreeNode*& first_node, TreeNode* const second_node) {
    if (first_node && second_node) {
      search_nodes.emplace(first_node, second_node);
    } else if (second_node) {
      first_node = second_node;
    }
  }

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

    queue<TwoNodes> search_nodes;
    search_nodes.emplace(node1, node2);
    while (!search_nodes.empty()) {
      auto [first_node, second_node] = std::move(search_nodes.front());
      search_nodes.pop();

      first_node->val += second_node->val;

      MergeOrPushQueue(search_nodes, first_node->left, second_node->left);
      MergeOrPushQueue(search_nodes, first_node->right, second_node->right);
    }

    return node1;
  }
};
