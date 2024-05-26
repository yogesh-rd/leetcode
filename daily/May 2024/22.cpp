class Solution {
private:
  bool isPalindrome(string s) {
    int n = s.size();
    for (int i = 0; i < n / 2; i++) {
      if (s[i] != s[n - 1 - i]) {
        return false;
      }
    }

    return true;
  }

  void backtrack(vector<vector<string>> &res, vector<string> &part, string s) {
    if (s.size() == 0) {
      res.push_back(part);
      return;
    }

    for (int i = 0; i < s.size(); i++) {
      string substring = s.substr(0, i + 1);
      if (isPalindrome(substring)) {
        part.push_back(substring);
        backtrack(res, part, s.substr(i + 1));
        part.pop_back();
      }
    }
  }

public:
  vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    vector<string> part;
    backtrack(res, part, s);
    return res;
  }
};