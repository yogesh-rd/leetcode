#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  long long countFairPairs(vector<int> &nums, int lower, int upper) {
    sort(nums.begin(), nums.end());

    const size_t n = nums.size();
    long long ret = 0;
    for (size_t i = 0; i < n; i++) {
      int l = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) -
              nums.begin();
      int r = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) -
              nums.begin();

      if (l <= r)
        ret += r - l;
    }

    return ret;
  }
};