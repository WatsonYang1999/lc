#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class Solution502 {
    bool static cmp(pair<int,int> &p1,pair<int, int> &p2) {
        return p1.first>p2.first;
    }
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // greed is good: always find the highest profits if capital allowed
        int n = profits.size();
        vector<pair<int,int>> arr;
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(&cmp)> pq(&cmp);
        for(int i = 0 ;i<profits.size();i++) {
            arr.push_back({profits[i],capital[i]});
        }
        sort(arr.begin(),arr.end(),cmp);


        for(int i = 0 ;i<k;i++){
            for(int j = 0 ; j<n;j++){
                if(arr[j].second>w) continue;
                pq.push({profits[j],capital[j]});
            }
            if(!pq.empty()) {
                w+=pq.top().first;
                pq.pop();
            }
        }

        return w;

    }
};

int main(){

}