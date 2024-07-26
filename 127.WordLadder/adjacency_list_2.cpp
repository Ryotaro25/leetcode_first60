class Solution {
public:
  struct WordToLevel {
    string word;
    int level;
  };

  vector<unique_ptr<vector<int>>> ConvertToAdjacentList(const vector<string>& word_list) {
    int num_words = word_list.size();
    vector<unique_ptr<vector<int>>> word_to_adjacents(num_words);

    // 初期化しないとSUMMARY: UndefinedBehaviorSanitizer: undefined-behaviorが発生
    // new演算子で初期化する代わりにunique_ptrを使う
    // スコープ外にでた場合に自動削除される
    for (int i = 0; i < num_words; ++i) {
        word_to_adjacents[i] = make_unique<vector<int>>();
    }

    for (int i = 0; i < num_words; ++i) {
      for (int j = i + 1; j < num_words; ++j) {
        if (IsTransformable(word_list[i], word_list[j])) {
          word_to_adjacents[i]->push_back(j);
          word_to_adjacents[j]->push_back(i);
        }
      }
    }
    return word_to_adjacents;
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
    auto word_to_adjacents = ConvertToAdjacentList(wordList);

    queue<WordToLevel> candidates;
    candidates.push({beginWord, 1});
    set<string> visited;
    visited.insert(beginWord);

    while (!candidates.empty()) {
      const auto [current_word, level] = candidates.front();
      candidates.pop();

      if (current_word == endWord) {
          return level;
      }

      int current_index = find(wordList.begin(), wordList.end(), current_word) - wordList.begin();
      for (const auto& adjacent_index : *word_to_adjacents[current_index]) {
        string adjacent_word = wordList[adjacent_index];
        if (visited.find(adjacent_word) == visited.end()) {
          visited.insert(adjacent_word);
          candidates.push({adjacent_word, level + 1});
        }
      }
    }
    return 0;
  }
};