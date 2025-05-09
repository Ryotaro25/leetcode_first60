// 開き+閉じ*(0~ここまでの開きの数までのどれか)までを一つの仕事とみるという仕事の分担方法
class Solution {
  public:
    vector<string> generateParenthesis(int n) {
      string paren = "";
      vector<string> all_parens = {};
      GenerateParens(n, 0, paren, all_parens);
      return all_parens;
    }

  private:
    void GenerateParens(int num_parens, int num_open, string& paren, vector<string>& all_parens) {
      if (paren.size() == num_parens * 2) {
        all_parens.push_back(paren);
        return;
      }

      if (num_open < num_parens) {
        paren.push_back('(');
        GenerateParens(num_parens, num_open + 1, paren, all_parens);
        paren.pop_back();
      }

      int num_close = count(paren.begin(), paren.end(), ')');
      if (num_close < num_open) {
        paren.push_back(')');
        GenerateParens(num_parens, num_open, paren, all_parens);
        paren.pop_back();
      }
    }
  };
