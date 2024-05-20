class Solution {
public:
  int subsetXORSum(vector<int> &nums) {
    int o = 0;
    for (const int &n : nums)
      o |= n;
    return o << (nums.size() - 1);
  }
};
