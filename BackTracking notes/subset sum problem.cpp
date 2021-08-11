#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int N = 20;
int arr[N];
vector <int> soultion;
void solve(int lo , int hi , int x){
    if(lo>hi){
        if(x == 0){
            for(auto v : soultion){
                printf("%d ",v);
            }
            puts("\n-------------------");
        }
        return ;
    }
    //option - 1 Take the element
    //Do
    soultion.push_back(arr[lo]);
    //Recurse
    solve(lo + 1 , hi, x - arr[lo]);
    //Undo
    soultion.pop_back();

    //option - 2 Leave the element
    //Do
    //Recurse
    solve(lo + 1 , hi ,x);
    //Undo
}

int main() {
    int n , x;
    scanf("%d%d",&n,&x);
    for (int i = 0; i < n; ++i) {
        scanf("%d",arr+i);
    }
    solve(0,n-1,x);
    return 0;
}