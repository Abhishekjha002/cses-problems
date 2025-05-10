#include <bits/stdc++.h>
using namespace std;
 

// Simple Dijkstra Algo

void solve() {
    long long int n, m;
    cin>>n>>m;
    vector<vector<vector<long long int>>> graph(n+1, vector<vector<long long int>>());
    
    for(long long int i=0;i<m;i++) {
        long long int u, v, w;
        cin>>u>>v>>w;
        graph[u].push_back({v, w});
    }
 
    priority_queue<vector<long long int>, vector<vector<long long int>>, greater<vector<long long int>>> pq;
    vector<bool> vis(n+1, false);
    pq.push({0, 1});
    vector<long long int> minDist(n+1, 9223372036854775800);
 
    while(pq.size() != 0) {
        long long int size = pq.size();
        while(size--) {
            vector<long long int> rvtx = pq.top();
            pq.pop();
            if(vis[rvtx[1]])
                continue;
            vis[rvtx[1]] = true;
            minDist[rvtx[1]] = min(minDist[rvtx[1]], rvtx[0]);
            for(long long int i=0;i<graph[rvtx[1]].size();i++) {
                long long int u = graph[rvtx[1]][i][0];
                long long int w = graph[rvtx[1]][i][1];
                if(!vis[u]) {
                    pq.push({rvtx[0]+w, u});
                }
            }
        }
    }
 
    for(long long int i=1;i<=n;i++)
        cout<<minDist[i]<<" ";
 
}
 
int main() {
    solve();
    return 0;
}