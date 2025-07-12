class Solution {
public:
  struct WordToLevel {
    string word;
    int level;
  };

  // 隣接リストを構築
  map<string, vector<string>> ConvertToAdjacentList(const vector<string>& word_list) {
    map<string, vector<string>> word_to_adjacents;
    for (int i = 0; i < word_list.size(); ++i) {
      for (int j = i + 1; j < word_list.size(); ++j) {
        if (IsTransformable(word_list[i], word_list[j])) {
          word_to_adjacents[word_list[i]].push_back(word_list[j]);
          word_to_adjacents[word_list[j]].push_back(word_list[i]);
        }
      }
    }
    return word_to_adjacents;
  }

  // 1文字のみ変換可能か確認
  bool IsTransformable(const string& first_word, const string& second_word) {
    int num_difference = 0;
    for (int i = 0; i < first_word.size(); i++) {
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
    map<string, vector<string>> word_to_adjacents = ConvertToAdjacentList(wordList);

    // BFSの初期化
    queue<WordToLevel> candidates;
    candidates.push({beginWord, 1});
    set<string> visited;
    visited.insert(beginWord);

    while (!candidates.empty()) {
      auto [current_word, level] = candidates.front();
      candidates.pop();

      if (current_word == endWord) {
        return level;
      }

      // 隣接ノードを探索
      for (const auto& adjacent_word : word_to_adjacents[current_word]) {
        if (!visited.contains(adjacent_word)) {
          visited.insert(adjacent_word);
          candidates.push({adjacent_word, level + 1});
        }
      }
    }
    return 0;
  }
};
