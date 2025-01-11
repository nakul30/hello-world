class Solution {
public:
    bool canConstruct(string s, int k) {
        unordered_map<char,int> mymap;
        for(int i=0;i<s.size();i++){
            mymap[s[i]]++;
        }
        int cntOdd=0;
        int cntEven=0;
        for(auto it:mymap){
            if(it.second%2!=0){cntOdd++; cntEven+= it.second/2;}
            else{
                cntEven += it.second/2;
            }
        }
        if(cntOdd>k)return false;
        if(cntEven>=k)return true;
        
        k=k-cntOdd; cntOdd=0;
        // if(k%2==0){
        //     if(cntEven*2>=k){
        //         return true;
        //     }
        //     else{
        //         return false;
        //     }
        // }
        // k is odd 
        if(cntEven*2>=k){
            return true;
        }
        return false;
    }
    // odd number of characters maximum 2 

};
// k=6
// joidan = 4 ---> 8 elements --->
