class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if (obstacleGrid[0][0] == OBSTACLE) {
      return 0;
    }

    int row_size = obstacleGrid.size();
    int column_size = obstacleGrid[0].size();
    vector<vector<int>> num_paths(row_size, vector<int>(column_size));

    for (int row = 0; row < row_size; row++) {
      for (int col = 0; col < column_size; col++) {
        if (obstacleGrid[row][col] == OBSTACLE) {
          num_paths[row][col] = 0;
          continue;
        }
        if (row == 0 && col == 0) {
          num_paths[row][col] = 1;
          continue;
        }
        if (row == 0) {
          num_paths[0][col] = num_paths[row][col - 1];
          continue;
        }
        if (col == 0) {
          num_paths[row][0] = num_paths[row - 1][col];
          continue;
        }

        num_paths[row][col] = num_paths[row - 1][col] + num_paths[row][col - 1];
      }
    }
    return num_paths[row_size - 1][column_size - 1];
  }

private:
  static constexpr int OBSTACLE = 1;
};
