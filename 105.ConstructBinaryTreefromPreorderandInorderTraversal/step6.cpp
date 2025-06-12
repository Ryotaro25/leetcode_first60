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
    return BuildTreeHelper(preorder, 0, inorder, 0, inorder.size());
  }

private:
  TreeNode* BuildTreeHelper(const vector<int>& preorder, int preorder_start,
                            const vector<int>& inorder, int inorder_start, int tree_size) {
    if (tree_size <= 0) {
      return nullptr;
    }

    int value = preorder[preorder_start];
    TreeNode* node = new TreeNode(value);

    int inorder_root_index = FindSeparatingIndex(inorder, inorder_start, inorder_start + tree_size, value);
    int left_tree_size = inorder_root_index - inorder_start;

    node->left = BuildTreeHelper(preorder, preorder_start + 1,
                                 inorder, inorder_start, left_tree_size);

    node->right = BuildTreeHelper(preorder, preorder_start + 1 + left_tree_size,
                                  inorder, inorder_root_index + 1, tree_size - left_tree_size - 1);
    return node;
  }

  int FindSeparatingIndex(const vector<int>& inorder, int start, int end, int value) {
    for (int i = start; i < end; ++i) {
      if (inorder[i] == value) {
        return i;
      }
    }
    return -1;
  }
};
