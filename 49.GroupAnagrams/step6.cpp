class Solution {
private:
  vector<int> count_alphabet(string s) {
    vector<int> counts(26, 0);
    for (char c : s) {
      counts[c - 'a']++;
    }

    return counts;
  };

public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> sorted_to_group;

    for (auto str : strs) {
      vector<int> counts = count_alphabet(str);
      string key;

      // chatGPTにて確認
      // https://ameblo.jp/nana-2007-july/entry-10098557843.html
      // https://cplusplus.com/reference/sstream/ostringstream/
      ostringstream oss;
      for (int count : counts) {
        oss << '#' << count;
      }
      key = oss.str();
      sorted_to_group[key].push_back(str);
    }

    vector<vector<string>> group_anagrams;
    for (auto& [key, word_group] : sorted_to_group) {
      group_anagrams.push_back(move(word_group));
    }

    return group_anagrams;
  }
};
