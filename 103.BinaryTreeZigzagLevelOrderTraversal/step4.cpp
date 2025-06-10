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
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if (!root) {
      return {};
    }
    vector<vector<int>> zigzag_level_orderd;
    bool is_left_to_right = true;
    queue<TreeNode*> processing_nodes;
    processing_nodes.push(root);
    while (!processing_nodes.empty()) {
      int node_size = processing_nodes.size();
      vector<int> same_level_nums;
      for (int i = 0; i < node_size; i++) {
        TreeNode* node = processing_nodes.front();
        processing_nodes.pop();
        same_level_nums.push_back(node->val);
        if (node->left) {
          processing_nodes.push(node->left);
        }
        if (node->right) {
          processing_nodes.push(node->right);
        }
      }
      if (!is_left_to_right) {
        reverse(same_level_nums.begin(), same_level_nums.end());
      }
      zigzag_level_orderd.push_back(std::move(same_level_nums));
      is_left_to_right = !is_left_to_right;
    }
    return zigzag_level_orderd;
  }
};
