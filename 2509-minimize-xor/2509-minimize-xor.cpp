class Solution {
public:
    int minimizeXor(int num1, int num2) {
        
        int cnt = __builtin_popcount(num2);  
        int formulated = 0;

        for (int i = 31; i >= 0; i--) {
            if ((num1 & (1 << i)) && cnt > 0) {  
                formulated |= (1 << i);  
                cnt--;
            }
        }
        for (int i = 0; cnt > 0 && i < 32; i++) {
            if (!(formulated & (1 << i))) {  
                formulated |= (1 << i);
                cnt--;
            }
        }
        return formulated;
    }
};