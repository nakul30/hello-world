class Solution {
public:
    int solve(vector<int>nums , int target , int index ,int sum , int n,vector<vector<int>>&dp,int total){
        if(index >=n ){
            if(sum == target ){
                return 1 ; 
            }
            else{return 0;}
        }
        if(dp[index][sum+total]!=-1){
            return dp[index][sum+total];
        }

        int a = solve(nums , target , index +1 , sum + nums[index] , n ,dp,total);
        int b = solve(nums , target , index +1 , sum - nums[index] , n,dp,total);

        return dp[index][sum+total]= a +b ;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int total=0;
        for(auto i:nums){
            total+=i;
        }
        int newtotal=2*total;
        vector<vector<int>>dp(nums.size(),vector<int>(newtotal+1,-1));
        return solve(nums , target , 0 , 0 , nums.size(),dp,total);
    }
};