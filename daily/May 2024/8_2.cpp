class Solution {
public:
  vector<string> findRelativeRanks(vector<int> &score) {
    const int n = score.size();
    int indices[n];
    iota(indices, indices + n, 0);

    sort(indices, indices + n, [&](const int left, const int right) {
      return score[left] > score[right];
    });

    vector<string> ret(n);

    for (int i = 0; i < n; i++) {
      if (i == 0) {
        ret[indices[i]] = "Gold Medal";
      } else if (i == 1) {
        ret[indices[i]] = "Silver Medal";
      } else if (i == 2) {
        ret[indices[i]] = "Bronze Medal";
      } else {
        ret[indices[i]] = to_string(i + 1);
      }
    }

    return ret;
  }
};