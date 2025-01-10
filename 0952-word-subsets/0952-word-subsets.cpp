class Solution {
public:

    bool issubset(vector<int>length,vector<int>particular){
        for(int i=0;i<26;i++){
            if(length[i]>particular[i]){
                return false;
            }
        }
        return true;
    }
    void Subsetreturn(vector<int>&length,vector<int>len2){
        // vector<int> ans(26,0);
        for(int i=0;i<26;i++){
            length[i]=max(length[i],len2[i]);
        }
        return;

    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2){
        vector<int>length(26,0);
        for(int i=0;i<words2.size();i++){
            vector<int>created(26,0);
            for(int j=0;j<words2[i].length();j++){
                created[words2[i][j]-'a']++;
            }
            Subsetreturn(length,created);
        }
        vector<string>answer;
        for(int i=0;i<words1.size();i++){
            vector<int>created(26,0);
            for(int j=0;j<words1[i].length();j++){
                created[words1[i][j]-'a']++;
            }
            if(issubset(length,created)){
                answer.push_back(words1[i]);
            }
        }
        return answer;
    }
};