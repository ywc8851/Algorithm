#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define MAX 100
int n,m,ans;
int arr[MAX][MAX];
int visit[MAX][MAX]={false,};
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
using namespace std;

int bfs(int a,int b,int cnt){
    queue <pair<pair<int,int>,int>> q;
    q.push(make_pair(make_pair(a,b),cnt));
  
    while(!q.empty()){
        int x=q.front().first.first;
        int y=q.front().first.second;
        int cnt=q.front().second;
        q.pop();
      
        if(x==n-1&&y==m-1){
            return cnt;
        }
      
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0||nx>n-1||ny<0||ny>m-1){
                continue;
            }
            if (arr[nx][ny] == 1 && !visit[nx][ny]) {
			    	  visit[nx][ny] = true;
				      q.push(make_pair(make_pair(nx, ny), cnt + 1));
		    	  }
        }   
    }
} 
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin.tie(0);
    cin>>n>>m;
    for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++)	{
            arr[i][j] = str[j] - '0';
        }
	}
    visit[0][0]=true;
    cout<<bfs(0,0,1);
    return 0;
}
