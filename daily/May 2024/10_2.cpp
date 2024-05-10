// O(k)

typedef pair<int, int> pii;
typedef pair<double, pii> pdpii;

class Solution {
public:
  vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k) {
    const int n = arr.size();
    priority_queue<pdpii, vector<pdpii>, greater<pdpii>> pq;

    for (int i = 0; i < n - 1; i++) {
      pq.push({(double)arr[i] / arr[n - 1], {i, n - 1}});
    }

    while (--k) {
      auto [f, p] = pq.top();
      pq.pop();
      if (p.second != p.first + 1)
        pq.push({(double)arr[p.first] / arr[p.second - 1],
                 {p.first, p.second - 1}});
    }

    return {arr[pq.top().second.first], arr[pq.top().second.second]};
  }
};