#include "step3.h"

#include <iostream>
#include <numeric>

int Solution::shipWithinDays(std::vector<int>& weights, int days) {
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

bool Solution::IsLoadable(const std::vector<int>& weights, int capacity, int allowable_days) {
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

int main() {
  Solution solution;
  std::vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
  int days = 5;
  int result = solution.shipWithinDays(weights, days);
  std::cout << "The output is: " << result << std::endl;
  return 0;
}