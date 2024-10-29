class Solution {
public:
    int solve(vector<vector<int>>&grid, int i, int j, int prev,vector<vector<int>>&dp){
        if(j==grid[0].size()){
            return 0;
        }
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()){
            return 0;
        }
        if(prev != -1 && prev>=grid[i][j]){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        
        int a=solve(grid,i-1,j+1,grid[i][j],dp);
        int b=solve(grid,i,j+1,grid[i][j],dp);
        int c=solve(grid,i+1,j+1,grid[i][j],dp);

        return dp[i][j]=1+max(a,max(b,c));
    }
    
    int maxMoves(vector<vector<int>>& grid) {
        int ans=INT_MIN;
        // Remove unused variables x,y
        vector<vector<int>>dp(grid.size()+1,vector<int>(grid[0].size()+1,-1));
        for(int i=0; i<grid.size(); i++){
            int z=solve(grid,i,0,-1,dp);
            ans = max(ans, z);  
            cout << i << " " << z << endl; 
        }
        
        if(ans<0) return 0;
        return ans-1;
    }
};
