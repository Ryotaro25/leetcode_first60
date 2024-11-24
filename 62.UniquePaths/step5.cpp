class Solution {
public:
  int uniquePaths(int m, int n) {
    vector<vector<int>> num_paths(m, vector<int>(n));
    // 到達まで1パターンの部分を初期化
    for (int i = 0; i < m; i++) {
      num_paths[i][0] = 1;
    }
    for (int j = 0; j < n; j++) {
      num_paths[0][j] = 1;
    }

    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        num_paths[i][j] = num_paths[i - 1][j] + num_paths[i][j - 1];
      }
    }

    return num_paths[m - 1][n - 1];
  }
};
