class Solution {
public:
    int xori(vector<int> nums){
        int ans=0;
        for(auto x:nums){
            ans = (ans^x);
        }
        return ans;
    }
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()%2==0 && nums2.size()%2==0){
            return 0;
        }
        else if(nums1.size()%2==0){
            return xori(nums1);
        }
        else if(nums2.size()%2==0){
            return xori(nums2);
        }
        else{
            int a=xori(nums1);
            int b=xori(nums2);
            return a^b;
        }
        return 0;
    }
};