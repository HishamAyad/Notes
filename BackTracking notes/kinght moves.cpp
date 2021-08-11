#include <bits/stdc++.h>

using namespace std;
#define ll long long

string path;
int n,m ,rs , cs, re,ce;
int dr[] = {2,1,-1,-2};
int dc[] = {1,2,2,1};
string moves = "ABCD";

void solve(int r,int c){
    if(r == re && c == ce){
        cout<<path<<endl;
    }
    for(int i = 0 ;i < 4;++i){
        int nr = r + dr[i] , nc = c + dc[i];
        if(nr < n && nc <m){
            //DO
            path.push_back(moves[i]);
            //Recurse
            solve(nr,nc);
            //Undo
            path.pop_back();
        }
    }
}


int main() {
    cin>>n>>m>>rs>>cs>>re>>ce;
    solve(rs,re);
    return 0;
}