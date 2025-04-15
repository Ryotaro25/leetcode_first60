template <typename K, typename V>
class my_unordered_map {
public: 
  my_unordered_map(size_t size = 128) : buckets(size) {}

  V& operator[](const K& key) {
    // 占有率0.7を超えたら倍の大きさにする
    if (static_cast<double>(count_elements()) / buckets.size() > 0.7) {
      resize(buckets.size() * 2);
    }
    // あまりを求めて場所を決定
    const size_t index = hash(key) % buckets.size();

    // keyが存在すれば値を返却
    for (auto& pair : buckets[index]) {
      if (pair.first == key) {
        return pair.second;
      }
    }

    // keyが存在しない新しいPairを作成
    buckets[index].emplace_back(key, V());
    return buckets[index].back().second;
  }

  auto begin() {
    return buckets.begin();
  }

  auto end() {
    return buckets.end();
  }

private:
  // チェイン方で管理。他にはオープンアドレス指定方などがある
  vector<list<pair<K, V>>> buckets;

  // ハッシュ法には徐算方や乗算シフト法や以下の乗算法が存在する
  // 用いる数字は一般的に素数
  // メンバー関数をconstにする
  size_t hash(const K& key) const {
    size_t hash_code = 0;
    for (char letter : key) {
      hash_code = hash_code * 31 + letter;
    } 
    return hash_code;
  }

  // 新しいサイズで再配置
  void resize(size_t new_size) {
    vector<list<pair<K, V>>> new_buckets(new_size);

    for (auto& bucket : buckets) {
      for (auto& pair : bucket) {
        size_t new_index = hash(pair.first) % new_size;
        new_buckets[new_index].emplace_back(move(pair));
      }
    }

    buckets = new_buckets;
  }

  size_t count_elements() const {
    size_t num_elements = 0;
    for (const auto& bucket : buckets) {
      num_elements += bucket.size();
    }
    return num_elements;
  }
};

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    my_unordered_map<string, vector<string>> sorted_to_group;
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
