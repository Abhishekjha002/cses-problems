#include <bits/stdc++.h>
using namespace std;

#define ll long long
const long long INF = 9223372036854775807;
/*
Think about brute force
All edge have two states
*/
void solve() {
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> edges;
    vector<vector<vector<ll>>> graph(n+1);
    for(ll i=0;i<m;i++) {
        ll u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
        graph[u].push_back({v,w});
    }


    /* 
    Here I maintain two states
    But question is why I need go maintain two states.
    Reason being because we have two state for each edges:
    1. Take same weight
    2. Take half weight
    */
    vector<vector<ll>> minDist(2, vector<ll>(n+1, INF));
    vector<vector<bool>> vis(2, vector<bool>(n+1, false));

    minDist[0][1] = 0;
    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;
    pq.push({0, 1, -1, 0, 0});
    bool flag = true;
    while(pq.size() != 0 && flag) {
        ll size = pq.size();
        while(size--) {
            vector<ll> rvtx = pq.top();
            pq.pop();
            if(vis[rvtx[4]][rvtx[1]])
                continue;
            vis[rvtx[4]][rvtx[1]] = true;
            minDist[rvtx[4]][rvtx[1]] = min(minDist[rvtx[4]][rvtx[1]], rvtx[0]);
            if(rvtx[1] == n) {
                flag = false;
                break;
            }
            for(ll i=0;i<graph[rvtx[1]].size();i++) {
                ll v = graph[rvtx[1]][i][0];
                ll w = graph[rvtx[1]][i][1];
                ll wsf1 = rvtx[0] + w;
                ll wsf2 = rvtx[0] + (w/2);

                if((rvtx[4] == 0) && (!vis[rvtx[4]][v]) && (wsf1 < minDist[rvtx[4]][v])) {
                    pq.push({wsf1, v, rvtx[1], w, 0});
                    pq.push({wsf2, v, rvtx[1], w/2, 1});
                }
                if((rvtx[4] == 1) && (!vis[rvtx[4]][v]) && wsf2 < minDist[rvtx[4]][v])
                    pq.push({wsf1, v, rvtx[1], w, 1});
            }
        }
    }
    cout<<min(minDist[0][n], minDist[1][n]);
}

int main() {
    solve();
    return 0;
}