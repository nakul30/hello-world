class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> freqA, freqB;
        vector<int> result;
        int ans = 0;
        
        for (size_t i = 0; i < A.size(); i++) {
            freqA[A[i]]++;
            freqB[B[i]]++;
           
            if (freqA[A[i]] == 1 && freqB[A[i]] > 0) ans++;
            if (freqB[B[i]] == 1 && freqA[B[i]] > 0 && A[i] != B[i]) ans++;
            
            result.push_back(ans);
        }
        return result;
    }
};
