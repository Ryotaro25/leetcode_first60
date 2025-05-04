#include <algorithm>
#include <string>
#include <vector>

class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      if (strs.empty()) {
        return {{}};
      }
      std::map<std::string, std::vector<std::string>> anagram_to_groups;
      for (const std::string& str : strs) {
        std::string sorted = str;
        std::sort(sorted.begin(), sorted.end());
        anagram_to_groups[sorted].push_back(std::move(str));
      }

      std::vector<std::vector<std::string>> grouped_anagrams;
      for (const auto& [anagram, group] : anagram_to_groups) {
        grouped_anagrams.push_back(std::move(group));
      }
      return grouped_anagrams;
    }
  };
