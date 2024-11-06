class Solution {
public:
  int uniquePaths(int m, int n) {
    // m と n を比較して、n の方が小さい場合、m と n を交換
    if (m < n) {
      swap(m, n);
    }

    vector<int> num_paths(n, 1);

      // m - 1 回ループで行を更新
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        // 左と上からの経路数を足す
        num_paths[j] += num_paths[j - 1];
      }
    }

    // 最後のセルのパス数を返す
    return num_paths[n - 1];
  }
};
