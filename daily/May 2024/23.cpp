class Solution {
private:
  inline bool valid(vector<int> &subset, int &k) {
    const int n = subset.size();
    for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
        if (abs(subset[i] - subset[j]) == k) {
          return false;
        }
      }
    }

    return true;
  }
  void backtrack(int &ret, vector<int> &nums, vector<int> &subset, int &k,
                 int start) {
    if (!subset.empty()) {
      if (valid(subset, k)) {
        ret++;
      } else {
        return;
      }
    }

    for (int i = start; i < nums.size(); i++) {
      subset.push_back(nums[i]);
      backtrack(ret, nums, subset, k, i + 1);
      subset.pop_back();
    }
  }

public:
  int beautifulSubsets(vector<int> &nums, int k) {
    int ret = 0;
    vector<int> subset;
    backtrack(ret, nums, subset, k, 0);
    return ret;
  }
};