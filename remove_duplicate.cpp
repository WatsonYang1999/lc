//
// Created by 12574 on 2023/2/11.
//
#include <iostream>
#include <stack>
#include <vector>
#include <deque>
using namespace  std;
int remove(vector<int>& A,int n){
    int count = 0;
    for(int i = 1; i < n; i++){
        if(A[i] == A[i-1]) count++;
        else A[i-count] = A[i];

        for(auto i: A) cout<<i <<' ';
        cout<<endl;
    }
    return n-count;
}
int main(){
    deque<int> dq1;
    remove(nums,nums.size());
    return 0;
}