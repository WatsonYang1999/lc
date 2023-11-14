#include <iostream>
#include<unordered_set>
#include<vector>
using namespace std;
class Solution {
private:
    vector<int> parent;
    vector<int> rank;
public:
    int find(int x){
        if(parent[x]!=x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void union_find(int x, int y){
        int root_x = find(x);
        int root_y = find(y);

        if(rank[root_x]<rank[root_y])
        {
            parent[root_x] = root_y;
        }
        else if(rank[root_x]<rank[root_y]){
            parent[root_y] = root_x;
        }
        else{
            parent[root_y] = root_x;
            rank[root_x]++;
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        //initialize union find
        parent = vector<int>(n);
        rank = vector<int>(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
            rank[i] = 0;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]) union_find(i,j);
            }
        }

        unordered_set<int> provinces;

        for(int i=0;i<n;i++){
            provinces.insert(find(i));
        }
        return provinces.size();
    }
};

int main(){

}