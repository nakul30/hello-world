#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    n = 5;
    m = 5;
    int row=-1,col=-1;
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int temp;
            cin >> temp;
            matrix[i][j] = temp;
            if(temp==1){
                row=i;col=j;
            }
        }
    }
    cout<<abs(row-2)+abs(col-2)<<endl;
}