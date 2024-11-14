#include <vector>

using namespace std;

class Solution {
public:
  int minimizedMaximum(int n, vector<int> &quantities) {
    int l = 1, r = 1e5, ret;
    while (l <= r) {
      int m = (l + r) / 2;

      int rem = n;
      for (const int &q : quantities) {
        rem -= (q + m - 1) / m;

        if (rem < 0)
          break;
      }

      if (rem >= 0) {
        ret = m;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }

    return ret;
  }
};