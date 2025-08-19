class Solution {
  public:
    int firstUniqChar(string s) {
      map<char, int> first_index;
      set<char> duplicated;
      map<int, char> first_index_to_char;

      for (int i = 0; i < s.size(); ++i) {
        char letter = s[i];

        if (duplicated.contains(letter)) {
          continue;
        }

        if (first_index.contains(letter)) {
          int index = first_index[letter];
          first_index.erase(letter);
          first_index_to_char.erase(index);
          duplicated.insert(letter);
        } else {
        first_index[letter] = i;
        first_index_to_char[i] = letter;
        }
      }

      if (!first_index_to_char.empty()) {
        return first_index_to_char.begin()->first;
      }
      return -1;
  }
};
