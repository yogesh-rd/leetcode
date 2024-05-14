class Solution {
public:
  double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k) {
    int n = quality.size();
    vector<pair<double, int>> rq(n);
    for (int i = 0; i < n; i++) {
      rq[i].first = static_cast<double>(wage[i]) / quality[i];
      rq[i].second = quality[i];
    }

    sort(rq.begin(), rq.end());

    int q_sum = 0;
    priority_queue<int> pq;
    for (int i = 0; i < k; i++) {
      q_sum += rq[i].second;
      pq.push(rq[i].second);
    }
    double ret = q_sum * rq[k - 1].first;
    for (int i = k; i < n; i++) {
      pq.push(rq[i].second);
      q_sum += (rq[i].second - pq.top());
      pq.pop();

      ret = min(ret, q_sum * rq[i].first);
    }

    return ret;
  }
};