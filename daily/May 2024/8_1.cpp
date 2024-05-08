class Solution {
public:
  vector<string> findRelativeRanks(vector<int> &score) {
    int n = score.size();
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
      mp[score[i]] = i;
    }
    vector<string> ret(n);
    int pos = n;
    for (auto &[s, idx] : mp) {
      if (pos > 3) {
        ret[idx] = to_string(pos);
      } else if (pos == 3) {
        ret[idx] = "Bronze Medal";
      } else if (pos == 2) {
        ret[idx] = "Silver Medal";
      } else {
        ret[idx] = "Gold Medal";
      }

      pos--;
    }

    return ret;
  }
};