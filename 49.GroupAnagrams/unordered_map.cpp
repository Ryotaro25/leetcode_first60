class my_unordered_map {
public: 
    my_unordered_map(size_t size = 128) : buckets(size) {}

    vector<string>& operator[](const string& key) {
        // あまりを求めて場所を決定
        size_t index = hash(key) % buckets.size();

        // keyが存在すれば値を返却
        for (auto& pair : buckets[index]) {
            if (pair.first == key) {
                return pair.second;
            }
        }

        // keyが存在しない新しいPairを作成
        buckets[index].emplace_back(key, vector<string>());
        return buckets[index].back().second;
    }

    auto begin() {
        return buckets.begin();
    }

    auto end() {
        return buckets.end();
    }

private:
    // ハッシュ法には徐算方や乗算シフト法や以下の乗算法が存在する
    // 用いる数字は一般的に素数
    size_t hash(const string& key) const {
        size_t hash_code = 0;
        for (char letter : key) {
            hash_code = hash_code * 31 + letter;
        } 
        return hash_code;
    }

    // チェイン方で管理。他にはオープンアドレス指定方などがある
    vector<list<pair<string, vector<string>>>> buckets;

};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        my_unordered_map sorted_to_group;
        for (auto& str : strs) {
            string anagram = str;
            sort(anagram.begin(), anagram.end());
            sorted_to_group[anagram].push_back(move(str));
        }

        // buchetの定義にlistを使ったためauto& [key, word_group] : sorted_to_groupだとエラー
        // 内部的には_List_baseから作られおりこれがメンバーへの直接アクセスを禁止している
        vector<vector<string>> group_anagrams;
        for (auto it = sorted_to_group.begin(); it != sorted_to_group.end(); ++it) {
            for (auto& pair : *it) {
                group_anagrams.push_back(std::move(pair.second));
            }
        }

        return group_anagrams;
    }
};
