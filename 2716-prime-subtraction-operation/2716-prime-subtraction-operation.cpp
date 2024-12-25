class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int maxnumber = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            maxnumber = max(nums[i], maxnumber);
        }
        vector<int> sieve(maxnumber + 1, true);
        sieve[1] = false;
        for (int i = 2; i <= sqrt(maxnumber + 1); i++) {
            if (sieve[i]) {
                for (int j = i * i; j <= maxnumber; j += i) {
                    sieve[j] = false;
                }
            }
        }
        vector<int> primes;
        for (int i = 2; i <= maxnumber; i++) {
            if (sieve[i]) {
                primes.push_back(i);
            }
        }
        for(int i=0;i<nums.size();i++){
            int diff = i == 0 ? nums[0] - 1 : nums[i] - nums[i - 1] - 1;
            int lb = lower_bound(primes.begin(),primes.end(),diff)-primes.begin();

            if (lb == primes.size() or primes[lb] > diff)
                lb--;
                
            if (lb < 0) {
                if (i == 0 or nums[i] > nums[i - 1])
                    continue;
                else
                    return false;
            }
            nums[i] -= primes[lb];
        }  
        return true;    
    }
};