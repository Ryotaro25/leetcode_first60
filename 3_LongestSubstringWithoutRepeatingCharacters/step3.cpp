class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
      int longest_length = 0;
      map<char, int> letters_to_index;
      int left = 0;
      for (int right = 0; right < s.size(); right++) {
        if (letters_to_index[s[right]] > 0) {
          left = max(letters_to_index[s[right]], left);
        }
        longest_length = max(longest_length, right - left + 1);
        letters_to_index[s[right]] = right + 1;
      }

      return longest_length;
    }
  };
