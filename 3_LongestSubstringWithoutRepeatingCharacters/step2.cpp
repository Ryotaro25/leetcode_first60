class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
      int longest_length = 0;

      map<char, int> letters_to_index;
      int left = 0;
      for (int right = 0; right < s.size(); right++) {
        if (letters_to_index[s[right]] > 0) {
          // left = letters_to_index[s[right]]だと現地点より前に
          // 重複があった場合そこの位置をleftにしてしまう
          left = max(letters_to_index[s[right]], left);
        }
        longest_length = max(longest_length, right - left + 1);
        // 重複が発生した際に、その次の位置をleftにするためここで＋1して記録
        letters_to_index[s[right]] = right + 1;
      }

      return longest_length;
    }
  };
