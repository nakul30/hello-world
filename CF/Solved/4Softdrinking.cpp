# include <iostream>
# include <string>
# include <vector>
using namespace std;

void solve(){
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;

    cout << min(min((k*l)/nl, c*d), p/np)/n << endl;
}

int main(){
    solve();
    return 0;
}