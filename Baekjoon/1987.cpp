#include<iostream>
#include<algorithm>
#define MAX 20
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int row,col,ans;
char board[MAX][MAX];
bool visited[26]={false,};  // 알파벳을 방문하였는지 체크
void dfs(int x,int y,int cnt) {
    ans=max(ans,cnt);
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<0||nx>=row||ny<0||ny>=col){ // 보드판을 벗어나면 불가능
            continue;
        }
        if(visited[(int)board[nx][ny]-65]){  // 이미 방문한 알파벳이면 불가능
            continue;
        }
        // 가능한 경우이므로 백트래킹
        visited[(int)board[nx][ny]-65]=true; 
		dfs(nx,ny,cnt+1);
		visited[(int)board[nx][ny]-65]=false;
    }
}
int main() { 
	ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	cin>>row>>col;
    for(int i=0;i<row;i++){   // 보드 입력받기
        for(int j=0;j<col;j++){
            cin>>board[i][j];
        }
    }
    visited[(int)board[0][0]-65]=true; // 첫번째 칸 알파벳은 무조건 방문
    dfs(0,0,1);
    cout<<ans;
    return 0;
}


