//
// Created by 12574 on 2023/4/27.
//
#include <vector>
#include <iostream>
#include <cstdio>
using namespace std;
class Solution {
public:
    vector<vector<int>> answer;
    vector<int> path;
    vector<bool> visited;
    void dfs(vector<vector<int>>& graph,int x,int n){
        cout<<x <<endl;
        visited[x] = true;
        if(x == n) {
            answer.push_back(path);
            return;
        }
        for(auto v:graph[x]){
            if(visited[v]) continue;
            cout << v<<endl;
            path.push_back(v);
            dfs(graph,v,n);
            path.pop_back();
        }
        visited[x] = false;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        visited = vector<bool>(n, false);

        dfs(graph,0,n-1);
        return answer;
    }
};
int main(){
    vector<vector<int>>graph = {{4,3,1},{3,2,4},{3},{4},{}};
    Solution s;


    for(auto p: s.allPathsSourceTarget(graph)){
        for(auto i:p) cout << i<<' ';
        cout<<endl;
    }
}