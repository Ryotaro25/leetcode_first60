class Solution {
public:
  bool wordBreak(string str, vector<string>& wordDict) {
    set<string_view> word_dict(wordDict.begin(), wordDict.end());
    // 分割地点として処理済みか
    vector<char> proceeded(str.size() + 1, FALSE);
    proceeded[0] = TRUE;

    for (int start_position = 0; start_position < str.size(); start_position++) {
      if (!proceeded[start_position]) {
          continue;
      }

      for (int end_position = start_position + 1; end_position <= str.size(); end_position++) {
        if (proceeded[end_position]) {
          continue;
        }

        if (word_dict.contains(string_view(str.begin() + start_position, str.begin() + end_position))) {
          proceeded[end_position] = TRUE;
        }
      }
    }

    return proceeded[str.size()] == TRUE;
  }

private:
  static constexpr char TRUE = 1;
  static constexpr char FALSE = 0;
};
