class Solution {
public:
  bool isArraySpecial(vector<int> &nums) {
    int n = nums.size();
    if (n == 1)
      return true;

    bool ret = true;
    for (int i = 0; i < n - 1; i++) {
      bool a = nums[i] % 2;
      bool b = nums[i + 1] % 2;

      if (!(a ^ b)) {
        ret = false;
        break;
      }
    }
    return ret;
  }
};