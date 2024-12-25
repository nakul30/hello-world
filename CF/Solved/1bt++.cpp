#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    int var= 0;
    for(int i=0;i<n;i++){
        string temp;
        cin >> temp;
        if(temp=="X++" || temp == "++X"){
            var++;
        }
        else if(temp=="X--" || temp == "--X"){
            var--;
        }
    }
    cout << var << endl;
    
}