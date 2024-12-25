# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
using namespace std;

void solve(){
    int a,b,c;
    cin >> a >> b >> c;
    int median;
    vector<int> v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    sort(v.begin(),v.end());
    median=v[1];
    cout << abs(a-median)+abs(b-median)+abs(c-median);
}
int main(){
    solve();
    return 0;
}