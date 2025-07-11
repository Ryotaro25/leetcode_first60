class Solution {
  public:
    string convert(string s, int numRows) {
      if (numRows == 1) {
        return s;
      }
      vector<vector<char>> transcription(numRows, vector<char>(s.size(), ' '));

      bool is_downforward = true;
      int row = 0;
      int col = 0;
      for (int i = 0; i < s.size(); i++) {
        transcription[row][col] = s[i];

        if (is_downforward) {
          if (row == numRows - 1) {
            is_downforward = false;
            row--;
            col++;
          } else {
            row++;
          }
        } else {
          if (row == 0) {
            is_downforward = true;
            row++;
          } else {
            row--;
            col++;
          }
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
