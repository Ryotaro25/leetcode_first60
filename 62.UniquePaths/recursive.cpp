class Solution {
public:
  int uniquePaths(int row, int col) {
    if (row == 1 || col == 1) {
      return 1;
    }
    return uniquePaths(row - 1, col) + uniquePaths(row, col - 1);
  }
};
