class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        }

        while(k--){
            pair<int,int> top=pq.top();
            pq.pop();
            pq.push({top.first*multiplier,top.second});
        }

        vector<int>ans(nums.size());
        while(!pq.empty()){
            pair<int,int>top=pq.top();
            pq.pop();
            ans[top.second]=top.first;

        }
        return ans;
    }
};