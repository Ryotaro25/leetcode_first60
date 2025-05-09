class Solution {
public:
  bool wordBreak(string str, vector<string>& wordDict) {
    set<string_view> word_dict(wordDict.begin(), wordDict.end());
    queue<int> dividing_positions;
    dividing_positions.push(0);
    // 分割地点として処理済みか
    vector<char> proceeded(str.size() + 1, FALSE);

    while (!dividing_positions.empty()) {
      int start_position = dividing_positions.front();
      dividing_positions.pop();

      if (start_position == str.size()) {
        return true;
      }
      // 文字列の長さの最大値で打ち切ったほうが、計算量が落ち、速くなると思います。
      for (int end_position = start_position + 1; end_position <= str.size(); end_position++) {
        if (proceeded[end_position]) {
          continue;
        }
        // begin() end()はそれぞれイテレーター
        if (word_dict.contains(string_view(str.begin() + start_position, str.begin() + end_position))) {
          dividing_positions.push(end_position);
          proceeded[end_position] = TRUE;
        }
      }
    }

    return false;
  }

private:
  static constexpr char TRUE = 1;
  static constexpr char FALSE = 0;
};
