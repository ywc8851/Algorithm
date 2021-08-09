#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int l, w, h, n, ans;
bool possible = true;
struct box{ // 큐브의 정보저장
	int len;
	int num;
};
box arr[20];
bool cmp(box b1, box b2) {  // 큰 박스부터 정렬
	if (b1.len > b2.len) return true;
	return false;
}
void solved(int l, int w, int h) {
	if (possible == false) return;
	if (l == 0 || w == 0 || h == 0) return; // 박스 채우기 성공

	for (int i = 0; i < n; i++) {
		if (l >= arr[i].len && w >= arr[i].len && h >= arr[i].len && arr[i].num > 0) {
			arr[i].num--; 
			ans++;
            // 제일 큰 큐브제거하고 3구역으로 나눠지므로 3개 재귀생성
			solved(l, w, h - arr[i].len);
			solved(arr[i].len, w - arr[i].len, arr[i].len);
			solved(l - arr[i].len, w , arr[i].len);
			return;
		}
	}
	possible = false; // n개의 큐브동안 박스채우지못하면 불가능한경우
}


int main() {
	cin >> l >> w >> h;
	cin >> n;
	int k;
	for (int i = 0; i < n; i++) {
		cin >> k >> arr[i].num;
		arr[i].len = pow(2,k);
	}
	sort(arr, arr + n, cmp); // 내림차순 정렬

	solved(l, w, h);

	if (possible == false)
		cout << -1 << endl;
	else
		cout << ans << endl;
    return 0;
}