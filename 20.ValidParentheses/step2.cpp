#include <string>
#include <stack>
class Solution {
public:
    bool isValid(string s) {
        std::stack<char> open_brackets;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[' ) {
                open_brackets.push(s[i]);
            } else if (
              open_brackets.empty() ||
              s[i] == ')' && open_brackets.top() != '(' ||
              s[i] == '}' && open_brackets.top() != '{' ||
              s[i] == ']' && open_brackets.top() != '['
              ) {
                return false;
            } else {
                open_brackets.pop();
            }
        }
        return open_brackets.empty();
    }
};
