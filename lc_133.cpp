#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace  std;
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
typedef pair<int,int> pii;
class lc133{
public:
    Node* cloneGraph(Node *node){
        if(node== nullptr) return node;

        unordered_map<Node*,Node*> visited;

        queue<Node*> Q;
        Q.push(node);

        visited[node] = new Node(node->val);

        while(!Q.empty()) {

            auto v = Q.front();

            Q.pop();

            for(auto &n:v->neighbors){
                if(visited.find(n) == visited.end()){
                    visited[n] = new Node(n->val);
                    Q.push(n);
                }
                visited[v]->neighbors.push_back(visited[n]);
            }
        }
        return visited[node];
    }
};
int main(){

}