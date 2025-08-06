class UnionFind {
  private:
    vector<int> root;
    vector<int> rank;
    vector<int> area;

  public:
    UnionFind(int size) : root(size), rank(size, 1), area(size, 1)  {
      for (int i = 0; i < size; i++) {
        root[i] = i;
      }
    }

    int find(int x) {
      while (x != root[x]) {
        x = root[x];
      }
      return x;
    }

    void unite(int x, int y) {
      int root_x = find(x);
      int root_y = find(y);
      if (rank[root_x] > rank[root_y]) {
        root[root_y] = root_x;
        area[root_x] += area[root_y];
      } else if (rank[root_x] < rank[root_y]) {
        root[root_x] = root_y;
        area[root_y] += area[root_x];
      } else {
        root[root_y] = root_x;
        rank[root_x]++;
        area[root_x] += area[root_y];
      }
    }

    int get_area(int x) {
      return area[find(x)];
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
  const int Land = 1;
  const int Water = 0;
  const int Visited = 2;

  bool is_inside(vector<vector<int>>& grid, const int& row, const int& column) {
  if ((0 <= row  && row < grid.size()) && (0 <= column && column < grid[0].size())) {
    return true;
  }

    return false;
  }

  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int size = grid.size() * grid[0].size();
    int row_size = grid.size();
    int column_size = grid[0].size();
    UnionFind island_set(size);

    vector<Direction> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    int max_area = 0;
    for (int row = 0; row < row_size; row++) {
      for (int column = 0; column < column_size; column++) {
        if (grid[row][column] == Water || grid[row][column] == Visited) {
          continue;
        }

        grid[row][column] = Visited;

        int x_index = row * column_size + column;
        for (const auto& direction : directions) {
          int neighber_row = row + direction.dx;
          int neighber_column = column + direction.dy;

          if (!is_inside(grid, neighber_row, neighber_column)) {
            continue;
          }

          if (grid[neighber_row][neighber_column] == Water || grid[neighber_row][neighber_column] == Visited) {
            continue;
          }
          int y_index = neighber_row * column_size + neighber_column;
          if (!island_set.is_connect(x_index, y_index)) {
            island_set.unite(x_index, y_index);
          }
        }

        max_area = max(max_area, island_set.get_area(x_index));
      }
    }

    return max_area;
  }
};
