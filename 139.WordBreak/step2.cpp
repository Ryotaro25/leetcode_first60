class Solution {
public:
  bool wordBreak(string s, vector<string>& wordDict) {
    set<string_view> word_dict(wordDict.begin(), wordDict.end());
    map<string_view, bool> word_to_validity;

    return CheckWordBreakable(s, word_dict, word_to_validity);
  }

private:
  bool CheckWordBreakable(string_view word, const set<string_view>& word_dict,
                          map<string_view, bool>& word_to_validity) {
    if (word_dict.contains(word)) {
      return true;
    }

    if (word_to_validity.contains(word)) {
      return word_to_validity[word];
    }

    for (int i = 0; i < word.size(); i++) {
      string_view left_side_word = word.substr(0, i + 1);

      if (word_dict.contains(left_side_word)) {
        string_view right_side_word = word.substr(i + 1);
        if (CheckWordBreakable(right_side_word, word_dict, word_to_validity)) {
          word_to_validity[word] = true;
          return true;
        }
      }
    }

    word_to_validity[word] = false;
    return false;
  }
};
