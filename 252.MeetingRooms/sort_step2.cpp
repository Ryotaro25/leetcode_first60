class Solution {
  public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
      if (intervals.size() == 0) {
        return true;
      }
      sort(intervals.begin(), intervals.end());
      int prev_end_time = intervals[0][1];
      for (int i = 1; i < intervals.size(); i++) {
        if (prev_end_time > intervals[i][0]) {
          return false;
        }
        prev_end_time = intervals[i][1];
      }
      
      return true;
    }
  };
