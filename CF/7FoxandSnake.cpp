# include <iostream>
# include <string>
# include <vector>
using namespace std;

template <typename T>
void printVector(vector<T> &v){
    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
    cout << endl;
}
template <typename T>
void printMatrix(vector<vector<T>> &v){
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout << v[i][j]<< " ";
        }
        cout << endl;
    }
}





void solve(){
    int n,m;
    cin >> n >> m;
    vector<vector<char>> v(n,vector<char>(m,'.'));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i%2==0){
                v[i][j]='#';
            }
            else{
                if(i%4==1 && j==m-1){
                    v[i][j]='#';
                }
                else if(i%4==3 && j==0){
                    v[i][j]='#';
                }
            }
        }
    }
    printMatrix(v);
    
}
int main(){
    long long t=1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}