// Binary search

class Solution {
public:
  vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k) {
    const int n = arr.size();
    double l = 0, r = 1;
    int num, den;
    while (l < r) {
      double m = (l + r) / 2;
      int cnt = 0;
      double max_f = 0;
      for (int i = 0, j = 1; i < n; i++) {
        while (j < n && arr[i] >= m * arr[j])
          j++;

        cnt += n - j;
        if (j == n)
          break;

        double f = static_cast<double>(arr[i]) / arr[j];

        if (f > max_f) {
          num = arr[i];
          den = arr[j];
          max_f = f;
        }
      }

      if (cnt == k)
        break;
      if (cnt < k)
        l = m;
      else
        r = m;
    }

    return {num, den};
  }
};