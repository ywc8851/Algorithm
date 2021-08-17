#include <iostream>
#include <algorithm>
#include <vector> 
#include<tuple>
#define MAX 100001
using namespace std; //
long long int ans;
vector<tuple<int,int,int>> edge;
vector<int> parent(MAX, -1); // 부모노드를 저장하는 벡터
vector<int> has_node(MAX, 1);
vector<int> num_edge(MAX, 0);
vector<int> minWeight(MAX, 1000000001);

bool cmp(tuple<int,int,int> t1, tuple<int,int,int> t2) {
	if (get<2>(t1) == get<2>(t2)) { // 가중치 같으면 시작점을 기준으로 정렬
		return get<0>(t1) < get<0>(t2);
	}
	return get<2>(t1) > get<2>(t2); // 가중치순으로 내림차순 정렬 정렬
}

int getParent(int node) {
	if (parent[node] == -1) { // -1로 초기화되어있기 때문에 자신이 부모노드인 경우
		return node;
	}
	return parent[node] = getParent(parent[node]);
}

bool Union(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b) { // 부모노드가 같으면 이미 연결되어있는 트리
		return false;
	}
	if (has_node[a] < has_node[b]) { // 트리의 높이가 긴쪽으로 
		swap(a, b);
	}
	parent[b] = a; // 종점의 부모노드를 시작점으로 설정
    // 최소가중치는 합치는 두개의 부분트리 가중치의 최소값 비교로 작은값이 된다
	minWeight[a] = min(minWeight[a], minWeight[b]); 
	num_edge[a] += num_edge[b]; // a가 부모노드인 트리의 간선개수가 num_edge[a]이다
	if (has_node[a] == has_node[b]) {
		has_node[a]++; // 루트노드가 가지고 있는 자식노드의 수
	}
	return true;
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
	cin >> n;
	for (int i = 1; i <= n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge.push_back(make_tuple(a,b,c)); // a 와 b를 연결하는 간선은 c가중치를 갖는다
	}
	sort(edge.begin(), edge.end(), cmp);

	for (int i=0;i<edge.size();i++) {
		int from = get<0>(edge[i]);
		int to = get<1>(edge[i]);
		int weight = get<2>(edge[i]);
		if (Union(from, to)) {
			// (subtree의 간선수 * 가중치의 최솟값) 과 ans값 크기비교
			num_edge[getParent(from)]++; // 합칠 수 있는경우이므로 간선개수 1증가
			minWeight[getParent(from)] = min(weight, minWeight[getParent(from)]); // 최소가중치 작아졌으므로 변경
            ans = max(ans, (long long int)minWeight[getParent(from)]*num_edge[getParent(from)]);
		}
	}
	cout << ans;
}