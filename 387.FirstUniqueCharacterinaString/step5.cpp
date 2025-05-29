class Solution {
public:
  int firstUniqChar(string s) {
    if (s.empty()) {
      return -1;
    }
    map<char, int> letter_to_cnt;
    for (auto letter : s) {
      letter_to_cnt[letter]++;
    }
    for (int i = 0; i < s.size(); i++) {
      if (letter_to_cnt[s[i]] == 1) {
        return i;
      }
    }
    return -1;
  }
};
