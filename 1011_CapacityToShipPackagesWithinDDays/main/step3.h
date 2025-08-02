#ifndef CAPACITYTOSHIPPACKAGE_MAIN_STEP3_H_ // The format of the symbol name should be <PROJECT>_<PATH>_<FILE>_H_.
#define CAPACITYTOSHIPPACKAGE_MAIN_STEP3_H_

#include <vector>

class Solution {
  public:
    int shipWithinDays(std::vector<int>& weights, int days);

  private:
    bool IsLoadable(const std::vector<int>& weights, int capacity, int allowable_days);
  };

#endif
  