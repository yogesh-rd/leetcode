// O(n^2)

typedef pair<int, int> pii;
typedef pair<double, pii> pdpii;

class Solution {
public:
  vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k) {
    const int n = arr.size();
    priority_queue<pdpii, vector<pdpii>, greater<pdpii>> pq;

    for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
        pq.push({(double)arr[i] / arr[j], {i, j}});
      }
    }

    while (--k) {
      pq.pop();
    }

    return {arr[pq.top().second.first], arr[pq.top().second.second]};
  }
};