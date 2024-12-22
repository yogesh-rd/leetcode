#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
  int maxKDivisibleComponents(int n, vector<vector<int>> &edges,
                              vector<int> &values, int k) {
    if (k == 1 || n == 1) {
      return n;
    }

    vector<vector<int>> adj(n);
    vector<int> deg(n, 0);

    for (const auto &e : edges) {
      adj[e[0]].push_back(e[1]);
      adj[e[1]].push_back(e[0]);
      deg[e[0]]++;
      deg[e[1]]++;
    }

    queue<int> leaves;
    for (int i = 0; i < n; i++) {
      if (deg[i] == 1) {
        leaves.push(i);
      }
    }

    int ret = 0;
    while (leaves.size()) {
      int u = leaves.front();
      leaves.pop();
      deg[u]--; // deg[u] becomes 0

      if (values[u] % k == 0)
        ret++;

      for (const int &v : adj[u]) {
        if (deg[v] == 0)
          continue;

        values[v] += values[u];
        values[v] %= k;

        if (--deg[v] == 1) {
          leaves.push(v);
        }
      }
    }

    return ret;
  }
};