class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
      int longest_length = 0;

      set<char> unique_letters;
      int start = 0;
      for (int end = 0; end < s.size(); end++) {
        while (unique_letters.contains(s[end])) {
          unique_letters.erase(s[start]);
          start++;
        }

        unique_letters.insert(s[end]);
        longest_length = max(longest_length, end - start + 1);
      }

      return longest_length;
    }
  };
