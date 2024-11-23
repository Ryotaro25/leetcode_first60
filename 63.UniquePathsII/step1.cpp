class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if (obstacleGrid[0][0] == OBSTACLE) {
      return 0;
    }

    int row_size = obstacleGrid.size();
    int column_size = obstacleGrid[0].size();
    vector<vector<int>> num_paths(row_size, vector<int>(column_size));

    num_paths[0][0] = 1;
    for (int i = 1; i < row_size; i++) {
      if (obstacleGrid[i][0] == OBSTACLE) {
        num_paths[i][0] = 0;
        continue;
      }
      num_paths[i][0] = num_paths[i - 1][0];
    }

    for (int i = 1; i < column_size; i++) {
      if (obstacleGrid[0][i] == OBSTACLE) {
        num_paths[0][i] = 0;
        continue;
      }
      num_paths[0][i] = num_paths[0][i - 1];
    }

    for (int i = 1; i < row_size; i++) {
      for (int j = 1; j < column_size; j++) {
        if (obstacleGrid[i][j] == OBSTACLE) {
          obstacleGrid[i][j] = 0;
          continue;
        }
        num_paths[i][j] = num_paths[i - 1][j] + num_paths[i][j - 1];
      }
    }

    return num_paths[row_size - 1][column_size - 1];
  }

private:
  static constexpr int OBSTACLE = 1;
};
