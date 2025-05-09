#include <bits/stdc++.h>
using namespace std;

// Simple DFS GCC and take each verticces from where GCC starts

void dfs(int src, vector<vector<int>>& graph, vector<bool>& vis) {
    vis[src] = true;
    for(int i=0;i<graph[src].size();i++) {
        if(!vis[graph[src][i]])
            dfs(graph[src][i], graph, vis);
    }
}


int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n+1, vector<int>());
    for(int i=0;i<m;i++) {
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
 
    vector<bool> vis(n+1, false);
    vector<vector<int>> edges;
 
    int u = -1, v = -1;
    int count = 0;
    for(int i=1;i<=n;i++) {
        if(!vis[i]) {
            count += 1;
            dfs(i, graph, vis);
            if(u == -1) {
                u = i;
            }
            else {
                edges.push_back({u, i});
            }
        }
    }
 
    cout<<count-1<<"\n";
    for(int i=0;i<edges.size();i++) {
        cout<<edges[i][0]<<" "<<edges[i][1]<<"\n";
    }
}