class Solution {
  public:
    vector<string> generateParenthesis(int n) {
      vector<string> all_parens;
      string paren;
      GenerateParen(n, 0, 0, paren, all_parens);
      return all_parens;
    }

  private:
    void GenerateParen(int num_parens, int num_open, int num_close,
                                         string& paren,
                                         vector<string>& all_parens) {
      if (num_open + num_close == num_parens * 2) {
        all_parens.push_back(paren);
        return;
      }
      if (num_open < num_parens) {
        paren.push_back('(');
        GenerateParen(num_parens, num_open + 1, num_close,
                                        paren,
                                        all_parens);
        paren.pop_back();
      }
      if (num_close < num_open) {
        paren.push_back(')');
        GenerateParen(num_parens, num_open, num_close + 1,
                                        paren,
                                        all_parens);
        paren.pop_back();
      }
    }
  };
