#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> decrypt(vector<int> &code, int k) {
    const unsigned short n = code.size();

    if (k == 0) {
      return vector<int>(n, 0);
    }

    vector<int> ret(n);
    unsigned short l, r;
    if (k > 0)
      l = 1, r = k;
    else
      r = n - 1, l = n + k;

    int sum = accumulate(code.begin() + l, code.begin() + r + 1, 0);
    ret[0] = sum;

    for (unsigned short i = 1; i < n; i++) {
      sum -= code[l];
      l = (l + 1) % n;
      r = (r + 1) % n;
      sum += code[r];

      ret[i] = sum;
    }

    return ret;
  }
};