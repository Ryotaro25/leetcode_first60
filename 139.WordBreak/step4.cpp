class Solution {
public:
  bool wordBreak(string str, vector<string>& wordDict) {
    set<string_view> word_dict(wordDict.begin(), wordDict.end());
    // 切り出されたstringが有効なのか関数の中で記録する
    map<string_view, bool> substring_to_breakable;
    return CheckWordBreakable(str, word_dict, substring_to_breakable);
  }

private:
  // string_viewのstrはデータを持っていない
  // 元の文字列データ(ここではwordBreak関数のstring str)へのポインターを管理している
  // コピーを発生させないため
  bool CheckWordBreakable(string_view str, const set<string_view>& word_dict,
                          map<string_view, bool>& substring_to_breakable) {
    if (word_dict.contains(str)) {
      return true;
    }

    if (substring_to_breakable.contains(str)) {
      return substring_to_breakable[str];
    }

    for (const auto& word : word_dict) {
      if (!str.starts_with(word)) {
        continue;
      }
      string_view remain = str.substr(word.size());
      if (CheckWordBreakable(remain, word_dict, substring_to_breakable)) {
        substring_to_breakable[str] = true;
        return true;
      }
    }

    substring_to_breakable[str] = false;
    return false;
  }
};
