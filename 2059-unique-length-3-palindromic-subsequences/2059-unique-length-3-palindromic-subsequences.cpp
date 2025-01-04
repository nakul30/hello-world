class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        vector<int> first(26, INT_MAX); 
        vector<int> last(26, INT_MIN);   

        for(int i = 0; i < n; i++) {
            first[s[i] - 'a'] = min(first[s[i] - 'a'], i);
            last[s[i] - 'a'] = max(last[s[i] - 'a'], i);
        }
        
        int result = 0;
        for(int i = 0; i < 26; i++) {
            if(first[i] != INT_MAX && last[i] != INT_MIN && first[i] < last[i]) {
                unordered_set<char> unique;
                for(int j = first[i] + 1; j < last[i]; j++) {
                    unique.insert(s[j]);
                }
                result += unique.size();
            }
        }
        
        return result;
    }
};