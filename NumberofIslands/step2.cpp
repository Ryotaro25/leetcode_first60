class Solution {
public:
  void traverse_island(vector<vector<char>>& grid, const int& row, const int& column) {
    if (row < 0 || row >= grid.size() || column < 0 || column >= grid[0].size()) {
      return;
    }

    if (grid[row][column] == '0') {
      return;
    }
    grid[row][column] = '0';
    traverse_island(grid, row - 1, column);
    traverse_island(grid, row, column + 1);
    traverse_island(grid, row + 1, column);
    traverse_island(grid, row, column - 1);
  }

  int numIslands(vector<vector<char>>& grid) {
    int island_count = 0;

    for (int row = 0; row < grid.size(); row++) {
      for (int column = 0; column < grid[0].size(); column++) {
        if (grid[row][column] == '1') {
          traverse_island(grid, row, column);
          island_count++;
        }
      }
    }

    return island_count;
  }
};
