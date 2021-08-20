#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define MAX 801
#define INF 987654321
using namespace std; 
int N, E, A, B, ans;
int Dist[MAX];
bool Flag1=true, Flag2=true;
vector<pair<int, int>> V[MAX];

void init(){ // 거리 초기화
    for (int i = 1; i <= N; i++) Dist[i] = INF;
}

void Dijkstra(int Start){
    priority_queue<pair<int, int>> pq;
    Dist[Start] = 0;
    pq.push(make_pair(0, Start));
 
    while (pq.empty() == 0)
    {
        int Cost = -pq.top().first;
        int Cur = pq.top().second;
        pq.pop();
 
        for (int i = 0; i < V[Cur].size(); i++) // cur과 인접한 모든 정점 체크
        {
            int Next = V[Cur][i].first;
            int nCost = V[Cur][i].second;
 
            if (Dist[Next] > Cost + nCost)
            {
                Dist[Next] = Cost + nCost; // 최단경로 갱신
                pq.push(make_pair(-Dist[Next], Next)); // -Dist[Next] 값 : 최소힙을위해
            }
        }
    }
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> E;
    for (int i = 0; i < E; i++){
        int a, b, c; 
        cin >> a >> b >> c;
        V[a].push_back(make_pair(b, c));
        V[b].push_back(make_pair(a, c));
    }
    cin >> A >> B; // 반드시 거쳐야 하는 두 정점
 
    init();
    Dijkstra(1); // 시작점 : 1번정점
    int Route1 = Dist[A]; // 1 ~ A 최단거리
    int Route2 = Dist[B]; // 1 ~ B 최단거리
    if (Route1 == INF) Flag1 = false; // 시작점에서 정점 A까지 갈 수 없는 경우
    if (Route2 == INF) Flag2 = false; // 시작점에서 정점 B까지 갈 수 없는 경우
 
    init();
    Dijkstra(A); // 시작점 : 정점 A
    if (Flag1 == true) Route1 = Route1 + Dist[B]; // 1 ~ A + A ~ B 의 최단거리
    if (Flag2 == true) Route2 = Route2 + Dist[B]; // 1 ~ B + B ~ A 의 최단거리 
 
    init();
    Dijkstra(B); // 시작점 : 정점 B
    if (Flag1 == true) Route1 = Route1 + Dist[N]; // 1 ~ A + A ~ B + B ~ N 의 최단거리 (최종루트)
 
    init();
    Dijkstra(A); // 시작점 : 정점 A
    if (Flag2 == true) Route2 = Route2 + Dist[N]; // 1 ~ B + B ~ A + A ~ N 의 최단거리 (최종루트)
 
    if (Flag1 == false && Flag2 == false) ans = -1; // 불가능
    else{
        ans = min(Route1, Route2);
    }
 
    if (ans == INF) ans = -1; // 불가능
 
    cout << ans << endl;
	return 0;
}
