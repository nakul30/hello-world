class Solution {
public:
    int maxScore(string s) {
        int cntOne=0;
        for(auto it:s){
            if(it=='1'){cntOne++;}
        }
        int temp=0;
        int ans=0;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='1'){temp++;}
            int zeroes= (i+1-temp);

            // if()
            ans=max(ans,zeroes+ cntOne-temp);
        }
        return ans;
    }
};