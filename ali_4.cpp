//
// Created by 12574 on 2023/10/14.
//
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 10e9+7;

int solve(int n,int m){

    if(m<=0) return 0;
    if(n<=1) return n;

    long long sum = 0;

    for(int i=0;i<=n-1;i++){
        sum += solve(i,m-1) + solve(n-i-1,m-1);
    }
    vector<vector<int>> sol(n+1,vector<int>(m+1,0));
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            
        }
    }
    return sum%MOD;
}
int main() {
    int n, m;
    //cin >> n >> m;
    n = 3,m=3;
    cout << solve(n,m)<<endl;
    return 0;
}