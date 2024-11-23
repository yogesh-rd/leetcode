#include <iostream>
#include <vcruntime_string.h>
#include <vector>

using namespace std;

class Solution {
public:
  int countUnguarded(int m, int n, vector<vector<int>> &guards,
                     vector<vector<int>> &walls) {
    // 0: unguarded, 1: guard/wall, 2: guarded
    short g[m][n];
    memset(g, 0, sizeof(g));

    for (auto &v : guards) {
      g[v[0]][v[1]] = 1;
    }

    for (auto &v : walls) {
      g[v[0]][v[1]] = 1;
    }

    // Up: (-1, 0)
    // Right: (0, 1)
    // Down: (1, 0)
    // Left: (0, -1)
    const int d[5] = {-1, 0, 1, 0, -1};

    for (auto &v : guards) {
      for (int k = 0; k < 4; k++) {
        int dr = d[k], dc = d[k + 1];

        for (int r = v[0] + dr, c = v[1] + dc;
             r >= 0 && r < m && c >= 0 && c < n && g[r][c] != 1;
             r += dr, c += dc) {
          g[r][c] = 2;
        }
      }
    }

    int ret = 0;
    for (int i = 0; i < m; i++) {
      ret += count(g[i], g[i] + n, 0);
    }

    return ret;
  }
};

static const bool __boost = []() {
  cin.tie(0);
  cout.tie(0);
  return ios_base::sync_with_stdio(0);
}();