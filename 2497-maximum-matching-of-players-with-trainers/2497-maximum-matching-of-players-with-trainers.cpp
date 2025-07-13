class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        priority_queue<int> play, train;
        for(int i=0;i<players.size();i++){
            play.push(players[i]);
        }
        for(int i=0;i<trainers.size();i++){
            train.push(trainers[i]);
        }
        int match=0;
        while (!play.empty() && !train.empty())
        {
            if(play.top()<= train.top()){
                match++;
                play.pop();train.pop();
            }
            else if(play.top()>train.top()){
                play.pop();
            }
        }
        return match;
    }
};