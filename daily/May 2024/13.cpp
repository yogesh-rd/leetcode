class Solution {
public:
  int matrixScore(vector<vector<int>> &grid) {
    int ret = 0;
    int m = grid.size();
    int n = grid[0].size();

    for (int j = 0, p = 1 << (n - 1); j < n; j++, p >>= 1) {
      int cnt = 0;
      for (int i = 0; i < m; i++) {
        cnt += grid[i][0] == 0 ^ grid[i][j] == 1;
      }
      ret += max(cnt, m - cnt) * p;
    }

    return ret;
  }
};