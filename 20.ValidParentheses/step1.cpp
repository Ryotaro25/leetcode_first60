#include <string>
#include <stack>
class Solution {
public:
    bool isValid(string s) {
        std::stack<char> brackets;
        if (s.length() < 2) {
          return false;
        }

        for (int i = 0; i < s.length(); i++) {
            if (brackets.empty() && (s[i] == ')' || s[i] == '}' || s[i] == ']')) {
                return false;
            } else if (s[i] == '(' || s[i] == '{' || s[i] == '[' ) {
                brackets.push(s[i]);
            } else if (s[i] == ')' && brackets.top() == '(') {
                brackets.pop();
            } else if (s[i] == '}' && brackets.top() == '{') {
                brackets.pop();
            } else if (s[i] == ']' && brackets.top() == '[') {
                brackets.pop();
            } else {
              return false;
            }
        }

        if (brackets.size() != 0) {
          return false;
        }
        return true;
    }
};
