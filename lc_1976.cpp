//
// Created by 12574 on 2023/4/27.
//
#include <vector>
#include <iostream>
using namespace std;
typedef pair<int,int> pii;
class Solution_1976 {
public:
    vector<vector<int>> answer;
    vector<int> path;
    vector<bool> visited;
    int count = 0;
    int curr_cost =0;
    int min_cost = INT_MAX;

    void dfs(vector<vector<pii>> &adj_list,int x,int n,int new_cost){
        curr_cost+=new_cost;
        visited[x] = true;
        path.push_back(x);
        if(x == n) {
            // reset
            if(curr_cost<min_cost){
                min_cost = curr_cost;
                count = 1;
            }
            else if(curr_cost == min_cost){
                count++;
            }
            for(auto i :path) cout<<i<<' ';
            cout<<endl;
            visited[x] = false;
            path.pop_back();
            return;
        }
        for(auto e:adj_list[x]){
            int v_next = e.first;
            int cost = e.second;
            if(visited[v_next]||curr_cost+cost>min_cost) continue;

            dfs(adj_list,v_next,n,cost);

        }
        visited[x] = false;
        path.pop_back();
        curr_cost-=new_cost;
    }
    int countPaths(int n, vector<vector<int>>& roads) {
        visited = vector<bool>(roads.size(), false);
        vector<vector<int>> graph = vector<vector<int>>(n,vector<int>(n,0));
        vector<vector<int>> time = vector<vector<int>>(n,vector<int>(n,0));
        vector<vector<pii>> adj_list = vector<vector<pii>>(n,vector<pii>());
        for(auto& e: roads){
            int v1 = e[0],v2 = e[1],t= e[2];
            adj_list[v1].emplace_back(v2,t);
            adj_list[v2].emplace_back(v1,t);
        }
        dfs(adj_list,0,n-1,0);

        return count%(10^9+7);
    }
};