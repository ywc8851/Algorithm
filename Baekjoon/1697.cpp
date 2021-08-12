#include<iostream>
#include<queue>
#include<algorithm>
#define MAX 100001
using namespace std;
int a,b;
bool visit[MAX];
queue<pair<int,int>>q;
int bfs(int a,int b){
	q.push(make_pair(a,0));
	visit[a]=true;
	// bfs
	while(!q.empty()){
		int x=q.front().first;
		int time=q.front().second;
		q.pop();
		if(x==b){ // 동생지점에 도착하면 이동횟수 출력
			return time;
		}
        /* 
        범위를 벗어나지 않고 방문하지 않았을 경우
        +1 -1 *2에대한 경우를 큐에 삽입
        */
		if(x+1<MAX && !visit[x+1]){ 
			q.push(make_pair(x+1,time+1)); 
			visit[x+1]=true;
		}
		if(x-1>=0 && !visit[x-1]){ 
			q.push(make_pair(x-1,time+1));
			visit[x-1]=true;
		}
		if(x*2<MAX && !visit[x*2]){
			q.push(make_pair(x*2,time+1));
			visit[x*2]=true;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>a>>b;

	cout<<bfs(a,b);
	return 0;
}
