class Solution {
public:
  int countComponents(int n, vector<vector<int>>& edges) {
    if (n == 0) {
      return 0;
    }

    vector<int> visited(n, 0);
    vector<vector<int>> adjacent_nodes(n);
    for (int i = 0; i < edges.size(); i++) {
      adjacent_nodes[edges[i][0]].push_back(edges[i][1]);
      adjacent_nodes[edges[i][1]].push_back(edges[i][0]);
    }

    int num_components = 0;
    for (int i = 0; i < n; i++) {
      if (visited[i] == 0) {
        num_components++;
        TraverseGraph(adjacent_nodes, visited, i);
      }
    }
    return num_components;
  }

private:
  void TraverseGraph(const vector<vector<int>>& adjacent_nodes, vector<int>& visited, int start_pos) {
    visited[start_pos] = 1;
    for (auto neighbor : adjacent_nodes[start_pos]) {
      if (visited[neighbor] == 0) {
        TraverseGraph(adjacent_nodes, visited, neighbor);
      }
    }
  }
};
