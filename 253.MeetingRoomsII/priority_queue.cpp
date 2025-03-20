class Solution {
  public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
      if (intervals.size() == 0) {
        return 1;
      }

      sort(intervals.begin(), intervals.end());
      priority_queue<int, vector<int>, greater<int>> using_rooms;
      using_rooms.push(intervals[0][1]);
      for (int i = 1; i < intervals.size(); i++) {
        int previous_end_time = using_rooms.top();
        // 現在の部屋の開始時間と比較
        if (intervals[i][0] >= previous_end_time) {
          using_rooms.pop();
        }
        // 現在の部屋の終了時間を入れる
        using_rooms.push(intervals[i][1]);
      }

      return using_rooms.size();
    }
  };
