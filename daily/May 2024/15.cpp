class Solution {
public:
  int maximumSafenessFactor(vector<vector<int>> &grid) {
    int n = grid.size();
    if (n == 1 || grid[0][0] || grid[n - 1][n - 1])
      return 0;

    vector<vector<int>> d(n, vector<int>(n, INT_MAX));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j]) {
          d[i][j] = 0;
          q.push({i, j});
        }
      }
    }

    while (!q.empty()) {
      auto [i, j] = q.front();
      q.pop();
      int dist = d[i][j];

      for (int b = 0; b < 4; b++) {
        int r = i + X[b];
        int c = j + Y[b];

        if (r >= 0 && r < n && c >= 0 && c < n && 1 + dist < d[r][c]) {
          d[r][c] = 1 + dist;
          q.push({r, c});
        }
      }
    }

    priority_queue<tuple<int, int, int>> pq;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    visited[0][0] = true;

    pq.push({d[0][0], 0, 0});
    while (!pq.empty()) {
      auto [dist, i, j] = pq.top();
      pq.pop();

      if (i == n - 1 && j == n - 1)
        return dist;

      for (int b = 0; b < 4; b++) {
        int r = i + X[b];
        int c = j + Y[b];

        if (r >= 0 && r < n && c >= 0 && c < n && !visited[r][c]) {
          int min_dist = min(dist, d[r][c]);
          pq.push({min_dist, r, c});
          visited[r][c] = true;
        }
      }
    }

    return -1;
  }
};