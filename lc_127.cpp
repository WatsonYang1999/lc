//
// Created by 12574 on 2023/9/24.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
using namespace std;

class Solution {
private:
    int wordDistance(string s1,string s2){
        if(s1.size()!=s2.size()) return -1;
        int dis  = 0;
        for(int i = 0;i<s1.size();i++){
            if(s1[i]!=s2[i]) dis++;
        }
        return dis;
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // check if beginWord is in the wordList
        int n = wordList.size();
        int source = n;
        auto it = find(wordList.begin(),wordList.end(),beginWord);
        if(it != wordList.end()){
            //beginWord in the wordList
            source = it - wordList.begin();
        }
        else{
            //beginWord not in the wordList
            wordList.push_back(beginWord);
            n++;
        }
        it = find(wordList.begin(),wordList.end(),endWord);
        int destiny = it - wordList.begin();
        vector<vector<int>> graph(n,vector<int>(n,0));
        vector<vector<int>> adjList(n,vector<int>());
        for (int i = 0; i < n; ++i) {
            for(int j = 0;j<n;j++) {
                if (wordDistance(wordList[i],wordList[j]) == 1){
                    graph[i][j] = 1;
                    adjList[i].emplace_back(j);
                }
            }
        }
        //implement BFS algorithm
        vector<int> dist(n,-1);
        dist[source] = 0;

        queue<int> q;
        set<int> vis;
        q.push(source);
        while (!q.empty()) {
            int curr = q.front();

            q.pop();

            for(auto neighbor: adjList[curr]) {
                if(vis.find(neighbor) == vis.end()){
                    vis.insert(neighbor);
                    dist[neighbor] = dist[curr]+1;
                    q.push(neighbor);
                    cout<<wordList[neighbor]<<endl;
                }
            }
        }

        return dist[destiny]+1;
    }
};

int main(){
    string begin = "hit";
    string end = "cog";
    vector<string> words = {"hot","dot","dog","lot","log","cog"};
    auto solution = new Solution();
    cout << solution->ladderLength(begin,end,words)<<endl;
    return  0 ;
}