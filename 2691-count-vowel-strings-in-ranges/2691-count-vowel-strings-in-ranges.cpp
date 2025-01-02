class Solution {
public:
    bool isVowel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
            return true;
        }
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int>cnt;
        int sum=0;
        cnt.push_back(sum);
        for(int i=0;i<words.size();i++){
            string stringi=words[i];
            if(isVowel(stringi[0]) && isVowel(stringi.back())){
                sum++;
            }
            cnt.push_back(sum);
        }
        for(int i=0;i<cnt.size();i++){
            cout << cnt[i] << " "; 
        }
    
        vector<int>answer;
        for(int i=0;i<queries.size();i++){
            int temp=cnt[queries[i][1]+1]-cnt[queries[i][0]];
            answer.push_back(temp);
        }
        return answer;

    }
};