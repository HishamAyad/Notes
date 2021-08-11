#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int N = 20;
char gird[N][N];
int n , no ;
void printSolution(){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout<<gird[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"--------------------\n";
}
/*
bool isVaild(int r,int c){
    for(int i = 0 ;i < r ;++i){
        if(gird[i][c]=='Q') return false;
    }
    for(int d = 0 ; r - d >= 0 && c + d < n ; ++d){
        if(gird[r-d][c+d] == 'Q') return false;
    }
    for(int d = 0 ; r - d >= 0 && c - d >= 0 ; ++d){
        if(gird[r-d][c-d] == 'Q') return false;
    }
    return true;
} */
bool C[N];
unordered_map<int,bool> D1 , D2;
bool isVaild(int r,int c){
    if(C[c] == true){
        return false;
    }
    if(D2[r+c] == true){
        return false;
    }
    if(D1[r-c] == true){
        return false;
    }
    return true;
}

void solve(int r){
    if(r == n){
        printSolution();
        no++;
        return;
    }
    for(int c = 0 ; c < n ;++c){
        if(isVaild(r,c)){ // for each vaild option
            //Do
            gird[r][c] = 'Q';
            C[c] = D1[r-c] = D2[r+c] = true;
            //Recure
            solve(r+1);
            //Undo
            gird[r][c] = '#';
            C[c] = D1[r-c] = D2[r+c] = false;
        }
    }
}
int main() {
    freopen("outputx.txt","w",stdout);
    cin>>n;
    for(int i = 0 ; i<n;++i){
        for (int j = 0; j < n; ++j) {
            gird[i][j] = '#';
        }
    }
    solve(0);
    cout<<no<<endl;
    return 0;
}