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
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    for (int i = 0; i < inorder.size(); i++) {
      inorder_value_to_index[inorder[i]] = i;
    }

    int preorder_index = 0;
    return BuildTreeHelper(0, inorder.size(), preorder, preorder_index);
  }

private:
  unordered_map<int, int> inorder_value_to_index;

  TreeNode* BuildTreeHelper(int left_bound, int right_bound, vector<int>& preorder, int& preorder_index) {
    if (left_bound >= right_bound) {
      return nullptr;
    }

    int value = preorder[preorder_index];
    TreeNode* node = new TreeNode(value);

    int inorder_index = inorder_value_to_index[value];
    preorder_index++;
    node->left = BuildTreeHelper(left_bound, inorder_index, preorder, preorder_index);
    node->right = BuildTreeHelper(inorder_index + 1, right_bound, preorder, preorder_index);
    return node;
  }
};
