class Solution {
  public:
    string convert(string s, int numRows) {
      if (numRows == 1) {
        return s;
      }
      // 文字が上から下に配置され、次に斜めに配置される部分を1セクションとする
      // 上から下へはnumRows文字必要で下から上へ斜めにnumRows-2文字必要
      // 1セクションには合計numRows + (numRows - 2)文字が必要。
      // 必要なセクション数は、文字列の長さs.size()を(2*numRows - 2)で割った値。
      // 各セクションは、numRows - 1列が必要。
      int num_cols = ceil(s.size() / (2 * numRows - 2.0)) * (numRows - 1);
      vector<vector<char>> transcription(numRows, vector<char>(num_cols, ' '));

      bool is_downforward = true;
      int row = 0;
      int col = 0;
      for (int i = 0; i < s.size(); i++) {
        transcription[row][col] = s[i];

        if (is_downforward) {
          row++;
        } else {
          row--;
          col++;
        }

        if (row == numRows - 1) {
          is_downforward = false;
        }
        if (row == 0) {
          is_downforward = true;
        }
      }

      string converted = "";
      for (int row = 0; row < transcription.size(); row++) {
        for (int col = 0; col < transcription[0].size(); col++) {
          if (transcription[row][col] == ' ') {
            continue;
          }
          converted.push_back(transcription[row][col]);
        }
      }
      return converted;
    }
  };
