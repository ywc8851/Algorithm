#include<iostream>
#include<algorithm>
using namespace std; 
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
bool visited[1000000]; // 6자리숫자 중복여부 확인
int ans;
int board[5][5];
void dfs(int x,int y,int cnt,int sum){
    if(cnt==5){ // 5번 이동완료하였을 때 
        if(visited[sum]==false){  // 중복된 숫자가 아니면
            visited[sum]=true; 
            ans++; // ans 값 1증가
        }
        return;
    }
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx >= 0 && ny >= 0 && nx < 5 && ny < 5){ // 보드판 안에 있는 칸
            dfs(nx,ny,cnt+1,sum*10+board[nx][ny]);
        }
                
    }
}
int main() { 
	ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>board[i][j];
        }
    }
    for(int i=0;i<5;i++){ // 모든 칸을 시작점으로하여 dfs
        for(int j=0;j<5;j++){
            dfs(i,j,0,board[i][j]);
        }
    }
    cout<<ans;
    return 0;
}


