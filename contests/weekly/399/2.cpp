class Solution {
public:
  string compressedString(string word) {
    string ret;
    int i = 0, n = word.size();
    while (i < n) {
      int cnt = 0;
      char c = word[i];
      while (i < n && word[i] == c && cnt < 9) {
        i++;
        cnt++;
      }

      ret += '0' + cnt;
      ret += c;
    }

    return ret;
  }
};