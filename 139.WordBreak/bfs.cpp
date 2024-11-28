class Solution {
public:
  bool wordBreak(string s, vector<string>& wordDict) {
    string_view word = s;
    set<string_view> word_dict(wordDict.begin(), wordDict.end());
    queue<int> dividing_positions;
    dividing_positions.push(0);
    vector<bool> visited(s.size(), false);

    while (!dividing_positions.empty()) {
      int start_position = dividing_positions.front();
      dividing_positions.pop();

      if (start_position == word.size()) {
        return true;
      }

      for (int end_position = start_position + 1; end_position <= word.size(); end_position++) {
        if (visited[end_position]) {
          continue;
        }
        if (word_dict.contains(word.substr(start_position, end_position - start_position))) {
          dividing_positions.push(end_position);
          visited[end_position] = true;
        }
      }
    }

    return false;
  }
};
