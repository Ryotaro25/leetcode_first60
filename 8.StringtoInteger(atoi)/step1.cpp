class Solution {
  public:
    int myAtoi(string s) {
      int index = 0;
      while (index < s.size() && s[index] == ' ') {
        index++;
      }

      bool is_negative = false;
      if (index < s.size() && s[index] == '-') {
        is_negative = true;
        index++;
      } else if (index < s.size() && s[index] == '+') {
        index++;
      }

      while (index < s.size() && s[index] == '0') {
        index++;
      }

      vector<char> numeric_strs;
      while (index < s.size() && IsNumber(s[index])) {
        numeric_strs.push_back(s[index]);
        index++;
      }

      int converted = 0;
      for (int i = 0; i < numeric_strs.size(); i++) {
        int digit = numeric_strs[i] - '0';

        if (converted > numeric_limits<int>::max() / 10 ||
           (converted == numeric_limits<int>::max() / 10 && digit > 7)) {
          if (is_negative) {
            return numeric_limits<int>::min();
          } else {
            return numeric_limits<int>::max();
          }
        }
      
        converted = converted * 10 + digit;
      }
      

      if (is_negative) {
        return -converted;
      }
      return converted;
    }
  
  private:
    bool IsNumber(char letter) {
      set<char> letter_numbers = {'0', '1', '2', '3', '4',
                                   '5','6', '7', '8', '9'};
      if (letter_numbers.contains(letter)) {
        return true;
      } else {
        return false;
      }
    }
  };
