class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
      int longest_length = 0;
      // ASCII文字用の配列を-1で初期化
      vector<int> letters_to_index(128, -1);
      int left = 0;

      for (int right = 0; right < s.size(); right++) {
        if (letters_to_index[s[right]] != -1) {
          left = max(letters_to_index[s[right]] + 1, left);
        }
        longest_length = max(longest_length, right - left + 1);
        letters_to_index[s[right]] = right;
      }

      return longest_length;
    }
  };
