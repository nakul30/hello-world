class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        // 0 1 4 4 7 5 (3,6)
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            auto up=upper_bound(nums.begin()+i+1,nums.end(),upper-nums[i]);
            auto down=lower_bound(nums.begin()+i+1,nums.end(),lower-nums[i]);

            ans+=(up-down);
        }
        return ans;
    }
};