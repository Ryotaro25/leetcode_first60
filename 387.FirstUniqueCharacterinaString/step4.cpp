template<typename T>
class Reference {
  private:
    // ポインター
    T* pointer_to_data;

  public:
    // メンバー変数を初期化
    Reference(T& variable) : pointer_to_data(&variable) {}

    operator T&() const {
      // ポインターが指しているデータを返却
      return *pointer_to_data;
    }

    T& operator=(const T& variable) {
      // ポインターが指しているデータを上書き
      *pointer_to_data = variable;
      return *pointer_to_data;
    }
};

class Solution {
public:
  int firstUniqChar(string s) {
    map<char, int> letter_to_count;
    for (Reference<char> letter : s) {
      letter_to_count[letter]++;
    }

    for (int i = 0; i < s.size(); i++) {
      if (letter_to_count[s[i]] == 1) {
        return i;
      }
    }
    return -1;
  }
};
