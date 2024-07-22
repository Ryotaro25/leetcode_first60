class Solution {
public:
  static constexpr int kWater = 0;
  static constexpr int kLand = 1;
  static constexpr int kVisited = 2;

  bool is_inside(vector<vector<int>>& grid, int row, int column) {
    return 0 <= row && row < grid.size() && 0 <= column && column < grid[0].size();
  }

  int measure_island(vector<vector<int>>& grid, int row, int column, int area) {
    if (!is_inside(grid, row, column)) {
      return 0;
    }
    if (grid[row][column] == kWater || grid[row][column] == kVisited) {
      return 0;
    }

    grid[row][column] = kVisited;
    int area_measurement = 1;

    area_measurement += measure_island(grid, row - 1, column, area);
    area_measurement += measure_island(grid, row, column + 1, area);
    area_measurement += measure_island(grid, row + 1, column, area);
    area_measurement += measure_island(grid, row, column - 1, area);
    return area_measurement;
  }

  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int max_area = 0;
    int num_rows = grid.size();
    int num_colums = grid[0].size();

    for (int row = 0; row < num_rows; row++) {
      for (int column = 0; column < num_colums; column++) {
        if (grid[row][column] == kLand) {
          int area = measure_island(grid, row, column, area);
          max_area = max(area, max_area);
        }
      }
    }

    return max_area;
  }
};
