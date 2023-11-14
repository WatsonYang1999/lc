#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <queue>
#include <unordered_map>
using namespace std;

bool is_sqrt(int n) {
    if (n < 0) return false;

    int root = int(sqrt(n));

    return root * root == n;
}

int main(){
    int n;
    cin >> n;
    vector<int> W(n+1);
    for(int i = 1;i<=n;i++) cin >> W[i];

    vector<pair<int,int>> E;
    vector<vector<int>> graph(n+1);
    unordered_map<int,pair<int,int>> map;
    int u,v;
    for(int i =0;i<n-1;i++) {
        cin >> u >> v;
        pair<int,int> p(u,v);
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);

        if(is_sqrt(W[u] * W[v])) {
            //available edge
            E.emplace_back(p);
            map[u] = p;
            map[v] = p;
        }

    }

    vector<bool> white(n,true);
    queue<int > leaves;
    for(int i =1 ;i <= n;i++) {
        if(graph[i].size() == 1) {
            if (is_sqrt(W[i] * W[graph[i][0]]))
                leaves.push(i);
        }
    }


    int red_count = 0;
    // the proper condition
    while(!map.empty()) {
        // get leave edge
        pair<int,int> e;
        int leaf = leaves.front();
        int adj = graph[leaf][0];

        // paint
        red_count += 2;
        white[leaf] = false;
        white[adj] = false;
        auto it = map.find(leaf);
        map.erase(leaf);
        it = map.find(adj);
        map.erase(adj);
        // remove
        leaves.pop();
        graph[leaf].clear();
        // no duplicate value in adj list , so this is OK
        remove(graph[adj].begin(), graph[adj].end(),leaf);
        if(graph[adj].size()==1) {
            int adj_adj = graph[adj][0];
            remove(graph[adj_adj].begin(),graph[adj_adj].end(),adj);
            if (graph[adj_adj].size() == 1) {
                leaves.push(adj_adj);
            }
        }

    }
    cout << red_count << endl;

}