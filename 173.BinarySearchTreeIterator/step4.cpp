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
class BSTIterator {
public:
  BSTIterator(TreeNode* root) {
    InorderTraverse(root);
  }
  
  // 問題文より有効である場合のみに呼ばれるため
  // 処理として値を返却するのみ
  int next() {
    int next_value = nodes_values.front();
    nodes_values.pop();
    return next_value;
  }
  
  bool hasNext() {
    return !nodes_values.empty();
  }

private:
  queue<int> nodes_values;

  void InorderTraverse(TreeNode* node) {
    if (!node) {
      return;
    }
    // 左に行けるところまで行く
    InorderTraverse(node->left);
    nodes_values.push(node->val);

    // 右に行けるところまで行く
    InorderTraverse(node->right);
  }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
