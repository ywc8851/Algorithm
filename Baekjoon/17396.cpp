#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define MAX 100000
#define ll long long
using namespace std; 

bool can[MAX] = {false};
bool visit[MAX]={false};
ll INF=1000000000000;
ll dp[MAX];
vector<pair<ll,int>> v[MAX];
priority_queue<pair<ll,int>> pq;
pair<ll,int> p;

int main(){
	  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int a;
	      cin >> a;
		    if (a == 0) can[i] = true;
    }
    can[n-1] = true; // 마지막점은 갈 수 있음
  
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        if (!can[a] || !can[b]) continue; // 어차피 갈 수 없는 경로
        v[a].push_back(make_pair(c,b));
        v[b].push_back(make_pair(c,a));
        if(a==0) dp[b]=c;
        if(b==0) dp[a]=c;
    }
    for(int i=1;i<n;i++){
        if(dp[i]==0) dp[i]=INF;
    }
    // 다익스트라 알고리즘
    for(int i=0;i<v[0].size();i++){
        pq.push(make_pair(-v[0][i].first,v[0][i].second)); // 최소힙
    }
    while(!pq.empty()){
        p=pq.top();
        pq.pop();
        if(!visit[p.second]){
            visit[p.second]=true;
            for(int i=0;i<v[p.second].size();i++){
                if (dp[v[p.second][i].second] > dp[p.second] + v[p.second][i].first) {
				        	dp[v[p.second][i].second] = dp[p.second] + v[p.second][i].first; // 현재 점을 거쳐서가는게 최소경로인 경우
				        	pq.push(make_pair(-dp[v[p.second][i].second], v[p.second][i].second));
			  	      }
            }
        }
    }
    if (dp[n - 1] == INF) cout << "-1\n"; // 불가능한 경우
	  else
		cout << dp[n - 1] << "\n";

	  return 0;
}



