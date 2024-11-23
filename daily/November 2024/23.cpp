#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
  const char stone = '#';
  const char empty = '.';
  const char obstacle = '*';

public:
  vector<vector<char>> rotateTheBox(const vector<vector<char>> &box) {
    const int m = box.size();
    const int n = box[0].size();

    vector<vector<char>> ret(n, vector<char>(m));
    for (int i = 0; i < m; i++) {
      int start = 0;
      while (start < n) {
        int cnt = 0, end = start;
        while (end < n && box[i][end] != obstacle) {
          cnt += box[i][end] == stone;
          end++;
        }

        for (int j = end - 1; j >= start; j--) {
          if (cnt) {
            ret[j][m - 1 - i] = stone;
            cnt--;
          } else {
            ret[j][m - 1 - i] = empty;
          }
        }

        if (end < n)
          ret[end][m - 1 - i] = obstacle;

        start = end + 1;
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