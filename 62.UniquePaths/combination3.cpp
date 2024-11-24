class Solution {
public:
  int uniquePaths(int m, int n) {
    // (m - 1) + (n - 1) = m + n - 2
    return combination(m + n - 2, min(m - 1, n - 1));
  }

private:
  int64_t combination(int64_t n, int64_t r) {
    int64_t result = 1;
    
    for (int64_t i = 1; i <= r; i++) {
      result *=  (n - i + 1);
      result /= i;
    }

    return result;
  }
};
