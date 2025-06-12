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
    return BuildTreeHelper(preorder, 0, preorder.size(), inorder, 0,
                           inorder.size());
  }

private:
  TreeNode* BuildTreeHelper(const vector<int>& preorder, int preorder_start, int preorder_end,
                            const vector<int>& inorder, int inorder_start, int inorder_end) {
    if (preorder_start >= preorder_end || inorder_start >= inorder_end) {
      return nullptr;
    }

    int value = preorder[preorder_start];
    TreeNode* node = new TreeNode(value);

    int position = FindSeparatingPosition(inorder, inorder_start, inorder_end, value);

    int left_tree_size = position - inorder_start + 1;
    node->left = BuildTreeHelper(preorder, preorder_start + 1, preorder_start + left_tree_size,
                                 inorder, inorder_start, position);
    node->right = BuildTreeHelper(preorder, preorder_start + left_tree_size, preorder_end,
                                  inorder, position + 1, inorder_end);
    return node;
  }

  int FindSeparatingPosition(const vector<int>& inorder, int start, int end, int value) {
    for (int i = start; i < end; ++i) {
      if (inorder[i] == value) {
        return i;
      }
    }
    return -1;
  }
};