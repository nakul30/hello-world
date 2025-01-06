class Solution {
public:
    vector<int> minOperations(string boxes) {
        unordered_set<int>loc;
        for(int i=0;i<boxes.size();i++){
            if(boxes[i]=='1'){
                loc.insert(i);
            }
        }
        vector<int>answer;
        for(int i=0;i<boxes.size();i++){
            int ans=0;
            for(auto it:loc){
                ans +=abs(it-i);
            }
            answer.push_back(ans);
        }
        return answer;
        
    }
};