class Solution {
public:
    string makeFancyString(string s) {
        int cnt=1;char re=s[0];
        cout << s[0] ;
        string ans="";
        ans+=s[0];
        for(int i=1;i<s.size();i++){
            if(s[i]==re){
                cnt++;
            }
            else{
                cnt=1;
                re=s[i];
            }
            if(cnt<3){
                ans+=s[i];
            }
        }
        return ans;
    }
};