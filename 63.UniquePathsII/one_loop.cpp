class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int row_size = obstacleGrid.size();
    int column_size = obstacleGrid[0].size();

    vector<int> num_paths(column_size);
    num_paths[0] = 1;

    for (int row = 0; row < row_size; row++) {
      for (int col = 0; col < column_size; col++) {
        if (obstacleGrid[row][col] == OBSTACLE) {
          num_paths[col] = 0;
          continue;
        }
        if (col > 0) {
          num_paths[col] += num_paths[col - 1];
        }
      }
    }

    return num_paths[column_size - 1];
  }

private:
  static constexpr int OBSTACLE = 1;
};
