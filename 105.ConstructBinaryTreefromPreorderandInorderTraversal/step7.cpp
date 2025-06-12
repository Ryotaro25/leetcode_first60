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
    if (preorder.empty() || inorder.empty()) {
      return nullptr;
    }
    int preorder_index = 0;
    return BuildTreeHelper(preorder, inorder, preorder_index, 0, inorder.size() - 1);
  }

private:
  TreeNode* BuildTreeHelper(const vector<int>& preorder, const vector<int>& inorder,
                      int& preorder_index, int left, int right) {
    if (left > right) {
      return nullptr;
    }
    // preorderはroot left right の順なので、
    // 最初の要素が現在の部分木の root
    int root_value = preorder[preorder_index];
    TreeNode* node = new TreeNode(root_value);

    // inorderではleft root rightの順に並ぶので
    // root の位置で左右に分けられる
    int division_index = 0;
    for (int i = 0; i < inorder.size(); i++) {
      if (inorder[i] == root_value) {
        division_index = i;
        break;
      }
    }
    // preorder_indexを進めることで、
    // 次の部分木のrootを preorderから取得できる
    // 引数は参照渡しなので、左部分木の再帰での更新が右部分木の再帰にも反映される
    preorder_index++;
    node->left = BuildTreeHelper(preorder, inorder, preorder_index, left, division_index - 1);
    node->right = BuildTreeHelper(preorder, inorder, preorder_index, division_index + 1, right);
    return node;
  }
};
