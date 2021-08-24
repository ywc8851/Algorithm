#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<stack>
#include<deque>
#include<tuple>
#define INF 987654321
#define ll long long
#define MAX 31
using namespace std; // build : ctrl+alt+c  , compile : ctrl+alt+r 
int board[MAX][MAX];
int visited[MAX][MAX];
int after[MAX][MAX];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

bool cmp_board(int n, int m){ // 배열을 비교
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] != after[i][j]) return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> after[i][j];
        }
    }
    bool inject = false; // BFS를 돌린적이 있는지 없는지 판별하는 변수
    for(int i = 0; i < n; i++){
    	if(inject) break; 
        for(int j = 0; j < m; j++){
            if(visited[i][j] || board[i][j] == after[i][j]) continue; // 같은 값이거나 방문한 적이 있으면 continue
            inject = true; 
            // BFS 
            queue<pair<int,int>> Q;
            Q.push({i,j});
            int key = board[i][j]; // 원래 board[i][j]의 값을 저장
            board[i][j] = after[i][j];
            visited[i][j] = 1;
            while(!Q.empty()){
                auto cur = Q.front(); 
                Q.pop();
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(board[nx][ny] != key || visited[nx][ny]) continue;
                    Q.push({nx,ny});
                    visited[nx][ny] = 1;
                    board[nx][ny] = after[i][j]; // 항체 전파 (값 변경)
                }
            }
        }
    }
    if(cmp_board(n,m)) cout << "YES"; // 결과와 같음
    else cout << "NO"; // 결과와 다름
    return 0;
}
