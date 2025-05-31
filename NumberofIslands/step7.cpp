class Solution {
public:
  int numIslands(vector<vector<char>>& grid) {
    if (grid.empty()) {
      return 0;
    }
    int row_size = grid.size();
    int col_size = grid[0].size();
    int num_islands = 0;
    for (int row = 0; row < row_size; row++) {
      for (int col = 0; col < col_size; col++) {
        if (grid[row][col] == LAND) {
          TraverseIsland(grid, row, col);
          num_islands++;
        }
      }
    }
    return num_islands;
  }

private:
  static constexpr char LAND = '1';
  static constexpr char WATER = '0';

  void TraverseIsland(vector<vector<char>>& grid, int row, int col) {
    if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) {
      return;
    }
    if (grid[row][col] == WATER) {
      return;
    }
    grid[row][col] = WATER;
    TraverseIsland(grid, row - 1, col);
    TraverseIsland(grid, row, col + 1);
    TraverseIsland(grid, row + 1, col);
    TraverseIsland(grid, row, col - 1);
  }
};
