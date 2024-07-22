class Union_find {
  private:
    vector<int> root;

  public:
    Union_find(int size) : root(size) {
      for (int i = 0; i < size; i++) {
        root[i] = i;
      }
    }

    // 自分自身が代表なのか、再起的に代表を見つける
    int find(int x) {
      if (x == root[x]) {
        return x;
      } else {
        root[x] = find(root[x]);
        return root[x];
      }
    }

    void Union(int x, int y) {
      int root_x = find(x);
      int root_y = find(y);
      if (root_x != root_y) {
        root[root_x] = root_y;
      }
    }

    bool is_connect(int x, int y) {
      return find(x) == find(y);
    }
};

class Solution {
public:
  int numIslands(vector<vector<char>>& grid) {
    int size = grid.size() * grid[0].size();
    Union_find island_set(size);

    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};

    int island_count = 0;
    for (int row = 0; row < grid.size(); row++) {
      for (int column = 0; column < grid[0].size(); column++) {
        if (grid[row][column] != '1') {
          continue;
        }

        grid[row][column] = '2';
        island_count++;
        int x_index = row * grid[0].size() + column;
        for (int i = 0; i < 4; i++) {
          int neighber_row = row + dx[i];
          int neighber_column = column + dy[i];

          if (neighber_row < 0 || neighber_row >= grid.size() || neighber_column < 0 || neighber_column >= grid[0].size()) {
                continue;
              }

          if (grid[neighber_row][neighber_column] != '1') {
            continue;
          }
          int y_index = neighber_row * grid[0].size() + neighber_column;
          if (!island_set.is_connect(x_index, y_index)) {
            island_set.Union(x_index, y_index);
            island_count--;
          }
        }

      }
    }

    return island_count;
  }
};
