class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> sorted_and_string;
        for (int i = 0; i < strs.size(); i++) {
            string sorted_word = strs[i];
            sort(sorted_word.begin(), sorted_word.end());
            sorted_and_string[sorted_word].push_back(strs[i]);
        }

        vector<vector<string>> anagrams;
        for (auto [key, value] : sorted_and_string) {
            anagrams.push_back(value);
        }

        return anagrams;
    }
};
