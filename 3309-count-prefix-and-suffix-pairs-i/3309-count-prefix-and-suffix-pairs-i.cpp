class Solution {
public:
    bool isPreSuf(string a,string b){
        if(b.length()<a.length()){
            return false;
        }
        if(b.substr(0,a.length()) == a && b.substr(b.length()-a.length())==a){
            // cout << b.substr(0,a.length()) <<" " <<b.substr(b.length()-a.length());
            return true;
        }
        return false;
    }
    int countPrefixSuffixPairs(vector<string>&a) {
        int cnt=0;
        for(int i=0;i<a.size();i++){
            string w=a[i];
            for(int j=i+1;j<a.size();j++){
                if(isPreSuf(w,a[j])){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};