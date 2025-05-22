class Solution {
  public:
    int shipWithinDays(vector<int>& weights, int days) {
      // left = min_capacity、right = max_capacityとして二分探索を行う
      int min_capacity = *max_element(weights.begin(), weights.end());
      int max_capacity = accumulate(weights.begin(), weights.end(), 0);

      while (min_capacity < max_capacity) {
        int mid = min_capacity + (max_capacity - min_capacity) / 2;

        if (!IsLoadable(weights, mid, days)) {
          min_capacity = mid + 1;
        } else {
          max_capacity = mid;
        }
      }
      return min_capacity;
    }

  private:
    bool IsLoadable(const vector<int>& weights, int capacity, int allowable_days) {
      int required_days = 1;
      int total_weight = 0;
      for (auto weight : weights) {
        total_weight += weight;
        if (total_weight > capacity) {
          total_weight = weight;
          required_days++;
        }
      }

      return required_days <= allowable_days;
    }
  };
  