
class Solution {
public:
  int minMeetingRooms(vector<vector<int>>& intervals) {
    if (intervals.size() == 0) {
      return 1;
    }
    vector<pair<int, string>> time_with_labels;

    for (const auto& interval : intervals) {
      time_with_labels.emplace_back(interval[0], "start"); // 会議開始
      time_with_labels.emplace_back(interval[1], "end"); // 会議終了
    }

    // 時刻が同じ場合はendがstartり前に来る
    // endがstartり辞書順で後にあるため
    sort(time_with_labels.begin(), time_with_labels.end());
    // 外部関数 `updateRoomCounter` を使用して最終的な会議室数を計算
    RoomCounter result = accumulate(time_with_labels.begin(), time_with_labels.end(),
                                    RoomCounter{0, 0}, updateRoomCounter);

    return result.min_num_required_rooms;
  }

private:
  struct RoomCounter {
    int num_using_rooms;
    int min_num_required_rooms;
  };

// 外部に畳み込み用の関数を定義
  static RoomCounter updateRoomCounter(RoomCounter counter, const pair<int, string>& time_with_labels) {
    if (time_with_labels.second == "start") {
      counter.num_using_rooms++;
      counter.min_num_required_rooms = max(counter.min_num_required_rooms, counter.num_using_rooms);
    } else {
      counter.num_using_rooms--;
    }
    return counter;
  }
};
