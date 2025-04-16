class Solution {
  public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
      // 時間ごとの鍵の貸し出し数を記録
      map<int, int> num_keys;
      for (const auto& interval : intervals) {
        // 鍵の貸し出し
        num_keys[interval[0]]++;
        // 鍵の返却
        num_keys[interval[1]]--;
      }

      int min_required_rooms = 0;
      int current_using_rooms = 0;
      // 時間ごとの鍵の貸し出し数のうち最大のものを探す
      for (const auto& [using_time, num_key] : num_keys) {
        current_using_rooms += num_key;
        min_required_rooms = max(min_required_rooms, current_using_rooms);
      }

      return min_required_rooms;
    }
  };
