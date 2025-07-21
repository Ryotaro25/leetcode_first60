class Solution {
  public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
      // 時間ごとの部屋の貸し出し数を記録
      map<int, int> time_to_room_reservation;
      for (const auto& interval : intervals) {
        time_to_room_reservation[interval[0]]++;
        time_to_room_reservation[interval[1]]--;
      }

      int min_required_rooms = 0;
      int current_used_rooms = 0;
      // 時間ごとの鍵の貸し出し数のうち最大のものを探す
      for (const auto& [time, num_used_rooms] : time_to_room_reservation) {
        current_used_rooms += num_used_rooms;
        min_required_rooms = max(min_required_rooms, current_used_rooms);
      }

      return min_required_rooms;
    }
  };
