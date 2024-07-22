class Solution {
public:
  void traverse_island(vector<vector<char>>& grid, int i, int j) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
      return;
    }

    if (grid[i][j] == '0') {
      return;
    }
    grid[i][j] = '0';
    traverse_island(grid, i - 1, j);
    traverse_island(grid, i, j + 1);
    traverse_island(grid, i + 1, j);
    traverse_island(grid, i, j - 1);
  }

  int numIslands(vector<vector<char>>& grid) {
    int island_count = 0;

    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == '1') {
          traverse_island(grid, i, j);
          island_count++;
        }
      }
    }

    return island_count;
  }
};
