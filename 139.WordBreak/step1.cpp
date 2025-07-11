class Solution {
public:
  bool wordBreak(string s, vector<string>& wordDict) {
    set<string> word_dict(wordDict.begin(), wordDict.end());
    map<string, bool> word_to_validity;

    return CheckWordBreak(s, word_dict, word_to_validity);
  }

private:
  bool CheckWordBreak(const string& word, const set<string>& word_dict, map<string, bool>& word_to_validity) {
    if (word_dict.contains(word)) {
      return true;
    }

    if (word_to_validity.contains(word)) {
      return word_to_validity[word];
    }

    for (int i = 0; i < word.size(); i++) {
      string left_side_word = word.substr(0, i + 1);

      if (word_dict.contains(left_side_word)) {
        string right_side_word = word.substr(i + 1);
        bool rest_word_validity = CheckWordBreak(right_side_word, word_dict, word_to_validity);
        if (rest_word_validity) {
          word_to_validity[word] = true;
          return true;
        }
      }
    }

    word_to_validity[word] = false;
    return false;
  }
};
