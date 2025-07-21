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
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    if (nums.size() == 0) {
      return nullptr;
    }
    TreeNode* new_root = new TreeNode();
    queue<NodeAndIndex> node_and_index;
    node_and_index.emplace(new_root, 0, nums.size() - 1);

    while (!node_and_index.empty()) {
      auto [node, start_index, end_index] = node_and_index.front();
      node_and_index.pop();

      int middle = start_index + (end_index - start_index) / 2;
      node->val = nums[middle];

      if (start_index < middle) {
        node->left = new TreeNode();
        node_and_index.emplace(node->left, start_index, middle - 1);
      }

      if (middle < end_index) {
        node->right = new TreeNode();
        node_and_index.emplace(node->right, middle + 1, end_index);
      }
    }
    return new_root;
  }

private:
  struct NodeAndIndex {
    TreeNode* node;
    int start_index;
    int end_index;
  };
};
