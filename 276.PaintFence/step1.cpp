class Solution {
public:
  int numWays(int num_posts, int num_colors) {
    if (num_posts == 0) {
      return 0;
    }
    if (num_posts == 1) {
      return num_colors;
    }
    if (num_posts == 2) {
      return num_colors * num_colors;
    }

    vector<int> past_two_colors(2);
    past_two_colors[0] = num_colors;
    past_two_colors[1] = num_colors * num_colors;

    int colors = 0;
    for (int i = 2; i < num_posts; i++) {
      colors = (num_colors - 1) * (past_two_colors[0] + past_two_colors[1]);
      past_two_colors[0] = past_two_colors[1];
      past_two_colors[1] = colors;
    }

    return colors;
  }
};
