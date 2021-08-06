#include <iostream>
#include <algorithm>
using namespace std;
long long ans = -1;
int arr[100000];
int n, m;
long long low,mid,high,sum;
bool search(int num) {
	int cnt = 1;
    long long total = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > num) // 블루레이 크기보다 기타레슨의 길이가 큰 경우
			return false; // 담을 수 없음		
		total += arr[i];
		if (total > num) { // 합이 블루레이 크기 넘는 경우
			total = arr[i]; 
			cnt++;
		}
	}
	if (cnt <= m) return true; 
	else return false; // 블루레이 갯수를 넘어갈 경우 불가능
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	long long sum = 0;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	high = sum;
    // 이분 탐색으로 접근
	while (low <= high) {
		mid = (high + low) / 2;
		bool possible = search(mid);
		if (possible) {
			high = mid - 1;
			ans = mid;
		}
		else low = mid + 1;
	}
	cout << ans;
	
	return 0;
}