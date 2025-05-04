class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      if (strs.empty()) {
        return {{}};
      }
      map<string, vector<string>> anagram_to_groups;
      for (const string& str : strs) {
        string sorted = str;
        sort(sorted.begin(), sorted.end());
        anagram_to_groups[sorted].push_back(move(str));
      }

      vector<vector<string>> grouped_anagrams;
      for (const auto& [anagram, group] : anagram_to_groups) {
        grouped_anagrams.push_back(move(group));
      }
      return grouped_anagrams;
    }
  };
