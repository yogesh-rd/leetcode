#include <iostream>
#include <map>
#include <vector>

#define endl '\n'

using namespace std;

class Solution {
public:
  int maxEqualRowsAfterFlips(vector<vector<int>> &matrix) {
    const int n = matrix[0].size();

    map<vector<int>, int> cnt;

    for (auto &v : matrix) {
      cnt[v]++;
    }

    int ret = 1;
    for (auto itr1 = cnt.begin(); itr1 != cnt.end(); itr1++) {
      ret = max(ret, itr1->second);

      auto itr2 = itr1;

      for (itr2++; itr2 != cnt.end(); itr2++) {
        int s = 0;
        for (int i = 0; i < n; i++) {
          s += itr1->first[i] ^ itr2->first[i];
        }

        if (s == n) {
          ret = max(ret, itr1->second + itr2->second);
        }
      }
    }

    return ret;
  }
};

static const bool __boost = []() {
  cin.tie(0);
  cout.tie(0);
  return ios_base::sync_with_stdio(0);
}();