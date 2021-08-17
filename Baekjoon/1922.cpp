#include<iostream>
#include<algorithm>
#include<queue>
#include<tuple>
#define MAX 1001
using namespace std;

int n,m,from,to,weight,ans;
int parent[MAX]={0,};
int child[MAX]={0,};
priority_queue<tuple<int,int,int>> edges;

int find(int node){ // 루트노드를 찾는 함수
    if(parent[node]==node){
        return node; // 루트노드찾음
    }
    return parent[node]=find(parent[node]); // 재귀
}

void union_node(int node1,int node2){
    int root_node1=find(node1);
    int root_node2=find(node2);
    // 자식의 개수가 큰 루트노드에게 합쳐짐 
    if(child[root_node1]<child[root_node2]) {
        parent[root_node1]=root_node2;
    }
    else if(child[root_node1]>child[root_node2]) {
        parent[root_node2]=root_node1;
    }
    else {
        parent[root_node2]=root_node1;
        child[root_node1]++;
    }
}

int main() { 
	ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    cin>>n;
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>from>>to>>weight;
        edges.push(make_tuple(-weight,from,to)); // 가중치가 낮은 간선부터 차례대로 저장됨(우선순위큐)
    }
    for(int i=1;i<=n;i++){ // 초기화
        parent[i]=i;
        child[i]=0;
    }
    while(!edges.empty()){ // 우선순위큐가 empty 될때까지 반복
        auto edge=edges.top();
        int weight=get<0>(edge)*(-1);
        int from=get<1>(edge);
        int to=get<2>(edge);

        if(find(from)!=find(to)) { // 부모가 같지않는경우
            union_node(from,to); // 트리합침
            ans+=weight; // 가중치 더해줌
        }
        edges.pop(); // 간선제거
    }
    cout<<ans;
    return 0;
}
