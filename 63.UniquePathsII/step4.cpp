class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int row_size = obstacleGrid.size();
    int column_size = obstacleGrid[0].size();
    if (obstacleGrid[0][0] == OBSTACLE || obstacleGrid[row_size - 1][column_size - 1] == OBSTACLE) {
      return 0;
    }
 
    vector<vector<int>> num_paths(row_size, vector<int>(column_size));
    num_paths[0][0] = 1; 
    for (int row = 0; row < row_size; row++) {
      for (int col = 0; col < column_size; col++) {
        if (obstacleGrid[row][col] == OBSTACLE) {
          num_paths[row][col] = 0;
          continue;
        }
        if (col > 0) {
          num_paths[row][col] += num_paths[row][col - 1];  
        }
        if (row > 0) {
          num_paths[row][col] += num_paths[row - 1][col];
        }
      }
    }
    return num_paths[row_size - 1][column_size - 1];
  }

private:
  static constexpr int OBSTACLE = 1;
};
