class Solution {
public:
  struct WordToLevel {
    string word;
    int level;
  };

  int TransformToAdjacentWord(const string& begin_word, const string& end_word, set<string>& word_list) {
    map<string, bool> visited;
    queue<WordToLevel> candidate;
    candidate.push({begin_word, 1});
    visited[begin_word] = true;

    while (!candidate.empty()) {
      auto [search_word, level]= candidate.front();
      candidate.pop();

      if (search_word == end_word) {
        return level;
        break;
      }
      
      for (int i = 0; i < search_word.size(); i++) {
        string adjacent_word = search_word;
        for (char letter = 'a'; letter <= 'z'; letter++) {
          adjacent_word[i] = letter;

          if (word_list.contains(adjacent_word) && !visited[adjacent_word]) {
            candidate.push({adjacent_word, level + 1});
            visited[adjacent_word] = true;
          }
        }
      }
    }
    return 0;
  }

  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    set<string> word_list;
    for (const auto& word : wordList) {
      word_list.insert(word);
    }

    int transformation_count = TransformToAdjacentWord(beginWord, endWord, word_list);
    return transformation_count;
  }
};
