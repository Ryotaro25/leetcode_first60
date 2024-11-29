class Solution {
public:
  struct WordAndLevel {
    int index;
    int level;
  };
  
  // 参照で受け取ってadjacent_listを書き換える
  void ConvertToAdjacentList(const vector<string>& word_list, vector<vector<int>>& adjacent_list) {
    int num_words = word_list.size();

    for (int i = 0; i < num_words; ++i) {
      for (int j = i + 1; j < num_words; ++j) {
        if (IsTransformable(word_list[i], word_list[j])) {
          adjacent_list[i].push_back(j);
          adjacent_list[j].push_back(i);
        }
      }
    }
  }

  bool IsTransformable(const string_view first_word, const string_view second_word) {
    int num_difference = 0;
    for (int i = 0; i < first_word.size(); ++i) {
      if (first_word[i] != second_word[i]) {
        num_difference++;
        if (num_difference > 1) {
          return false;
        }
      }
    }
    return true;
  }

  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    wordList.push_back(beginWord);
    vector<vector<int>> adjacent_list(wordList.size());
    ConvertToAdjacentList(wordList, adjacent_list);

    int begin_word_index = wordList.size() - 1;
    queue<WordAndLevel> candidates;
    candidates.push({begin_word_index, 1});

    vector<bool> visited(wordList.size());
    visited[begin_word_index] = true;

    while (!candidates.empty()) {
      const auto [current_index, level] = candidates.front();
      candidates.pop();

      if (wordList[current_index] == endWord) {
        return level;
      }

      for (const auto& adjacent_index : adjacent_list[current_index]) {
        if (!visited[adjacent_index]) {
          visited[adjacent_index] = true;
          candidates.push({adjacent_index, level + 1});
        }
      }
    }
    return 0;
  }
};
