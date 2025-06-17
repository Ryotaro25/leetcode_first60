#include <chrono>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    string convert(string s, int numRows) {
      if (numRows == 1) {
        return s;
      }
      vector<string> string_per_row(numRows);

      bool is_downforward = true;
      int row = 0;
      for (char letter : s) {
        string_per_row[row] += letter;
        if (is_downforward) {
          row++;
        } else {
          row--;
        }

        if (row == numRows - 1) {
          is_downforward = false;
        } else if (row == 0) {
          is_downforward = true;
        }
      }

      string converted = "";
      converted.reserve(s.size());
      for (const auto& str : string_per_row) {
        converted += str;
        // std::cout << converted.size() << "/" << converted.capacity() << std::endl;
      }
      return converted;
    }
  };

  int main() {
    Solution sol;
    string input = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijk";
    int numRows = 3;

    // 計測開始
    auto start = std::chrono::high_resolution_clock::now();
    string result = sol.convert(input, numRows);
    //std::cout << "変換後の文字列: " << result << std::endl;

    // 計測終了
    auto end = std::chrono::high_resolution_clock::now();

    // 経過時間（ミリ秒）
    //std::chrono::duration<double> elapsed = end - start;
    // std::cout << "処理時間: " << elapsed.count() << " 秒" << std::endl;
    // 経過時間（マイクロ秒）
    auto elapsed_us = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    std::cout << "処理時間: " << elapsed_us << " マイクロ秒" << std::endl;

    return 0;
  }