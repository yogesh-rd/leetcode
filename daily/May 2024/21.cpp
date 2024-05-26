#define endl '\n'
#pragma GCC optimize("O3", "unroll-loops,inline")

class Solution {
public:
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> res;
    int n = nums.size();
    for (int i = 0; i < (1 << n); i++) {
      vector<int> subset;
      for (int j = 0; j < n; j++) {
        if (i & (1 << j)) {
          subset.push_back(nums[j]);
        }
      }
      res.push_back(subset);
    }
    return res;
  }
};

static const bool __boost = []() {
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return ios_base::sync_with_stdio(false);
}();