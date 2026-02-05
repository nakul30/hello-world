class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n= nums.size();
        vector<int>ans(n,0);
        for(int i=0;i<nums.size();i++){
            int steps=nums[i];
            // if steps is positive
            if(steps>0){
               steps=steps%n;
                if(steps+i<n){
                    ans[i]=nums[i+steps];
                }
                else{
                    int toplace =(steps+i)-n;
                    ans[i]=nums[toplace];
                }
            }
            else{
                steps = abs(steps);
                steps=steps%n;
                if(i-steps>=0){
                    ans[i]=nums[i-steps];
                }
                else{
                    int neg = i-steps;
                    int toplace = n+neg;
                    ans[i]=nums[toplace];
                }
            }

            for(auto j: ans){
                cout << j << " ";
            }
            cout << endl;
        }

        return ans;
    }
};

// class Solution {
// public:
//     vector<int> constructTransformedArray(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> ans(n);

//         for (int i = 0; i < n; i++) {
//             int target = (i + nums[i]) % n;
//             if (target < 0) target += n;
//             ans[i] = nums[target];
//         }

//         return ans;
//     }
// };
