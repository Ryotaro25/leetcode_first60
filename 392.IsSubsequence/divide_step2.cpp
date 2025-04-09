class Solution {
  public:
    bool isSubsequence(string s, string t) {
      // 整数リテラルは非constなint&にはバインドできないので変数を用意する
      int source_index = 0;
      int target_index = 0;
      return CheckIsSubsequence(source_index, s, target_index, t);
    }

  private:
    bool CheckIsSubsequence(int source_index, string& source,
                            int target_index, string& target) {
      if (source_index == source.size()) {
        return true;
      }
      if (target_index == target.size()) {
        return false;
      }
      if (source[source_index] == target[target_index]) {
        source_index++;
      }
      target_index++;
      return CheckIsSubsequence(source_index, source, target_index, target);
    }
  };
