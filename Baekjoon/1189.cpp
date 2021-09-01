#include <iostream>

using namespace std;

#define endl '\n'


int R, C, K;
char board[5][5];
bool isVisited[5][5];
int dy[4] = {+1, 0, 0, -1};
int dx[4] = {0, +1, -1, 0};

bool isValid(int y, int x) // 좌표가 board 를 벗어나지 않는지 판단
{
    return y >= 0 && y < R && x >= 0 && x < C;
}

int dfs(int cy, int cx, int dist){
// 현재 좌표에서 집까지 도착하는 경우중 거리가 K+1-dist 인 가짓수를 반환
// 현재 좌표 = (cy, cx), 현재 이동한 거리 = dist */
    
    if (dist == K) { // 현재 이동한 거리가 K 이면 
        // 현재 좌표가 집이면 1을 반환(가짓수 하나 찾음), 그렇지 않으면 0을 반환 
        return (board[cy][cx] == 'H') ? 1 : 0;
    }
    isVisited[cy][cx] = true;
    int ret = 0; /* 현재 좌표에서 출발하여 집으로 가는 거리가 K+1-dist 인 가짓수 */

    for (int i=0; i<4; i++) {
        int ny = cy + dy[i];
        int nx = cx + dx[i];
        /* 좌표가 유효하고, 방문되지 않았고, 이동불가칸이 아니면 */
        if (isValid(ny, nx) && not(isVisited[ny][nx]) && board[ny][nx] != 'T') {
            /* 그 칸으로 이동 */
            ret += dfs(ny, nx, dist+1);
        }
    }

    isVisited[cy][cx] = false;
    return ret;
}


int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> R >> C >> K;
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            cin >> board[i][j];
        }
    }
    board[0][C-1] = 'H'; // 도착지점

    // DFS 돌림 
    int ans = dfs(R-1, 0, 1);

    cout << ans << endl;
    return 0;
}

