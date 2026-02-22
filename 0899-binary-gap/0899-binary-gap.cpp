class Solution {
public:
    int binaryGap(int n) {
        int currPos=-1,pairPos=-1;
        int index=0;
        int maxdiff=0;
        while(n){
            int quot = n/2;
            int remain=n%2;
            if(remain==1 && currPos==-1)currPos=index;
            else if(remain==1){
                pairPos=currPos;
                currPos=index; 
                maxdiff=max(maxdiff,abs(currPos-pairPos));

            }
                            n=quot;index++;

        }
        return maxdiff;
    }
};