#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  long long maximumSubarraySum(vector<int> &nums, int k) {
    const int n = nums.size();

    unordered_map<int, int> mp;
    for (int i = 0; i < k; i++)
      mp[nums[i]]++;

    long long sum = accumulate(nums.begin(), nums.begin() + k, 0ll);
    long long ret = 0;

    int l = 0, r = k - 1;
    while (r < n) {
      if (mp.size() == k)
        ret = max(ret, sum);

      sum -= nums[l];
      if (--mp[nums[l]] == 0) {
        mp.erase(nums[l]);
      }
      l++;

      if (++r < n) {
        sum += nums[r];
        mp[nums[r]]++;
      }
    }

    return ret;
  }
};