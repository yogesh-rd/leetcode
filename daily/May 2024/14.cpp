class Solution {
private:
  int ret, m, n;
  vector<vector<int>> grid;

  void dfs(int i, int j, int curr) {
    if (i < 0 || j < 0 || i >= m || j >= n || !grid[i][j])
      return;

    curr += grid[i][j];
    int temp = grid[i][j];
    grid[i][j] = 0;
    ret = max(ret, curr);

    dfs(i - 1, j, curr);
    dfs(i + 1, j, curr);
    dfs(i, j + 1, curr);
    dfs(i, j - 1, curr);

    grid[i][j] = temp;
  }

public:
  int getMaximumGold(vector<vector<int>> &grid) {
    this->grid = grid;
    m = grid.size();
    n = grid[0].size();
    ret = 0;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j]) {
          dfs(i, j, 0);
        }
      }
    }

    return ret;
  }
};