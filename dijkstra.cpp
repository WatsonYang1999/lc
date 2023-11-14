
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

typedef pair<int, int> pii;


unordered_map<int, vector<pii>> graph;
typedef vector<vector<pii>> Graph;
vector<int> dijkstra2(const Graph& graph, int start) {
    const int n = graph.size();
    vector<int> distances(n, INF);
    vector<bool> visited(n, false);

    distances[start] = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && (u == -1 || distances[j] < distances[u])) {
                u = j;
            }
        }

        visited[u] = true;

        for (const auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (distances[v] > distances[u] + weight) {
                distances[v] = distances[u] + weight;
            }
        }
    }

    return distances;
}
vector<int> dijkstra(int start){
    priority_queue<pii,vector<pii>,greater<>> pq;
    vector<int> dist(graph.size()+1,INT_MAX);

    dist[start] = 0;

    pq.push({0,start});

    while(!pq.empty()) {
        auto curr = pq.top();
        int curr_node = curr.second, curr_dist = curr.first;

        if(dist[curr_node]<curr_dist) {
            continue;
        }

        for(auto neighbor: graph[curr_node]){
            int neighbor_dist = neighbor.first;
            int neighbor_index=  neighbor.second;
            int alt_dist = curr_dist + neighbor_dist;
            if(alt_dist< dist[neighbor_index]){
                pq.push({alt_dist,neighbor_index});
                dist[neighbor_index] = alt_dist;
            }
        }
    }

    return dist;
}
void bellmanFord(const Graph& graph, int start, vector<int>& distances) {
    const int n = graph.size();
    const int INF = INT_MAX;

    distances[start] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int u = 0; u < n; u++) {
            for (const auto& v : graph[u]) {
                int neighbor = v.first;
                int weight = v.second;

                if (distances[u] != INF && distances[u] + weight < distances[neighbor]) {
                    distances[neighbor] = distances[u] + weight;
                }
            }
        }
    }

    // Check for negative cycles
    for (int u = 0; u < n; u++) {
        for (const auto& v : graph[u]) {
            int neighbor = v.first;
            int weight = v.second;

            if (distances[u] != INF && distances[u] + weight < distances[neighbor]) {
                cout << "Graph contains negative cycle" << endl;
                return;
            }
        }
    }
}
int main() {
    // Example Usage:
    graph = {
            {1, {{3, 2}, {4, 1}}},
            {2, {{1, 4}, {4, 3}}},
            {3, {{4, 4}}},
            {4, {}}
    };
    auto p1 = pii(1,2),p2 = pii(2,1);
    cout<< (p1<p2)<<endl;
    int start_node = 1;
    vector<int> distances = dijkstra(start_node);
    for (int node = 1; node <= graph.size(); node++) {
        cout << "Shortest distance from node " << start_node << " to node " << node << " is " << distances[node] << endl;
    }

    return 0;
}