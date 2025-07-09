class Solution {
public:
  int UNDEFINED = -1;

  int numWays(int num_posts, int num_colors) {
    // デフォルトは0で初期化なので今回あり得ない-1で初期化
    vector<int> memoization(num_posts + 1, UNDEFINED);
    return CountNumWays(num_posts, num_colors, memoization);
  }

private:
  int CountNumWays(int num_posts, const int num_colors, vector<int>& memoization) {
    if (memoization[num_posts] != UNDEFINED) {
      return memoization[num_posts];
    }
    if (num_posts == 0) {
      return 0;
    }
    if (num_posts == 1) {
      return num_colors;
    }
    if (num_posts == 2) {
      return num_colors * num_colors;
    }
    int same_pattern_ways = CountNumWays(num_posts - 2, num_colors, memoization) * (num_colors - 1);
    int different_pattern_ways = CountNumWays(num_posts - 1, num_colors, memoization) * (num_colors - 1);

    memoization[num_posts] = same_pattern_ways + different_pattern_ways;
    return memoization[num_posts];
  }
};
