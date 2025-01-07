class Solution {
public:
    static bool custom(string a,string b){
        return a.length() <b.length();
    }
    bool isSubstring(string a,string b){
        for(int i=0;i<=b.length()-a.length();i++){
            if(b.substr(i,a.length()) == a){
                return true;
            }
        }
        return false;
    }
    vector<string> stringMatching(vector<string>& words) {
        sort(words.begin(),words.end(),custom);
        for(auto s:words){
            cout << s << " ";
        }
        vector<string>ans;
        for(int i=0;i<words.size();i++){
            string to = words[i];
            for(int j=i+1;j<words.size();j++){
                if(to.length()< words[j].length() && isSubstring(to,words[j])){
                    ans.push_back(to);
                    break;
                }
            }
        }
        return ans;
    }
};