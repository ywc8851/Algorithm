#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define MAX 901
#define endl "\n"
using namespace std;

int K, N, F;
int num_friend[MAX];
bool is_friend[MAX][MAX]; // true면 친구관계
bool ans[MAX];
bool possible = false;

bool possible_ans(int x){
    for (int i = 1; i <= N; i++){
        if (ans[i] == true)
        {
            if (is_friend[x][i] == false) return false;
        }
    }
    return true;
}
 
void backtracking(int Cur, int Cnt){
    if (possible == true) 
		  return;
    if (Cnt == K){ // K명의 친구관계 성공
        for (int i = 1; i <= N; i++){
        if (ans[i] == true) cout << i << endl; // ans[i]가 true면 현재 K명의 친구관계중 한명이므로 출력
    }
        possible = true;
        return;
    }
 
    for (int i = Cur + 1; i <= N; i++){
        if (is_friend[Cur][i] == false){ // i와 친구관계가 아님
			continue;
		} 
        if (possible_ans(i) == false){
			continue;
		} 
        ans[i] = true;
        backtracking(i, Cnt + 1);   
        ans[i] = false;
    }
}
int main() { 
	ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	cin >> K >> N >> F;
    for (int i = 0; i < F; i++){
        int a, b;
        cin >> a >> b;
        is_friend[a][b] = true;
        is_friend[b][a] = true;
 
        num_friend[a]++;
        num_friend[b]++;
    }
	for (int i = 1; i <= N; i++){
        if (num_friend[i] < K - 1){ // 친구 수가 k-1 보다 작은경우는 불가능
            continue;
        } 
        if (possible == true){
            break;
        }
        ans[i] = true;
        backtracking(i, 1);
        ans[i] = false;
    }
 
    if (possible == false){ // 불가능한경우 
		cout << -1 << endl;	
	} 

	return 0;
}
