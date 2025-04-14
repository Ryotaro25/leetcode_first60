class Solution {
  public:
    int shipWithinDays(vector<int>& weights, int days) {
      int min_capacity = *max_element(weights.begin(), weights.end());
      int max_capacity = accumulate(weights.begin(), weights.end(), 0);
  
      while (min_capacity < max_capacity) {
        int middle = min_capacity + (max_capacity - min_capacity) / 2;
        
        if (!IsLoadable(weights, middle, days)) {
          min_capacity = middle + 1;
        } else {
          max_capacity = middle;
        }
      }
  
      return min_capacity;
    }
  
  private:
    bool IsLoadable(const vector<int>& weights, int capacity, int allowable_days) {
      int required_day = 1;
      int total_weight = 0;
      for (auto weight : weights) {
        total_weight += weight;
        if (total_weight > capacity) {
          total_weight = weight;
          required_day++;
        }
      }
  
      return required_day <= allowable_days;
    }
  };
  