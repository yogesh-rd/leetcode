# 2410. Maximum Matching of Players With Trainers - Greedy Two Pointer Solution

# Intuition
To get the maximum number of matches, players must be matched with trainers with capacities closest to their abilities.

# Approach
Each trainer can only be matched with one player. Sort players and trainers. Use two pointers ($i$ and $j$ respectively) to traverse the sorted lists and an integer counter for the number of matches.

In each iteration $(i,j)$ if $players[i]<=trainers[j]$ then increment $i$ and the counter. $j$ will always be incremented since a trainer with a greater capacity should be considered in the next iteration.

# Complexity
- Time complexity: $O(n \lg n)$

- Space complexity: $O(n)$

# Code
```cpp []
class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        if (trainers.back() < players.front()) {
            return 0;
        }

        const int m = players.size(), n = trainers.size();
        int i = 0, j = 0, ret = 0;

        while (i < m && j < n) {
            if (players[i] <= trainers[j]) {
                i++, ret++;
            }

            j++;
        }

        return ret;
    }
};

static const bool init = []() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    return true;
}();
```