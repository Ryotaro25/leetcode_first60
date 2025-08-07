class Solution {
public:
  int hammingWeight(int n) {
    return GenerichammingWeight(n);
  }

private:
  template <typename T>
  std::enable_if_t<std::is_integral_v<T>, int> GenerichammingWeight(T n) {
    int num_bits = 0;
    T mask = 1;
    constexpr int num_digits = std::numeric_limits<T>::digits;

    for (int i = 0; i < num_digits; ++i) {
      if ((n & mask) != 0) {
        num_bits++;
      }
      mask <<= 1;
    }

    return num_bits;
  }
};
