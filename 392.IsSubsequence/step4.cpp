// map.cppからレビューを反映したもの
class Solution {
  public:
    bool isSubsequence(string s, string t) {
      // ASCII文字列として格納する
      vector<int>letters_to_indices[128];
      for (int i = 0; i < t.size(); i++) {
        letters_to_indices[static_cast<int>(t[i])].push_back(i);
      }

      // 探索前なのでありえない値で初期化
      int current_index = -1;
      for (char letter : s) {
        int letter_index = static_cast<int>(letter);
        if (letters_to_indices[letter_index].empty()) {
          return false;
        }

        auto it = lower_bound(letters_to_indices[letter_index].begin(),
                              letters_to_indices[letter_index].end(),
                              current_index + 1);
        if (it == letters_to_indices[letter_index].end()) {
          return false;
        }

        // 順番を考慮してマッチしない場合
        current_index = *it;
      }
      return true;
    }
  };
