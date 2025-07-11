class Solution {
  public:
    string convert(string s, int numRows) {
      if (numRows == 1) {
        return s;
      }
      vector<string> string_per_row(numRows);

      int direction = -1;
      int row = 0;
      for (char letter : s) {
        string_per_row[row] += letter;

        if (row == numRows - 1) {
          direction = -1;
        }
        if (row == 0) {
          direction = 1;
        }
        row += direction;
      }

      string converted = "";
      converted.reserve(s.size());
      for (const auto& str : string_per_row) {
        converted += str;
      }
      return converted;
    }
  };
