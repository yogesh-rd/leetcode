class DisjointSet {
  int *rank, *parent, n;

public:
  DisjointSet(int n) : n(n) {
    rank = new int[n];
    parent = new int[n];
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
  }

  ~DisjointSet() {
    delete[] rank;
    delete[] parent;
  }

  int find(int x) {
    if (parent[x] != x) {
      parent[x] = find(parent[x]);
    }

    return parent[x];
  }

  void Union(int x, int y) {
    int xset = find(x);
    int yset = find(y);

    if (xset == yset)
      return;

    if (rank[xset] < rank[yset]) {
      parent[xset] = yset;
    } else if (rank[xset] > rank[yset]) {
      parent[yset] = xset;
    }

    else {
      parent[yset] = xset;
      rank[xset] = rank[xset] + 1;
    }
  }
};

class Solution {
public:
  vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries) {
    vector<bool> ret;
    ret.reserve(queries.size());
    int n = nums.size();
    DisjointSet d(n);
    int idx = 1;
    while (idx < n) {
      while (idx < n && (nums[idx] % 2 ^ nums[idx - 1] % 2)) {
        d.Union(idx, idx - 1);
        idx++;
      }
      idx++;
    }

    for (auto &q : queries) {
      ret.push_back(d.find(q[0]) == d.find(q[1]));
    }

    return ret;
  }
};