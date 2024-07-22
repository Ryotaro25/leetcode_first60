class Solution {
public:
  const char Land = '1';
  const char Water = '0';
  const char Visited = '2';

  void traverse_island(vector<vector<char>>& grid, const int& row, const int& column) {
    if (!is_inside(grid, row, column)) {
      return;
    }

    if (grid[row][column] == Water || grid[row][column] == Visited) {
      return;
    }
    grid[row][column] = Visited;
    traverse_island(grid, row - 1, column);
    traverse_island(grid, row, column + 1);
    traverse_island(grid, row + 1, column);
    traverse_island(grid, row, column - 1);
  }

  bool is_inside(vector<vector<char>>& grid, const int& row, const int& column) {
  if ((0 <= row  && row < grid.size()) && (0 <= column && column < grid[0].size())) {
    return true;
  }

    return false;
  }

  int numIslands(vector<vector<char>>& grid) {
    int island_count = 0;

    for (int row = 0; row < grid.size(); row++) {
      for (int column = 0; column < grid[0].size(); column++) {
        if (grid[row][column] == Land) {
          traverse_island(grid, row, column);
          island_count++;
        }
      }
    }

    return island_count;
  }
};
