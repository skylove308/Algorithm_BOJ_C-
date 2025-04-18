#include <bits/stdc++.h>
using namespace std;
 
static int N, M;
static vector<vector<int>> board;
static vector<vector<int>> dp;
static vector<int> dx = {-1, 1, 0, 0};
static vector<int> dy = {0, 0, -1, 1};
static int ans = 0;

int dfs(int x, int y, vector<vector<bool>> visited){
    if(ans == -1)
        return 0;

    if(dp[x][y] != 0) 
        return dp[x][y];

    int curMovecnt = dp[x][y];
    for(int i=0; i<4; i++){
        int nx = x + dx[i] * board[x][y];
        int ny = y + dy[i] * board[x][y];

        if(nx<0||ny<0||nx>=N||ny>=M||board[nx][ny]==-1)
            continue;
        if(visited[nx][ny]){
            ans = -1;
            return 0;
        }
        visited[nx][ny] = true;
        dp[x][y] = max(dp[x][y], curMovecnt + dfs(nx, ny, visited));
        visited[nx][ny] = false;
    }
    dp[x][y] += 1;
    return dp[x][y];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); 

    cin >> N >> M;
    board.resize(N, vector<int>(M));
    dp.resize(N, vector<int>(M));

    for(int i=0; i<N; i++){
        string line;
        cin >> line;
        for(int j=0; j<M; j++){
            if(line[j] == 'H'){
                board[i][j] = -1;
            }else{
                board[i][j] = line[j] - '0';
            }
        }
    }

    vector<vector<bool>> visited(N, vector<bool>(M));
    int result = dfs(0, 0, visited);
    if(ans == -1){
        cout << -1 << '\n';
    }else{
        cout << result << '\n';
    }

    return 0;
}
