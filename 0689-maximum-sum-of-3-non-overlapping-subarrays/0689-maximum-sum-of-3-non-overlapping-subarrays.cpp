class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> sum(n - k + 1); 
        long long temp = 0;

        for (int i = 0; i < k; i++) {
            temp += nums[i];
        }
        sum[0] = temp;
        for (int i = k; i < n; i++) {
            temp += nums[i] - nums[i - k];
            sum[i - k + 1] = temp;
        }
        for(int i=0;i<sum.size();i++){
            cout << sum[i] <<" ";
        }
        cout<<endl;
        vector<int> left(n - k + 1), right(n - k + 1);
        int best = 0;
        
        // Fill the 'left' array
        for (int i = 0; i < n - k + 1; i++) {
            if (sum[i] > sum[best]) {
                best = i;
            }
            left[i] = best;
        }
        
        best = n - k;
        // Fill the 'right' array
        for (int i = n - k; i >= 0; i--) {
            if (sum[i] >= sum[best]) {
                best = i;
            }
            right[i] = best;
        }
        cout <<"Left :"<<endl;
        for(int i=0;i<right.size();i++){
            cout << left[i] <<" ";
        }
        cout << endl;
        cout <<"Right :"<<endl;
        for(int i=0;i<right.size();i++){
            cout << right[i] <<" ";
        }
        cout << endl;
        vector<int> answer(3);
        long long maxSum = 0;
        for (int j = k; j < n - 2 * k + 1; j++) {
            int i = left[j - k];
            int l = right[j + k];
            long long total = sum[i] + sum[j] + sum[l];
            if (total > maxSum) {
                maxSum = total;
                answer = {i, j, l};
            }
        }
        
        return answer;
    }
};
