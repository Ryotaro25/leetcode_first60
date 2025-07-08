// 鍵を借りる時間と返す時間をばらばらにソートして、鍵の数が2つ以上でたかを確認という手もありますね。
class Solution {
  public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
      map<int, int> num_keys;
      for (const auto& interval : intervals) {
        // 鍵を借りる
        num_keys[interval[0]]++;
        // 鍵を返す
        num_keys[interval[1]]--;
      }

      int sum_keys = 0;
      for (auto& [using_time, num_key] : num_keys) {
        sum_keys += num_key;
        if (sum_keys > 1) {
          return false;
        }
      }
      
      return true;
    }
  };
