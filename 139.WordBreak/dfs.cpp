class Solution {
public:
  bool wordBreak(string s, vector<string>& wordDict) {
    map<string_view, bool> word_to_validity;
    return CheckWordBreak(s, wordDict, word_to_validity);
  }

private:
  bool CheckWordBreak(const string_view& target, const vector<string>& word_dict,
                      map<string_view, bool>& word_to_validity) {
    if (word_to_validity.contains(target)) {
      return word_to_validity[target];
    }

    if (target.empty()) {
      return true;
    }

    for (const auto word : word_dict) {
      // targetがwordから始まっているかどうかをチェック
      if (target.starts_with(word)) {
        string_view remaining = target.substr(word.size());
        if (CheckWordBreak(remaining, word_dict, word_to_validity)) {
          word_to_validity[target] = true;
          return true;
        }
      }
    }

    word_to_validity[target] = false;
    return false;
  }
};
