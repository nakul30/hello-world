// class Solution {
// public:
//     bool isPalindrome(string s) {
//         int left = 0, right = s.length() - 1;
//         while (left < right) {
//             if (s[left] != s[right]) {
//                 return false;
//             }
//             left++;
//             right--;
//         }
//         return true;
//     }

//     string longestPalindromeRecursive(string s, int start, int end) {
//         if (start == end) {
//             return s.substr(start, 1);
//         }

//         if (isPalindrome(s.substr(start, end - start + 1))) {
//             return s.substr(start, end - start + 1);
//         }

//         string palindrome1 = longestPalindromeRecursive(s, start, end - 1);
//         string palindrome2 = longestPalindromeRecursive(s, start + 1, end);

//         return (palindrome1.length() > palindrome2.length()) ? palindrome1 : palindrome2;
//     }
//     string longestPalindrome(string s) {
//         if (s.empty()) {
//             return "";
//         }

//         return longestPalindromeRecursive(s, 0, s.length() - 1);
//     }
// };
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length() ; 
        vector<vector<int>>dp(n , vector<int>(n , 0 )) ;
        string answer = "" ; 
        int maxans = 0 ; 
        for( int diff = 0 ; diff < n ; diff++ ){
            for(int i=0,j=i+diff;i<n &&j<n;i++,j++){
                if(diff==0){
                    dp[i][j] = 1 ; 
                }
                else if( diff == 1 ){
                    if(s[i] == s[j]){
                        dp[i][j] = 2 ; 
                    }
                }
                else{
                    if(s[i] == s[j] && dp[i+1][j-1]){
                        dp[i][j] = 2 + dp[i+1][j-1] ; 
                    }
                }
                if( maxans < dp[i][j]){
                    maxans = j - i + 1 ;
                    answer = s.substr(i , j-i +1) ; 
                }
// 
            }
        } 
        return answer ;
    }
};