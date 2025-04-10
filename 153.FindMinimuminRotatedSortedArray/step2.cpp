class Solution {
public:
  int findMin(vector<int>& nums) {
    // 1. [false, false, ..., false, true, true, ..., true] の切れ目を探す。
    // 2.[false, false, ..., false, true, true, ..., true] のうち一番初めの true を探す。
    // 今回は2.の1番初めのTrue(最小値)を探す
    // そのために[true, true, ..., true]となるように絞り込む

    // numsの範囲外に答えが来ることがないのでright = nums.size() - 1
    int left = 0;
    int right = nums.size() - 1;
    
    // 切れ目のtrueの左側だけ見ていればいいのでleft<=rightとはしない
    while (left < right) {
      int middle = (left + right) / 2;

      if (nums[middle] <= nums[right]) {
        // nums[middle]自体が回答になりうるので範囲に含める
        right = middle;
      } else {
        // nums[middle]は回答にならないので+1して範囲の外にする
        left = middle + 1;
      }
    }

    // left == rightでループが終了し答えがnums[left] or nums[right]となる
    return nums[left];
  }
};
