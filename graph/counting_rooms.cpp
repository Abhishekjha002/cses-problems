#include <bits/stdc++.h>
using namespace std;
 
 
int dirN[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
 
bool isValid(int row, int col, vector<vector<char>>& matrix) {
    if(row < 0 || col < 0 || row >= matrix.size() || col >= matrix[0].size() || matrix[row][col] == '#')
        return false;
    return true;
}
 
 
void dfs(int i, int j, vector<vector<char>>& matrix) {
    matrix[i][j] = '#';
    for(int d=0;d<4;d++) {
        int nX = i + dirN[d][0];
        int nY = j + dirN[d][1];
        if(isValid(nX, nY, matrix))
            dfs(nX, nY, matrix);
    }
}
 
void helper() {
    int n, m;
    cin>>n>>m;
 
    vector<vector<char>> matrix(n, vector<char>(m, '#'));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++)
            cin>>matrix[i][j];
    }
 
    // Simple using get connected components
    int countRooms = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(matrix[i][j] == '.') {
                dfs(i, j, matrix);
                countRooms += 1;
            }
        }
    }
    cout<<countRooms<<"\n";
}

int main() {
    helper();
}