#include <iostream>
#include <algorithm>
using namespace std;
int chessboard[15];
int n,cnt;

bool ispossible(int level) {
	for (int i = 0; i < level; i++) {
		if (chessboard[i] == chessboard[level] || (level - i) == abs(chessboard[i] - chessboard[level])) {
			return false;
		}
	}
	return true;
}
void backtracking(int level) {
	if (level == n)
		cnt++;
	for (int i = 0; i < n; i++) {
		
		chessboard[level] = i;
		
		if(ispossible(level))
			backtracking(level + 1);
	}
}

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	backtracking(0);

	cout << cnt << '\n';
	return 0;
}
