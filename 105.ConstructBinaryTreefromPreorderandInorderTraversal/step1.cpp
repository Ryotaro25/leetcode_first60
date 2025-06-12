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
    if (!inorder.empty()) {
      int value = preorder[0];
      preorder.erase(preorder.begin());

      TreeNode* node = new TreeNode(value);

      int index;
      for (int i = 0; i < inorder.size(); i++) {
        if (inorder[i] == value) {
          index = i;
        }
      }
      vector<int>::iterator position = inorder.begin() + index;
      vector<int> left_inorder(inorder.begin(), position);
      vector<int> right_inorder(position + 1, inorder.end());

      node->left = buildTree(preorder, left_inorder);
      node->right = buildTree(preorder, right_inorder);

      return node;
    }
    return nullptr;
  }
};
