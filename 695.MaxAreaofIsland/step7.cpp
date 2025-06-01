class Solution {
public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    if (grid.empty()) {
      return 0;
    }
    int row_size = grid.size();
    int col_size = grid[0].size();
    vector<vector<bool>> visited(row_size, vector<bool>(col_size, false));
    int max_area_of_island = 0;
    for (int row = 0; row < grid.size(); row++) {
      for (int col = 0; col < grid[0].size(); col++) {
        if (grid[row][col] == WATER) {
          continue;
        }
        int current_num_island = 0;
        CountIslandArea(grid, row, col, current_num_island, visited);
        max_area_of_island = max(max_area_of_island, current_num_island);
      }
    }
    return max_area_of_island;
  }

private:
  static constexpr int LAND = 1;
  static constexpr int WATER = 0;

  void CountIslandArea(vector<vector<int>>& grid, int row, int col, int& num_islands, vector<vector<bool>>& visited) {
    if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) {
      return;
    }
    if (grid[row][col] == WATER) {
      return;
    }
    if (visited[row][col]) {
      return;
    }
    visited[row][col] = true;
    num_islands++;
    CountIslandArea(grid, row - 1, col, num_islands, visited);
    CountIslandArea(grid, row, col + 1, num_islands, visited);
    CountIslandArea(grid, row + 1, col, num_islands, visited);
    CountIslandArea(grid, row, col - 1, num_islands, visited);
  } 
};

// traverse all grid
// if the gird is land, the count funcsion will start
// in the count function, the land should be recoreded in the visited 
// in the count fucntion the water will be ignored
