class Solution {
  public:
    bool isSubsequence(string subsequence, string text) {
      int subsequence_index = 0;
      for (int i = 0; i < text.size(); i++) {
        if (subsequence_index == subsequence.size()) {
          break;
        }
        if (subsequence[subsequence_index] == text[i]) {
          subsequence_index++;
        }
      }

      return subsequence_index == subsequence.size();
    }
  };
