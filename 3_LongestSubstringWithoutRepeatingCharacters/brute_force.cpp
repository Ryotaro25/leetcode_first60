class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
      int longest_length = 0;

      for (int start = 0; start < s.size(); start++) {
        set<char> unique_letters;
        for (int end = start; end < s.size(); end++) {
          if (unique_letters.contains(s[end])) {
            break;
          }
          unique_letters.insert(s[end]);
          longest_length = max(longest_length, end - start + 1);
        }
      }

      return longest_length;
    }
  };
