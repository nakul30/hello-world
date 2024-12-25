#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main(){
    long long n;
    cin >> n;
    long long ans = 0;
    vector<long long> digits;
    while(n){
        long long last = n % 10;
        n = n / 10;
        if(n==0 && last == 9){
            digits.push_back(9);
            break;
        }
        if(last >= 5){
            last = 9 - last;
        }
        digits.push_back(last);
    }

    for(long long i = digits.size() - 1; i >= 0; i--){
        ans = ans * 10 + digits[i];
    }
    
    cout << ans << endl;
    return 0;
}
