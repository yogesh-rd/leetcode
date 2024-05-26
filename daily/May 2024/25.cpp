#define endl '\n'
#pragma GCC optimize("O3", "unroll-loops,inline")

class Solution {
private:
  vector<string> ret;
  string curr;

  inline bool starts_with(string &s, int &start, string &w) {
    if (s.size() - start < w.size())
      return false;

    for (int i = 0; i < w.size(); i++) {
      if (w[i] != s[i + start])
        return false;
    }

    return true;
  }

  void backtrack(string &s, vector<string> &d, int start) {
    if (start >= s.size()) {
      ret.push_back(curr);
      return;
    }

    for (auto &w : d) {
      if (starts_with(s, start, w)) {
        bool empty = curr.empty();
        curr += (empty ? "" : " ") + w;

        backtrack(s, d, start + w.size());

        for (int i = 0; i < w.size(); i++)
          curr.pop_back();
        if (!empty)
          curr.pop_back();
      }
    }
  }

public:
  vector<string> wordBreak(string s, vector<string> &wordDict) {
    backtrack(s, wordDict, 0);
    return ret;
  }
};

static const bool __boost = []() {
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return ios_base::sync_with_stdio(false);
}();