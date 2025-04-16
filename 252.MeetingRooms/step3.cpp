class Solution {
  public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
      set<int> used_hours;
      for (const vector<int>& interval : intervals) {
        for (int hour = interval[0]; hour < interval[1]; hour++) {
          if (used_hours.contains(hour)) {
            return false;
          }
          used_hours.insert(hour);
        }
      }
      return true;
    }
  };
