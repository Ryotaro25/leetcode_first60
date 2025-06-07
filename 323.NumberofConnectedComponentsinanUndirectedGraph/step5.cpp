class Solution {
public:
  int countComponents(int n, vector<vector<int>>& edges) {
    if (n == 0) {
      return 0;
    }

    vector<vector<int>> adjacent_nodes(n);
    for (int i = 0; i < edges.size(); i++) {
      adjacent_nodes[edges[i][0]].push_back(edges[i][1]);
      adjacent_nodes[edges[i][1]].push_back(edges[i][0]);
    }

    vector<int> visited(n, NOTVISITED);
    int num_components = 0;
    for (int i = 0; i < n; i++) {
      if (visited[i] == NOTVISITED) {
        num_components++;
        TraverseGraph(adjacent_nodes, visited, i);
      }
    }
    return num_components;
  }

private:
  static constexpr int NOTVISITED = 0;
  static constexpr int VISITED = 1;

  void TraverseGraph(const vector<vector<int>>& adjacent_nodes, vector<int>& visited, int start) {
    visited[start] = VISITED;
    for (int neighbor : adjacent_nodes[start]) {
      if (visited[neighbor] == NOTVISITED) {
        TraverseGraph(adjacent_nodes, visited, neighbor);
      }
    }
  }
};
