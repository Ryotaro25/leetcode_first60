class Solution {
public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    if (grid.empty()) {
      return 0;
    }

    int row_size = grid.size();
    int col_size = grid[0].size();
    int max_area_of_island = 0;
    for (int row = 0; row < grid.size(); row++) {
      for (int col = 0; col < grid[0].size(); col++) {
        if (grid[row][col] == WATER || grid[row][col] == VISITED) {
          continue;
        }
        int current_num_island = 0;
        CountIslandArea(grid, row, col, current_num_island);
        max_area_of_island = max(max_area_of_island, current_num_island);
      }
    }
    return max_area_of_island;
  }

private:
  static constexpr int LAND = 1;
  static constexpr int WATER = 0;
  static constexpr int VISITED = 2;

  void CountIslandArea(vector<vector<int>>& grid, int row, int col, int& num_islands) {
    if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) {
      return;
    }
    if (grid[row][col] == WATER) {
      return;
    }
    if (grid[row][col] == VISITED) {
      return;
    }
    grid[row][col] = VISITED;
    num_islands++;
    CountIslandArea(grid, row - 1, col, num_islands);
    CountIslandArea(grid, row, col + 1, num_islands);
    CountIslandArea(grid, row + 1, col, num_islands);
    CountIslandArea(grid, row, col - 1, num_islands);
  } 
};

// insted using vector<vector<bool>> to maintain visited area
// the constant int, marked as VISITED, can be used
// it reduce space complexity O(m * n) used for vecotr<vector<bool>>
// however, it overwrite the argument grid
// it possibly suprises user who call this function
