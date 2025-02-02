class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt=0;
        if(nums.size()<=1)return true;
        if(nums.back()>nums[0])cnt++;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                cnt++;
            }
        }
        if(cnt>=2){return false;}
        return true;
    }
};