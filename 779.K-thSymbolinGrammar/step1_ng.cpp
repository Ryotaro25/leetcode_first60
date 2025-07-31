class Solution {
public:
  int kthGrammar(int n, int k) {
    vector<string> rows_for_num(n + 1);
    rows_for_num[1] = "0";

    for (int i = 2; i <= n; i++) {
      string previous = rows_for_num[i - 1];
      string replaced;
      for (int j = 0; j < previous.size(); j++) {
        if (previous[j] == '0') {
          replaced.append("01");
        } else if (previous[j] == '1') {
          replaced.append("10");
        }
      }

      rows_for_num[i] = replaced;
    }

    return rows_for_num.back()[k - 1] - '0';
  }
};
