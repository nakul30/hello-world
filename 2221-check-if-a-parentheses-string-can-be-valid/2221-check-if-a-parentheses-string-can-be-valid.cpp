class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.length() % 2 != 0) return false; // Odd length can't be valid

        int open = 0, close = 0;

        for(int i = 0; i < s.length(); i++) {
            if(locked[i] == '1') {
                if(s[i] == '(') open++;
                else close++;
            } else {
                open++;  // unlocked can be used as '('
            }
            if(close > open) return false;
        }

        open = close = 0;
        for(int i = s.length() - 1; i >= 0; i--) {
            if(locked[i] == '1') {
                if(s[i] == ')') close++;
                else open++;
            } else {
                close++;  // unlocked can be used as ')'
            }
            if(open > close) return false;
        }
        return true;
    }
};
