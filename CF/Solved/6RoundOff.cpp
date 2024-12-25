# include <iostream>
# include <string>
# include <vector>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int multiplier=1;
    vector<int> ans;
    while(n){
        int last=n%10;
        last=last*multiplier;
        if(last!=0){
            ans.push_back(last);
        }
        n/=10;
        multiplier*=10;
    }

    cout << ans.size() << endl;
    for(int i=ans.size()-1;i>=0;i--){
        cout << ans[i] << " ";
    }
}
int main(){
    long long t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}