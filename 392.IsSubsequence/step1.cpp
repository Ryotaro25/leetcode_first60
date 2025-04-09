class Solution {
  public:
    bool isSubsequence(string s, string t) {
      queue<char> letters_to_subsequence;
      for (auto& letter : s) {
        letters_to_subsequence.push(letter);
      }

      for (auto& letter : t) {
        if (letter == letters_to_subsequence.front()) {
          letters_to_subsequence.pop();
        }
      }

      return letters_to_subsequence.empty();
    }
  };
