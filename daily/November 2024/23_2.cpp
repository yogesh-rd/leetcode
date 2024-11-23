#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  const char stone = '#';
  const char empty = '.';
  const char obstacle = '*';

public:
  vector<vector<char>> rotateTheBox(const vector<vector<char>> &box) {
    const int m = box.size();
    const int n = box[0].size();

    vector<vector<char>> ret(n, vector<char>(m, '.'));
    for (int i = 0; i < m; i++) {
      int bottom = n - 1;
      for (int j = n - 1; j >= 0; j--) {
        if (box[i][j] == stone) {
          ret[bottom][m - 1 - i] = stone;
          bottom--;
        } else if (box[i][j] == obstacle) {
          ret[j][m - 1 - i] = obstacle;
          bottom = j - 1;
        }
      }
    }
    return ret;
  }
};

static const bool __boost = []() {
  cin.tie(0);
  cout.tie(0);
  return ios_base::sync_with_stdio(0);
}();