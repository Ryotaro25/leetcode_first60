class Solution {
  public:
    bool isSubsequence(string s, string t) {
      map<char, vector<int>> letter_to_indices;
      for (int i = 0; i < t.size(); i++) {
        letter_to_indices[t[i]].push_back(i);
      }

      // 探索前なのでありえない値で初期化
      int current_index = -1;
      for (char letter : s) {
        if (!letter_to_indices.contains(letter)) {
          return false;
        }

        bool is_matched = false;
        for (int matched_index : letter_to_indices[letter]) {
          if (current_index > matched_index) {
            continue;
          }
          current_index = matched_index;
          is_matched = true;
          break;
        }
        // 順番を考慮してマッチしない場合
        if (!is_matched) {
          return false;
        }
      }
      return true;
    }
  };
