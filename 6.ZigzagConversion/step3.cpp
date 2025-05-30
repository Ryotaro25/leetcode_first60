class Solution {
  public:
    string convert(string s, int numRows) {
      if (numRows == 1) {
        return s;
      }
      vector<string> string_per_row(numRows);

      bool is_downforward = true;
      int row = 0;
      for (char letter : s) {
        string_per_row[row] += letter;
        if (is_downforward) {
          row++;
        } else {
          row--;
        }

        if (row == numRows - 1) {
          is_downforward = false;
        }
        if (row == 0) {
          is_downforward = true;
        }
      }

      string converted = "";
      converted.reserve(s.size());
      for (const auto& str : string_per_row) {
        converted += str;
      }
      return converted;
    }
  };
