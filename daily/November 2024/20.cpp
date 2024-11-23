#include <string>

using namespace std;

class Solution {
public:
  int takeCharacters(string s, int k) {
    const int n = s.size();

    if (n < 3 * k)
      return -1;

    int cnt[3] = {};
    for (const char &c : s)
      cnt[c - 'a']++;

    if (cnt[0] < k || cnt[1] < k || cnt[2] < k)
      return -1;

    if (cnt[0] + cnt[1] + cnt[2] == 3 * k)
      return n;

    int ret = n;
    for (int l = 0, r = 0; r < n; r++) {
      cnt[s[r] - 'a']--;
      while (l <= r && (cnt[0] < k || cnt[1] < k || cnt[2] < k)) {
        cnt[s[l++] - 'a']++;
      }

      ret = min(ret, n - r + l - 1);
    }

    return ret;
  }
};