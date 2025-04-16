class Solution {
  public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
      set<int> used_hours;
      for (vector<int>& interval : intervals) {
        int start = interval[0];
        int end = interval[1];
        for (int hour = start; hour < end; hour++) {
          if (used_hours.contains(hour)) {
            return false;
          }
          used_hours.insert(hour);
        }
      }
      return true;
    }
  };
