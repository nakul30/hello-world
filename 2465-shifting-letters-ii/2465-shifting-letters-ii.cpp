class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> index(s.size(),0);
        
         // Applying the shifts using prefix sum technique
        for (auto& shift : shifts) {
            int start = shift[0], end = shift[1], direction = shift[2];
            if (direction == 1) {
                index[start] += 1;
                if(end+1<s.size()){
                   index[end + 1] -= 1;
                }
                
            } else {
                index[start] -= 1;
                if(end+1<s.size()){
                   index[end + 1] += 1;
                }
                
            }
        }


        for(int i=0;i<index.size();i++){
            cout << index[i] <<" ";
        }
        int cumulative_shift = 0;
        for (int i =0; i <s.size() ; i++) {
            cumulative_shift += index[i];
            int shift = (s[i] - 'a' + cumulative_shift) % 26;
            if (shift < 0) shift += 26;
            s[i] = 'a' + shift;
        }

        return s;
    }
};
// 0  1   2 
// -1 -1 
//     1  1 
// 1      1 
// 0    0 2   