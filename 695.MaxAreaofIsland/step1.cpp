class Solution {
public:
  const int Water = 0;
  const int Land = 1;
  const int Visited = 2;

  bool is_inside(vector<vector<int>>& grid, const int& row, const int& column) {
    return row >= 0 && row < grid.size() && column >= 0 && column < grid[0].size();
  }

  int measure_island(vector<vector<int>>& grid, const int& row, const int& column, int& size) {
    if (!is_inside(grid, row, column)) {
      return 0;
    }
    if (grid[row][column] == Water || grid[row][column] == Visited) {
      return 0;
    }

    grid[row][column] = Visited;
    size++;

    measure_island(grid, row - 1, column, size);
    measure_island(grid, row, column + 1, size);
    measure_island(grid, row + 1, column, size);
    measure_island(grid, row, column - 1, size);
    return size;
  }

  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int max_size = 0;
    int row_size = grid.size();
    int column_size = grid[0].size();

    for (int row = 0; row < row_size; row++) {
      for (int column = 0; column < column_size; column++) {
        if (grid[row][column] == Land) {
          int size = 0;
          max_size = max(measure_island(grid, row, column, size), max_size);
        }
      }
    }

    return max_size;
  }
};
