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
  
  int next() {
    current_index++;
    return nodes[current_index];
  }
  
  bool hasNext() {
    return current_index < index;
  }

private:
  map<int, int> nodes;
  int index = 0;
  int current_index = 0;

  void InorderTraverse(TreeNode* node) {
    if (node) {
      InorderTraverse(node->left);
      index++;
      nodes[index] = node->val;
      InorderTraverse(node->right);
    }
  }

};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
