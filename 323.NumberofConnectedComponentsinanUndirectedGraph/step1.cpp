class Solution {
public:
  vector<bool> traverse_component(int node, vector<bool> visited, vector<vector<int>> connected_edges) {
    queue<int> candidates;
    candidates.push(node);
    visited[node] = true;
    
    while (!candidates.empty()) {
      int search_node = candidates.front();
      candidates.pop();

      for (const auto& neighbour_node : connected_edges[search_node]) {
        if (!visited[neighbour_node]) {
          visited[neighbour_node] = true;
          candidates.push(neighbour_node);
        }
      }
    }
    return visited;
  }

  int countComponents(int n, vector<vector<int>>& edges) {
    vector<bool> visited(n, false);
    
    vector<vector<int>> connected_edges(n);
    for (const auto& edge : edges) {
      connected_edges[edge[0]].push_back(edge[1]);
      connected_edges[edge[1]].push_back(edge[0]);
    }

    int total_component = 0;
    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        total_component++;
        visited = traverse_component(i, visited, connected_edges);
      }
    }
    return total_component;
  }
};
