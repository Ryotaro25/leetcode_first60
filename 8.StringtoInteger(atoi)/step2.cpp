class Solution {
  public:
    int myAtoi(string s) {
      // indexを勧めながら一文字ずつ前処理を行う
      int index = 0;
      while (index < s.size() && s[index] == ' ') {
        index++;
      }

      bool is_negative = false;
      if (index < s.size() && s[index] == '-') {
        is_negative = true;
        index++;
      } else if (index < s.size() && s[index] == '+') {
        is_negative = false;
        index++;
      }

      while (index < s.size() && s[index] == '0') {
        index++;
      }

      // 有効な数値を配列に入れる
      vector<char> numeric_strs;
      while (index < s.size() && isdigit(s[index])) {
        numeric_strs.push_back(s[index]);
        index++;
      }

      // intへの変換処理　桁ごとにオーバーフローしないかチェックする
      int converted = 0;
      for (int i = 0; i < numeric_strs.size(); i++) {
        int digit = numeric_strs[i] - '0';

        if (converted > numeric_limits<int>::max() / 10 ||
           (converted == numeric_limits<int>::max() / 10 && digit > numeric_limits<int>::max() % 10)) {
          if (is_negative) {
            return numeric_limits<int>::min();
          } else {
            return numeric_limits<int>::max();
          }
        }
        converted = converted * 10 + digit;
      }

      if (is_negative) {
        return -converted;
      } else {
        return converted;
      }
    }
  };
