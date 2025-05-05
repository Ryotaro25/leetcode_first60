class Solution {
public:
  int search(vector<int>& nums, int target) {
 
    // numsの内targetを探すので外側を参照することはない
    int left = 0;
    int right = nums.size() - 1;

    // [false, false, ..., false, true, true, ..., true] の切れ目を探すとして
    // trueの区間は昇順に並んでいる
    // trueのインデックスが欲しいだけだが、配列の長さが0の場合を考慮
    while (left <= right) {
      int middle = (left + right) / 2;

      if (nums[middle] == target) {
        return middle;
      }

      // ここがtrue=middleからrightまでは昇順に並んでいる
      if (nums[middle] < nums[right]) {
        // middleを含め左側にはtargetは存在しない
        if (nums[middle] < target && target <= nums[right]) {
          left = middle + 1;
        } else {
          right = middle - 1;
        }
      } else {
        // 左端からmiddleまでは並んでいる
        // 並んでいる左側のうちどこかにいる
        if (nums[left] <= target && target < nums[middle]) {
          right = middle - 1;
        } else {
          left = middle + 1;
        }
      }
    }

    // left == rightとなるまで探しても見つからない場合は存在しない
    return -1;
  }
};
