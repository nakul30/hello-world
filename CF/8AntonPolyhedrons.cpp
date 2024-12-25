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

void solve()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (s == "Tetrahedron")
        {
            ans += 4;
        }
        else if (s == "Cube")
        {
            ans += 6;
        }
        else if (s == "Octahedron")
        {
            ans += 8;
        }
        else if (s == "Dodecahedron")
        {
            ans += 12;
        }
        else if (s == "Icosahedron")
        {
            ans += 20;
        }
    }
    cout << ans << endl;
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