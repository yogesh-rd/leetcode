#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries) {
    int n = items.size();
    sort(items.begin(), items.end());

    vector<pair<int, int>> v;
    v.reserve(n);
    int mx = 0;
    for (const auto &item : items) {
      if (item[1] <= mx)
        continue;

      mx = item[1];
      v.push_back({item[0], item[1]});
    }
    n = v.size();

    vector<int> ret;
    ret.reserve(queries.size());
    for (const int &q : queries) {
      int l = 0, r = n - 1, val = 0;

      while (l <= r) {
        int m = l + (r - l) / 2;

        if (v[m].first <= q) {
          val = v[m].second;
          l = m + 1;
        } else {
          r = m - 1;
        }
      }

      ret.push_back(val);
    }

    return ret;
  }
};