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
        anagram_to_groups[sorted].emplace_back(str);
      }

      vector<vector<string>> grouped_anagrams;
      for (const auto& [key, group] : anagram_to_groups) {
        grouped_anagrams.emplace_back(group);
      }
      return grouped_anagrams;
    }
  };
