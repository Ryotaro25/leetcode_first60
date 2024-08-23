class Solution {
public:
  struct position {
    int row;
    int column;
  };

  int numIslands(vector<vector<char>>& grid) {
    int island_count = 0;
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};

    for (int row = 0; row < grid.size(); row++) {
      for (int column = 0; column < grid[0].size(); column++) {
        if (grid[row][column] == '1') {
          island_count++;
          grid[row][column] = '0';

          queue<position> candidate;
          candidate.push({row, column});
          while (!empty(candidate)) {
            position island = candidate.front();
            candidate.pop();

            for (int i = 0; i < 4; i++) {
              int neighber_row = island.row + dx[i];
              int neighber_column = island.column + dy[i];
              if (neighber_row < 0 || neighber_row >= grid.size() || neighber_column < 0 || neighber_column >= grid[0].size()) {
                continue;
              }
              if (grid[neighber_row][neighber_column] == '0') {
                continue;
              }
              grid[neighber_row][neighber_column] = '0';
              candidate.push({neighber_row, neighber_column});
            }
          }
        }
      }
    }

    return island_count;
  }
};
