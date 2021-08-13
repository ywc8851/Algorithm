#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define MAX 1001
using namespace std; 
int n,m,final_x,final_y,x,y;
int board[MAX][MAX];
int ans[MAX][MAX];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
bool visited[MAX][MAX];
queue<pair<int,int>> q;

int main() { 
	ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
            if(board[i][j]==2){
                final_x=i; // 목표지점 x좌표
                final_y=j; // 목표지점 y좌표
                visited[i][j]=true; // 목표지점은 방문상태
                ans[i][j]=0; 
            }
        }
    }
    q.push(make_pair(final_x,final_y)); // 목표지점에서부터 탐색시작
    while(!q.empty()){
        x=q.front().first;
        y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 보드판 벗어나는 경우 X
			if (board[nx][ny] == 0) continue; // 지나갈 수 없는 길인 경우 X
			if (visited[nx][ny]) continue; // 방문했던 길인 경우 X
            q.push(make_pair(nx,ny));
            visited[nx][ny]=true;
            ans[nx][ny]=ans[x][y]+1; 
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(ans[i][j]==0&&board[i][j]==1){ // 지나갈 수 있는 경우인데 경로가 없는경우 -1출력
                cout<<"-1"<<" ";
            }
            else {
                cout<<ans[i][j]<<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
}


