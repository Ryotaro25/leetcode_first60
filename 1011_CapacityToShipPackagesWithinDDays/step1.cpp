class Solution {
  public:
    int shipWithinDays(vector<int>& weights, int days) {
      int left = 0;
      int right = 0;
  
      for (auto weight : weights) {
        left = max(left, weight);
        right += weight;
      }
  
      while (left < right) {
        int middle = left + (right - left) / 2;
        
        if (!IsLoadable(weights, middle, days)) {
          left = middle + 1;
        } else {
          right = middle;
        }
      }
  
      return left;
    }
  
  private:
    bool IsLoadable(vector<int>& weights, int capacity, int required_days) {
      int day = 1;
      int total_weight = 0;
      for (auto weight : weights) {
        total_weight += weight;
        if (total_weight > capacity) {
          total_weight = weight;
          day++;
        }
      }
  
      return day <= required_days;
    }
  };
  