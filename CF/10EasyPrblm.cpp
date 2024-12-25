#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>

using namespace std;

template <typename T>
void printVector(vector<T> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
template <typename T>
void printMatrix(vector<vector<T>> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}
template <typename T>
void inputVector(vector<T> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cin >> v[i];
    }
}

void solve()
{
    int n;
    bool easy=true;
    cin >> n;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x==1){
            easy=false;
        }
    }
    if(easy){
        cout<<"EASY"<<endl;
    }else{
        cout<<"HARD"<<endl;
    }
}
int main()
{
    long long t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}