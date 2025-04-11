class Solution {
  public:
    vector<string> generateParenthesis(int n) {
      vector<string> parentheses_combinations;
      GenerateParenthesisCombinations(n, 0, 0, "", parentheses_combinations);
      return parentheses_combinations;
    }

  private:
    void GenerateParenthesisCombinations(int num_parenthesis, int num_open, int num_close,
                                         string formed_parentheses,
                                         vector<string>& parentheses_combinations) {
      if (num_open == num_close && num_open + num_close == num_parenthesis * 2) {
        parentheses_combinations.emplace_back(formed_parentheses);
        return;
      }
      if (num_open < num_parenthesis) {
        GenerateParenthesisCombinations(num_parenthesis, num_open + 1, num_close,
                                        formed_parentheses + '(',
                                        parentheses_combinations);
      }
      if (num_close < num_open) {
        GenerateParenthesisCombinations(num_parenthesis, num_open, num_close + 1,
                                        formed_parentheses + ')',
                                        parentheses_combinations);
      }
    }
  };
