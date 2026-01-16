class Solution {
public:
    int maximizeSquareArea(int m, int n,
                           vector<int>& hBars,
                           vector<int>& vBars) {

        // add outer boundaries
        hBars.push_back(1);
        hBars.push_back(m);
        vBars.push_back(1);
        vBars.push_back(n);

        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        unordered_set<int> hDiffs;

        // all horizontal distances
        for (int i = 0; i < hBars.size(); i++) {
            for (int j = i + 1; j < hBars.size(); j++) {
                hDiffs.insert(hBars[j] - hBars[i]);
            }
        }

        int maxSide = -1;
         const long long MOD = 1e9 + 7; 
        // match vertical distances
        for (int i = 0; i < vBars.size(); i++) {
            for (int j = i + 1; j < vBars.size(); j++) {
                int diff = vBars[j] - vBars[i];
                if (hDiffs.count(diff)) {
                    maxSide = max(maxSide, diff);
                }
            }
        }

         if (maxSide == -1) return -1;
        return (maxSide % MOD) * (maxSide % MOD) % MOD;
    }
};
