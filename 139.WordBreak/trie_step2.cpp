class Solution {
public:
  bool wordBreak(string s, vector<string>& wordDict) {
    auto root = BuildTrieNode(wordDict);

    vector<char> is_segmented(s.size());
    for (int start = 0; start < s.size(); start++) {
      if (start == 0 || is_segmented[start - 1]) {
        if (SearchString(root, s, start, is_segmented)) {
          is_segmented[start] = TRUE;
        }
      }
    }
    return is_segmented.back();
  }

private:
  static constexpr char TRUE = 1;
  static constexpr char FALSE = 0;

  struct TrieNode {
    bool is_word;
    map<char, TrieNode*> children;
    TrieNode() : is_word(false), children(map<char, TrieNode*>()){}
  };

  unique_ptr<TrieNode> BuildTrieNode(const vector<string> word_dict) {
    // スマートポインタで管理
    unique_ptr<TrieNode> root = make_unique<TrieNode>();
    for (auto word : word_dict) {
      TrieNode* node = root.get();
      for (char letter : word) {
        if (!node->children.contains(letter)) {
          node->children[letter] = new TrieNode();
        }
        node = node->children[letter];
      }
      node->is_word = TRUE;
    }
    return root;
  }

  bool SearchString(const unique_ptr<TrieNode>& root, const string& str,
                    int start, vector<char>& is_segmented) {
    auto node = root.get();
    for (int end = start; end < str.size(); end++) {
      char letter = str[end];
      if (!node->children.contains(letter)) {
        break;
      }

      node = node->children[letter];
      if (node->is_word) {
        is_segmented[end] = TRUE;
      }
    }
    return is_segmented[str.size() - 1];
  }
};
