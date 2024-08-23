class UnionFind {
  private:
    vector<int> root;
    vector<int> rank;

  public:
    UnionFind(int size) : root(size), rank(size, 1) {
      for (int i = 0; i < size; i++) {
        root[i] = i;
      }
    }

    // 自分自身が代表なのか、再帰的に代表を見つける
    int find(int x) {
      while (x != root[x]) {
        x = root[x];
      }
      return x;
    }

    void union_tree(int x, int y) {
      int root_x = find(x);
      int root_y = find(y);
      if (rank[root_x] > rank[root_y]) {
        root[root_y] = root_x;
      } else if (rank[root_x] < rank[root_y]) {
        root[root_x] = root_y;
      } else {
        root[root_y] = root_x;
        rank[root_x]++;
      }
    }

    bool is_connect(int x, int y) {
      return find(x) == find(y);
    }
};

struct Direction {
  int dx;
  int dy;
};

class Solution {
public:
  const char Land = '1';
  const char Water = '0';
  const char Visited = '2';

  bool is_inside(vector<vector<char>>& grid, const int& row, const int& column) {
  if ((0 <= row  && row < grid.size()) && (0 <= column && column < grid[0].size())) {
    return true;
  }

    return false;
  }

  int numIslands(vector<vector<char>>& grid) {
    int size = grid.size() * grid[0].size();
    UnionFind island_set(size);

    vector<Direction> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    int island_count = 0;
    for (int row = 0; row < grid.size(); row++) {
      for (int column = 0; column < grid[0].size(); column++) {
        if (grid[row][column] == Water || grid[row][column] == Visited) {
          continue;
        }

        grid[row][column] = Visited;
        island_count++;
        int x_index = row * grid[0].size() + column;
        for (const auto& direction : directions) {
          int neighber_row = row + direction.dx;
          int neighber_column = column + direction.dy;

          if (!is_inside(grid, neighber_row, neighber_column)) {
                continue;
              }

          if (grid[neighber_row][neighber_column] == Water ||grid[neighber_row][neighber_column] == Visited) {
            continue;
          }
          int y_index = neighber_row * grid[0].size() + neighber_column;
          if (!island_set.is_connect(x_index, y_index)) {
            island_set.union_tree(x_index, y_index);
            island_count--;
          }
        }
      }
    }

    return island_count;
  }
};
