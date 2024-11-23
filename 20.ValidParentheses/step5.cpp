class Solution {
public:
  bool isValid(string s) {
    map<char, char> brackets_pairs = {{'(', ')'}, {'{', '}'}, {'[', ']'} };

    stack<char> open_brackets;
    for (auto bracket : s) {
      if (bracket == '(' || bracket == '{' || bracket == '[') {
        open_brackets.emplace(bracket);
        continue;
      }
      if (open_brackets.empty() || bracket != brackets_pairs[open_brackets.top()]) {
        return false;
      }
      open_brackets.pop();
    }
    return open_brackets.empty();
  }
};
