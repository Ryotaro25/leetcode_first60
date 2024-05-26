#include <string>
#include <stack>
#include <map>
class Solution {
public:
    bool isValid(string s) {
        std::stack<char> open_brackets;
        std::map<char, char> brackets_pairs;
        brackets_pairs['('] = ')';
        brackets_pairs['['] = ']';
        brackets_pairs['{'] = '}';

        for (int i = 0; i < s.length(); i++) {
            if (brackets_pairs.contains(s[i])) {
                open_brackets.push(s[i]);
                continue;
            } else if (open_brackets.empty() ||
                       brackets_pairs[open_brackets.top()] != s[i]) {
                return false;
            }
            open_brackets.pop();
        }
        return open_brackets.empty();
    }
};
