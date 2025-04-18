#include <bits/stdc++.h>
using namespace std;

static int M, N;
static vector<vector<int>> factory;
static vector<vector<bool>> visited;
static pair<int, int> robotEndPos;
static int robotEndDir;
static int minMoveCnt = INT32_MAX;
static vector<int> dx = {0, 0, 0, 1, -1};
static vector<int> dy = {0, 1, -1, 0, 0};

struct Point{
    int x, y, d, moveCnt;
    Point(int _x, int _y, int _d, int _moveCnt){
        x = _x;
        y = _y;
        d = _d;
        moveCnt = _moveCnt;
    }
};

int dirChangeCnt(int curDir, int nextDir){
    if(curDir == 1){
        if(nextDir == 2) return 2;
        else return 1;
    }else if(curDir == 2){
        if(nextDir == 1) return 2;
        else return 1;
    }else if(curDir == 3){
        if(nextDir == 4) return 2;
        else return 1;
    }else{
        if(nextDir == 3) return 2;
        else return 1;
    }
}

void bfs(int x, int y, int d){
    queue<Point> RobotQueue;
    RobotQueue.push(Point(x, y, d, 0));
    while(!RobotQueue.empty()){
        Point p = RobotQueue.front();
        RobotQueue.pop();

        if(minMoveCnt <= p.moveCnt)
            continue;

        if(p.x == robotEndPos.first && p.y == robotEndPos.second){
            minMoveCnt = min(minMoveCnt, p.moveCnt + dirChangeCnt(p.d, robotEndDir));
            continue;
        }

        visited[p.x][p.y] = true;

        for(int i=1; i<=4; i++){
            for(int j=1; j<=3; j++){
                int nx = p.x + dx[i] * j;
                int ny = p.y + dy[i] * j;
        
                if(nx<=0 || ny<=0 || nx>M || ny>N || visited[nx][ny] || factory[nx][ny] == 1)
                    break;

                RobotQueue.push(Point(nx, ny, i, p.moveCnt + dirChangeCnt(p.d, i) + 1));
            }
        }
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); 

    cin >> M >> N;
    factory.resize(M+1, vector<int>(N+1));
    visited.resize(M+1, vector<bool>(N+1));
    for(int i=1; i<=M; i++){
        for(int j=1; j<=N; j++){
            cin >> factory[i][j];
        }
    }

    pair<int, int> robotStartPos;
    int robotStartDir;

    cin >> robotStartPos.first >> robotStartPos.second >> robotStartDir;
    cin >> robotEndPos.first >> robotEndPos.second >> robotEndDir;

    bfs(robotStartPos.first, robotStartPos.second, robotStartDir);

    cout << minMoveCnt << '\n';

}