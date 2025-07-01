class Solution {
public:
  int numWays(int num_posts, int num_colors) {
    if (num_posts == 1) {
      return num_colors;
    }
    if (num_posts == 2) {
      return num_colors * num_colors;
    }

    int num_ways = 0;
    int previous_num_ways = num_colors;
    int second_previous_num_ways = num_colors * num_colors;
    
    for (int i = 2; i < num_posts; i++) {
      num_ways = (num_colors - 1) * (previous_num_ways + second_previous_num_ways);
      previous_num_ways = second_previous_num_ways;
      second_previous_num_ways = num_ways;
    }

    return num_ways;
  }
};
