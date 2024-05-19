class Solution {
public:
  long long sumDigitDifferences(vector<int> &nums) {
    long long ret = 0;
    int cnt[10][10] = {};
    for (auto &x : nums) {
      int i = 0;
      while (x) {
        cnt[i][x % 10]++;
        i++;
        x /= 10;
      }
    }

    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 9; j++) {
        for (int k = j + 1; k < 10; k++) {
          ret += cnt[i][j] * cnt[i][k];
        }
      }
    }

    return ret;
  }
};