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
  bool isValidBST(TreeNode* root) {
    if (!root) {
      return true;
    }
    queue<NodeAndRange> nodes;
    // LONG_MINはlong型のもの
    // https://en.cppreference.com/w/cpp/types/climits
    // C++11 以降の C++ では、 std::numeric_limits::min() と std::numeric_limits::max() を使用する
    // https://en.cppreference.com/w/cpp/types/numeric_limits/min
    // https://en.cppreference.com/w/cpp/types/numeric_limits/max
    nodes.emplace(root, numeric_limits<int64_t>::min(), numeric_limits<int64_t>::max());
    while (!nodes.empty()) {
      const auto [node, lower_value, upper_value] = nodes.front();
      nodes.pop();
      if (node->val <= lower_value || node->val >= upper_value) {
        return false;
      }
      if (node->left) {
        nodes.emplace(node->left, lower_value, node->val);
      }
      if (node->right) {
        nodes.emplace(node->right, node->val, upper_value);
      }
    }
    return true;
  }

private:
  struct NodeAndRange {
    TreeNode* node;
    int64_t lower_value;
    int64_t upper_value;
  };
};
