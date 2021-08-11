#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int N = 20;
char gird[N][N];
string path;
int n,m;
void solve(int r,int c){
    if(r == n-1 && c == m-1){
        cout<<path<<endl;
    }
    // option 1 - Right
    if(c+1 < m && gird[r][c+1]!='#'){
        //Do
        path.push_back('R');
        //Recurse
        solve(r,c+1);
        //Undo
        path.pop_back();
    }
    //option 2 - Down
    if(r+1 <n &&gird[r+1][c] != '#'){
        //Do
        path.push_back('D');
        //Recurse
        solve(r+1,c);
        //Undo
        path.pop_back();
    }
}

int main() {
    cin>>n>>m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin>>gird[i][j];
        }
    }
    solve(0,0);
    return 0;
}