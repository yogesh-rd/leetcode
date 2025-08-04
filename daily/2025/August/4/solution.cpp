class Solution {
public:
  int totalFruit(vector<int> &fruits) {
    const int n = fruits.size();

    unordered_map<int, int> freq;
    int ret = 0;
    for (int l = 0, r = 0; r < n; r++) {
      freq[fruits[r]]++;

      while (freq.size() > 2) {
        if (--freq[fruits[l]] == 0) {
          freq.erase(fruits[l]);
        }

        l++;
      }

      ret = max(ret, r - l + 1);
    }

    return ret;
  }
};