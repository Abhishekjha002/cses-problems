#include <bits/stdc++.h>
using namespace std;

#define ll long long int


// Simple Floyd Wrashall Algo
/*
Reason because floyd warshal is multi source shortest path also
TC: o(N^3)
*/

void solve() {
    ll n,m,q;
    cin>>n>>m>>q;
    ll INF = 9223372036854775807;
    vector<vector<ll>> adjList(n+1, vector<ll>(n+1, INF));

    for(ll i=0;i<m;i++) {
        ll u, v, w;
        cin>>u>>v>>w;
        adjList[u][v] = min(adjList[u][v], w);
        adjList[v][u] = min(adjList[u][v], w);
    }

    for(ll i=1;i<=n;i++) {
        adjList[i][i] = 0;
    }


    for(int via=1;via<=n;via++) {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++)
                if(adjList[i][via] < INF && adjList[via][j] < INF)
                    adjList[i][j] = min(adjList[i][j], adjList[i][via]+adjList[via][j]);
        }
    }

    for(int i=1;i<=q;i++) {
        int u, v;
        cin>>u>>v;
        ll ans = adjList[u][v];
        if(ans == INF)
            cout<<-1;
        else 
            cout<<ans;
        cout<<"\n";
    }

}


int main() {
    solve();
    return 0;
}

