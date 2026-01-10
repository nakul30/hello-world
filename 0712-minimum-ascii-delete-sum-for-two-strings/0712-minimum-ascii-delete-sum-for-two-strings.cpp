class Solution {
public:
    int solve(int i,int j,string s1,string s2,vector<vector<int>> &dp){
        if(i==s1.size() || j == s2.size()){
            // TODO [all asci of string that is left]
            int ans=0;
            for(int f=i;f<s1.size();f++){
                ans += static_cast<int>(s1[f]);
            }
            for(int f=j;f<s2.size();f++){
                ans+=static_cast<int>(s2[f]);
            }
            return ans;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s1[i]==s2[j]){
            // no deletion reuired continue fwd both
            return dp[i][j] = solve(i+1,j+1,s1,s2,dp);
        }

        int a1= solve(i+1,j,s1,s2,dp) + static_cast<int>(s1[i]);
        int a2= solve(i,j+1,s1,s2,dp) + static_cast<int>(s2[j]);

        return dp[i][j] =  min(a1,a2);

    }
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp (s1.size()+1,vector<int>(s2.size()+1,0));
         // Base case: when s2 is exhausted
        int n = s1.size(), m = s2.size();
        for (int i = n - 1; i >= 0; i--) {
            dp[i][m] = dp[i + 1][m] + s1[i];
        }

        // Base case: when s1 is exhausted
        for (int j = m - 1; j >= 0; j--) {
            dp[n][j] = dp[n][j + 1] + s2[j];
        }
        for(int i=s1.size()-1;i>=0;i--){
            for(int j=s2.size()-1;j>=0;j--){
                if(s1[i]==s2[j]){
                    // no deletion reuired continue fwd both
                    dp[i][j] = dp[i+1][j+1];
                }
                else{
                    dp[i][j] = min( s1[i] + dp[i + 1][j],s2[j] + dp[i][j + 1]);
                }
            }
        }
        return dp[0][0];
    }   
};