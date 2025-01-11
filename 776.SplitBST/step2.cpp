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
  vector<TreeNode*> splitBST(TreeNode* root, int target) {
    TreeNode* node = root;

    TreeNode* smaller_head = new TreeNode();
    TreeNode* smaller = smaller_head;

    TreeNode* bigger_head = new TreeNode();
    TreeNode* larger = bigger_head;

    while (node) {
      if (node->val > target) {
        // 現在のnodeの値の方が小さいのでnodeを左側に紐づける
        larger->left = node;
        larger = larger->left;
        // 小さい数字が含まれているので左側に探索を進める
        node = node->left;
        larger->left = nullptr;
      }  else {
        // 現在のnodeの値の方が大きいのでnodeを右側に紐づける
        smaller->right = node;
        smaller = smaller->right;
        // 大きい数字が含まれているので右側に探索を進める
        node = node->right;
        smaller->right = nullptr;
      }
    }

    return {smaller_head->right, bigger_head->left};
  }
};
