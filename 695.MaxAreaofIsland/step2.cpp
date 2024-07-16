class Solution {
public:
  const int Water = 0;
  const int Land = 1;
  const int Visited = 2;

  bool is_inside(vector<vector<int>>& grid, const int& row, const int& column) {
    return row >= 0 && row < grid.size() && column >= 0 && column < grid[0].size();
  }

  int measure_island(vector<vector<int>>& grid, const int& row, const int& column, int& area) {
    if (!is_inside(grid, row, column)) {
      return 0;
    }
    if (grid[row][column] == Water || grid[row][column] == Visited) {
      return 0;
    }

    grid[row][column] = Visited;
    area++;

    measure_island(grid, row + 1, column, area);
    measure_island(grid, row, column - 1, area);
    return area;
  }

  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int max_area = 0;
    int row_size = grid.size();
    int column_size = grid[0].size();

    for (int row = 0; row < row_size; row++) {
      for (int column = 0; column < column_size; column++) {
        if (grid[row][column] == Land) {
          int area = 0;
          max_area = max(measure_island(grid, row, column, area), max_area);
        }
      }
    }

    return max_area;
  }
};
