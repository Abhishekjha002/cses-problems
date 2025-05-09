#include <bits/stdc++.h>
using namespace std;
 
 
int dirN[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
char dir[4] = {'U', 'D', 'L', 'R'};
 
bool isValid(int row, int col, vector<vector<char>>& matrix, vector<vector<bool>>& vis) {
    if(row < 0 || col < 0 || row >= matrix.size() || col >= matrix[0].size() || matrix[row][col] == '#' || vis[row][col])
        return false;
    return true;
}

// Simple BFS with efficient way of storing path as well.

string bfs(int si, int sj, int ei, int ej, vector<vector<char>>& matrix, vector<vector<bool>>& vis) {
    int n = matrix.size();
    int m = matrix[0].size();

    // Created Two Array where parent[i][j] store the coordinates to reach (i,j)
    vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m));
    // Store the move taken to come to position (i,j)
    vector<vector<char>> move(n, vector<char>(m));

    queue<pair<int, int>> que;
    que.push({si,sj});
    vis[si][sj] = true;
 
    bool found = false;

    while(que.size() != 0) {
        int size = que.size();
        while(size--) {
            pair<int, int> rvtx = que.front();
            que.pop();
            if((rvtx.first == ei) && (rvtx.second == ej)) {
                found = true;
                break;
            }
            for(int d=0;d<4;d++) {
                int newX = rvtx.first + dirN[d][0];
                int newY = rvtx.second + dirN[d][1];
                if(isValid(newX, newY, matrix, vis)) {
                    vis[newX][newY] = true;
                    parent[newX][newY] = {rvtx.first, rvtx.second};
                    move[newX][newY] = dir[d];
                    que.push({newX, newY});
                }
            }
        }
        if(found)
            break;
    }

    if(!found)
        return "";
    string path = "";
    int ci = ei, cj = ej;
    while(ci != si || cj != sj) {
        path += move[ci][cj];
        int x = parent[ci][cj].first;
        int y = parent[ci][cj].second;
        ci = x;
        cj = y;
    }
    reverse(path.begin(), path.end());
    return path;
}
 
 
void helper() {
    int n, m;
    cin>>n>>m;
 
    vector<vector<char>> matrix(n, vector<char>(m, '#'));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++)
            cin>>matrix[i][j];
    }
    int si = -1, sj = -1;
    int ei = -1, ej = -1;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(matrix[i][j] == 'A') {
                si = i;
                sj = j;
            }
            if(matrix[i][j] == 'B') {
                ei = i;
                ej = j;
            }
        }
    }
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    string ans = bfs(si, sj, ei, ej, matrix, vis);
    if(ans.size() == 0)
        cout<<"NO";
    else {
        cout<<"YES\n";
        cout<<ans.size()<<"\n";
        cout<<ans;
    }
}
int main() {
    helper();
}