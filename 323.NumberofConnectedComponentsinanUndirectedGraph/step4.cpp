class Solution {
public:
  void TraverseComponent(const int& node, vector<bool>* visited_ptr, const vector<vector<int>>& connected_edges) {
    queue<int> candidates;
    candidates.push(node);
    (*visited_ptr)[node] = true;

    while (!candidates.empty()) {
      int search_node = candidates.front();
      candidates.pop();

      for (const auto& neighbor_node : connected_edges[search_node]) {
        if ((*visited_ptr)[neighbor_node]) {
          continue;
        }
        (*visited_ptr)[neighbor_node] = true;
        candidates.push(neighbor_node);
      }
    }
  }

  int countComponents(int n, vector<vector<int>>& edges) {
    vector<vector<int>> connected_edges(n);
    for (const auto& edge : edges) {
      connected_edges[edge[0]].push_back(edge[1]);
      connected_edges[edge[1]].push_back(edge[0]);
    }

    int num_components = 0;
    vector<bool> visited(n);
    for (int i = 0; i < n; i++) {
      if (visited[i]) {
        continue;
      }

      num_components++;
      TraverseComponent(i, &visited, connected_edges);
    }

    return num_components;
  }
};
