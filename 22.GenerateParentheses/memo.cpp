class Solution {
  public:
    vector<string> generateParenthesis(int n) {
      map<int, vector<string>> num_to_parenthesis;
      return GenerateParenthesis(n, num_to_parenthesis);
    }
  
  private:
    vector<string> GenerateParenthesis(int num_parenthesis, map<int, vector<string>>& num_to_parenthesis) {
      // 既に構築済みであればメモしたものを返却
      if (num_to_parenthesis.count(num_parenthesis)) {
        return num_to_parenthesis[num_parenthesis];
      }
      if (num_parenthesis == 0) {
        vector<string> base = {""};
        return base;
      }

      vector<string> parenthesis;
      // 最初の()に含める括弧の数
      for (int inside_count = 0; inside_count < num_parenthesis; inside_count++) {
        for (const string& open : GenerateParenthesis(inside_count, num_to_parenthesis)) {
          for (const string& close : GenerateParenthesis(num_parenthesis - 1 - inside_count, num_to_parenthesis)) {
            parenthesis.push_back("(" + open + ")" + close);
          }
        }
      }
      return num_to_parenthesis[num_parenthesis] = parenthesis;
    }
  };
