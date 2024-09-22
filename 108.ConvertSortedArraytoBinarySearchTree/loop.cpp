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
    queue<NodeAndNums> node_and_nums;
    node_and_nums.emplace(new_root, nums);

    while (!node_and_nums.empty()) {
      auto [node, search_nums] = node_and_nums.front();
      node_and_nums.pop();

      int middle = search_nums.size() / 2;
      node->val = search_nums[middle];

      vector<int> left_nums(search_nums.begin(), search_nums.begin() + middle);
      if (left_nums.size() > 0) {
        node->left = new TreeNode();
        node_and_nums.emplace(node->left, left_nums);
      }

      vector<int> right_nums(search_nums.begin() + middle + 1, search_nums.end());
      if (right_nums.size() > 0) {
        node->right = new TreeNode();
        node_and_nums.emplace(node->right, right_nums);
      }
    }
    return new_root;
  }

private:
  struct NodeAndNums {
    TreeNode* node;
    vector<int> nums;
  };
};
