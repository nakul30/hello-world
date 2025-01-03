class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
    int count=0;
        vector<long long> prefSum(n);
        prefSum[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefSum[i] = prefSum[i - 1] + nums[i];
        }

        for (int i = 0; i < n - 1; i++) {
            long long leftSum = prefSum[i];

            long long rightSum = prefSum[n - 1] - prefSum[i];

            if (leftSum >= rightSum) {
                count++;
            }
        }

        return count;
    }
};