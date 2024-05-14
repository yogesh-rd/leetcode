class Solution {
public:
  vector<vector<int>> largestLocal(vector<vector<int>> &grid) {
    int n = grid.size();
    vector<vector<int>> ret(n - 2, vector<int>(n - 2));

    for (int i = 1; i < n - 1; i++) {
      for (int j = 1; j < n - 1; j++) {
        int mx = -1;
        for (int ii = i - 1; ii <= i + 1; ii++) {
          for (int jj = j - 1; jj <= j + 1; jj++) {
            mx = max(mx, grid[ii][jj]);
          }
        }
        ret[i - 1][j - 1] = mx;
      }
    }

    return ret;
  }
};