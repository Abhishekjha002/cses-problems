#include<bits/stdc++.h>
using namespace std;

#define ll long long
const long long INF = 9223372036854775807;

bool dfs(int src, vector<bool>& vis, vector<vector<ll>>& graph, int destination) {
    if(src == destination)
        return true;
    vis[src] = true;
    bool ans = false;
    for(int neigh: graph[src]) {
        if(vis[neigh])
            continue;
        ans = ans || dfs(neigh, vis, graph, destination);
    }
    return ans;
}

// Use belmann ford with dfs to find destination is part of a cycle node.

void solve() {
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> edges;
    vector<vector<ll>> graph(n+1, vector<ll>());
    for(ll i=0;i<m;i++) {
        ll u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u, v, w});
        graph[u].push_back(v);
    }

    vector<ll> max_dist(n+1, -INF);
    max_dist[1] = 0;

    for(int i=1;i<n;i++) {
        for(int j=0;j<m;j++) {
            ll u = edges[j][0];
            ll v = edges[j][1];
            ll w = edges[j][2];
            if(max_dist[u] != -INF && max_dist[u] + w > max_dist[v])
                max_dist[v] = max_dist[u] + w;
        }
    }

    vector<bool> vis(n+1, false);
    for(int j=0;j<m;j++) {
        ll u = edges[j][0];
        ll v = edges[j][1];
        ll w = edges[j][2];
        if(max_dist[u] != -INF && max_dist[u] + w > max_dist[v]) {
            if(dfs(u, vis, graph, n)) {
                /*
                *******************  IMPORTANT
                When you find the maximum weight after n-1 iteration then there must be a +ve cycle
                and to find whether it is a part of your destination. Simply, apply dfs to find it.
                */
                cout<<-1;
                return;
            }
        }
    }
    cout<<max_dist[n];
}


int main() {
    solve();
    return 0;
}
