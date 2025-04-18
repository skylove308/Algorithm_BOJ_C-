#include <bits/stdc++.h>
using namespace std;

static int N;
vector<vector<int>> bamboo;
vector<vector<int>> dp;
static vector<int> dx = {-1, 1, 0, 0};
static vector<int> dy = {0, 0, -1, 1};

int dfs(int x, int y){
    if(dp[x][y] != 0)
        return dp[x][y];

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx<0||ny<0||nx>=N||ny>=N)
            continue;

        if(bamboo[x][y] >= bamboo[nx][ny])
            continue;

        dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
    }
    return dp[x][y];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); 

    cin >> N;

    bamboo.resize(N, vector<int>(N));
    dp.resize(N, vector<int>(N));

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> bamboo[i][j];
        }
    }

    int maxBambooCnt = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            maxBambooCnt = max(maxBambooCnt, dfs(i, j) + 1);
        }
    }

    cout << maxBambooCnt << '\n';

}
