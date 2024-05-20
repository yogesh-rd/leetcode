class Solution {
public:
  long long maximumValueSum(vector<int> &nums, int k,
                            vector<vector<int>> &edges) {
    long long ret = accumulate(nums.begin(), nums.end(), 0ll);
    int min_neg = INT_MIN;
    int min_pos = INT_MAX;
    int pos_cnt = 0;
    for (auto &n : nums) {
      int diff = (n ^ k) - n;

      if (diff > 0) {
        pos_cnt++;
        ret += diff;
        min_pos = min(min_pos, diff);
      } else {
        min_neg = max(min_neg, diff);
      }
    }
    if (pos_cnt % 2) {
      ret -= min_pos;
      ret += max(min_pos + min_neg, 0);
    }

    return ret;
  }
};