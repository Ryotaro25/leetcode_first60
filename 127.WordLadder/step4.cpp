class Solution {
public:
  struct WordToLevel {
    string word;
    int level;
  };

  int CountStepsToEndWord(const string& begin_word, const string& end_word, set<string>& unique_words) {
    map<string, bool> visited;
    queue<WordToLevel> candidates;
    candidates.emplace(begin_word, 1);
    visited[begin_word] = true;

    while (!candidates.empty()) {
      const auto [search_word, level]= candidates.front();
      candidates.pop();

      if (search_word == end_word) {
        return level;
      }
      
      for (int i = 0; i < search_word.size(); i++) {
        string adjacent_word = search_word;
        for (char letter = 'a'; letter <= 'z'; letter++) {
          adjacent_word[i] = letter;

          if (unique_words.contains(adjacent_word) && !visited[adjacent_word]) {
            candidates.emplace(adjacent_word, level + 1);
            visited[adjacent_word] = true;
          }
        }
      }
    }
    return 0;
  }

  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    set<string> unique_words(wordList.begin(), wordList.end());

    int transformation_count = CountStepsToEndWord(beginWord, endWord, unique_words);
    return transformation_count;
  }
};
