#define endl '\n'
#pragma GCC optimize("O3", "unroll-loops,inline")

class Solution {
private:
  vector<int> w;
  uint8_t cnt[26] = {};
  int ret = 0;

  inline void initialise_weights(vector<string> &words, vector<int> &score) {
    w.reserve(words.size());
    for (auto &word : words) {
      int sum = 0;
      for (auto &c : word)
        sum += score[c - 'a'];
      w.push_back(sum);
    }
  }

  inline void initialise_cnt(vector<char> &letters) {
    for (auto &c : letters)
      cnt[c - 'a']++;
  }

  inline bool can_pick(string &s) {
    uint8_t tmp[26] = {};
    for (auto &c : s)
      tmp[c - 'a']++;

    for (int i = 0; i < 26; i++) {
      if (tmp[i] > cnt[i])
        return false;
    }

    return true;
  }

  inline void pick(string &s) {
    for (auto &c : s) {
      cnt[c - 'a']--;
    }
  }

  inline void unpick(string &s) {
    for (auto &c : s) {
      cnt[c - 'a']++;
    }
  }

  void backtrack(vector<string> &words, int curr, int start) {
    ret = max(ret, curr);
    if (start >= words.size())
      return;

    for (int i = start; i < words.size(); i++) {
      if (can_pick(words[i])) {
        pick(words[i]);
        backtrack(words, curr + w[i], i + 1);
        unpick(words[i]);
      }
    }
  }

public:
  int maxScoreWords(vector<string> &words, vector<char> &letters,
                    vector<int> &score) {
    initialise_weights(words, score);
    initialise_cnt(letters);
    backtrack(words, 0, 0);
    return ret;
  }
};

static const bool __boost = []() {
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return ios_base::sync_with_stdio(false);
}();