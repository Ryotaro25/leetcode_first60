class UnionFind {
  private:
    vector<int> parent;
    vector<int> rank;

    int Find(int x) {
      if (x == parent[x]) {
        return x;
      } else {
        parent[x] = Find(parent[x]);
        return parent[x];
      }
    }

  public:
    UnionFind(int size) : parent(size), rank(size, 1)  {
      for (int i = 0; i < size; i++) {
        parent[i] = i;
      }
    }

    bool Union(int x, int y) {
      int parent_x = Find(x);
      int parent_y = Find(y);
      if (parent_x == parent_y) {
        return false;
      }

      if (rank[parent_x] > rank[parent_y]) {
        parent[parent_y] = parent_x;
      } else if (rank[parent_x] < rank[parent_y]) {
        parent[parent_x] = parent_y;
      } else {
        parent[parent_y] = parent_x;
        rank[parent_x]++;
      }
      return true;
    }
};

class Solution {
public:
  int countComponents(int n, vector<vector<int>>& edges) {
    UnionFind node_tree = UnionFind(n);
   
    int total_component = n;
    for (auto edge : edges) {
      if (node_tree.Union(edge[0], edge[1])) {
        total_component--;
      }
    }

    return total_component;
  }
};
