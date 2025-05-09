class Solution {
  public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
      if (intervals.size() == 0) {
        return false;
      }
      sort(intervals.begin(), intervals.end());
      for (int i = 0; i < intervals.size() - 1; i++) {
        // 現在の終了時間 > 次の開始時間 で比較
        if (intervals[i][1] > intervals[i + 1][0]) {
          return false;
        }
      }
      
      return true;
    }
  };
