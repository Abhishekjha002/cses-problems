#include <bits/stdc++.h>
using namespace std;
 
vector<int> bfs(vector<vector<int>>& graph, int n) {
    vector<int> parent(n + 1, -1);  // to track the path
    vector<bool> vis(n + 1, false);
    queue<int> que;
    que.push(1);
    vis[1] = true;
 
    while(!que.empty()) {
        int node = que.front();
        que.pop();
        
        // If we've reached Maija's computer (node n)
        if(node == n) {
            vector<int> path;
            for(int cur = n; cur != -1; cur = parent[cur]) {
                path.push_back(cur);
            }
            reverse(path.begin(), path.end());  // reverse to get the path from 1 to n
            return path;
        }
 
        for(int neighbor : graph[node]) {
            if(!vis[neighbor]) {
                vis[neighbor] = true;
                parent[neighbor] = node;  // track the parent of each node
                que.push(neighbor);
            }
        }
    }
 
    return {};  // return empty path if there's no way to reach node n
}
 
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
 
    vector<int> path = bfs(graph, n);
    if(path.empty()) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << path.size() << endl;
        for(int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }
 
    return 0;
}