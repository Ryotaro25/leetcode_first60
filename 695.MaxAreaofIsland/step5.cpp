class UnionFind {
  private:
    vector<int> parent;
    vector<int> rank;
    vector<int> area;

    int Find(int x) {
      while (x != parent[x]) {
        x = parent[x];
      }
      return x;
    }

  public:
    UnionFind(int size) : parent(size), rank(size, 1), area(size, 1)  {
      for (int i = 0; i < size; i++) {
        parent[i] = i;
      }
    }

    void Union(int x, int y) {
      int root_x = Find(x);
      int root_y = Find(y);
      if (root_x == root_y) {
        return;
      }
      if (rank[root_x] > rank[root_y]) {
        parent[root_y] = root_x;
        area[root_x] += area[root_y];
      } else if (rank[root_x] < rank[root_y]) {
        parent[root_x] = root_y;
        area[root_y] += area[root_x];
      } else {
        parent[root_y] = root_x;
        rank[root_x]++;
        area[root_x] += area[root_y];
      }
    }

    int GetArea(int x) {
      return area[Find(x)];
    }

    bool AreConnected(int x, int y) {
      return Find(x) == Find(y);
    }
};

struct Direction {
  int dy;
  int dx;
};

class Solution {
public:
  static constexpr int kLand = 1;
  static constexpr int kWater = 0;
  static constexpr int kVisited = 2;

  bool IsInside(vector<vector<int>>& grid, const int row, const int& column) {
    return 0 <= row && row < grid.size() && 0 <= column && column < grid[0].size();
  }

  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int size = grid.size() * grid[0].size();
    int num_rows = grid.size();
    int num_colums = grid[0].size();
    UnionFind island_set(size);

    vector<Direction> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    int max_area = 0;
    for (int row = 0; row < num_rows; row++) {
      for (int column = 0; column < num_colums; column++) {
        if (grid[row][column] == kWater || grid[row][column] == kVisited) {
          continue;
        }

        grid[row][column] = kVisited;

        int cell_index = row * num_colums + column;
        for (const auto& direction : directions) {
          int neighber_row = row + direction.dy;
          int neighber_column = column + direction.dx;

          if (!IsInside(grid, neighber_row, neighber_column)) {
            continue;
          }

          if (grid[neighber_row][neighber_column] == kWater || grid[neighber_row][neighber_column] == kVisited) {
            continue;
          }
          int neighbor_cell_index = neighber_row * num_colums + neighber_column;
          island_set.Union(cell_index, neighbor_cell_index);
        }

        max_area = max(max_area, island_set.GetArea(cell_index));
      }
    }

    return max_area;
  }
};
