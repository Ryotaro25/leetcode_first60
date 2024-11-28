class Solution {
public:
  bool wordBreak(string s, vector<string>& wordDict) {
    TrieNode* root = new TrieNode();
    for (auto word : wordDict) {
      TrieNode* node = root;
      for (char letter : word) {
        if (!node->children.contains(letter)) {
          node->children[letter] = new TrieNode();
        }
        node = node->children[letter];
      }
      node->is_word = true;
    }

    vector<bool> is_segmented(s.size());
    for (int start = 0; start < s.size(); start++) {
      if (start == 0 || is_segmented[start - 1]) {
        TrieNode* node = root;
        for (int end = start; end < s.size(); end++) {
          char letter = s[end];
          if (!node->children.contains(letter)) {
            break;
          }

          node = node->children[letter];
          if (node->is_word) {
            is_segmented[end] = true;
          }
        }
      }
    }
    return is_segmented.back();
  }

private:
  struct TrieNode {
    bool is_word;
    map<char, TrieNode*> children;
    TrieNode() : is_word(false), children(map<char, TrieNode*>()){}
  };
};
