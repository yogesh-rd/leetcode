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