class Solution {
public:
  int uniquePaths(int m, int n) {
    // (m - 1) + (n - 1) = m + n - 2
    return combination(m + n - 2, min(m - 1, n - 1));
  }

private:
  int combination(int n, int r) {
    long long result = 1;
    
    for (int i = 1; i <= r; i++) {
      result *=  (n - i + 1) / i;
    }

    return static_cast<int>(result);
  }
};
