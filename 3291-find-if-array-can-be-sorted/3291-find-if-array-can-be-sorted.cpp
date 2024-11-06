class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> newpair;
        
        for (int i = 0; i < n; i++) {
            newpair.push_back({nums[i], __builtin_popcount(nums[i])});
        }
        
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (newpair[j].second==newpair[j + 1].second && newpair[j].first > newpair[j + 1].first) {
                    swap(newpair[j], newpair[j + 1]);
                }
            }
        }
        for (int i = 1; i < n; i++) {
            if (newpair[i].first < newpair[i - 1].first) {
                return false;
            }
        }
        
        return true;
    }
};