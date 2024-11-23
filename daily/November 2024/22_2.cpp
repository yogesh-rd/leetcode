#include <bitset>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int maxEqualRowsAfterFlips(vector<vector<int>> &matrix) {
    const int n = matrix[0].size();
    unordered_map<bitset<300>, int> cnt;

    for (auto &row : matrix) {
      bitset<300> pattern;
      for (int i = 0; i < n; i++) {
        pattern[i] = row[0] ^ row[i];
      }

      cnt[pattern]++;
    }

    int ret = 1;
    for (auto &[k, v] : cnt) {
      ret = max(ret, v);
    }

    return ret;
  }
};