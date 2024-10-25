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
    dfs(root);
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

  void dfs(TreeNode* node) {
    if (node) {
      dfs(node->left);
      index++;
      nodes[index] = node->val;
      dfs(node->right);
    }
  }

};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
