class Solution {
  public:
    bool isSubsequence(string s, string t) {
      int source_index = 0;
      int target_index = 0;
      while (source_index < s.size() && target_index < t.size()) {
        if (s[source_index] == t[target_index]) {
          source_index++;
        }
        target_index++;
      }

      return source_index == s.size();
    }
  };
