#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/* 
오큰수 : A(i) 오른쪽에 있으면서 A(i)보다 큰 수중 가장 왼쪽에 있는 수
즉 A(i)보다 크면서 처음으로 A(i)보다 큰 값을 갖는 A(j)가 A(i)의 오큰수이다.  ( j>i )
*/
int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n; // 수열의 크기 입력받기
	
	vector<int>arr(n); // 크기가 n인 수열 An 넣을 벡터
    vector<int>ans(n,-1); // 오큰수 값을 저장할 벡터 (-1로 초기화)
	stack<int>s; // 인덱스 값을 저장할 스택	
	
	for (int i = 0; i < n; i++){
        cin >> arr[i];	// 수열 An 입력받기
    } 
    
	for (int i = 0; i < n ; i++) {
/* 
스택이 비어있는 경우 - > 스택에 인덱스 i값 push
스택이 비어있지 않음 and 현재 스택탑에 있는 인덱스값을 갖는 수열 arr[s.top()]보다 현재 i값 인덱스를 갖는 수열 arr[i]가 클경우
-> 오큰수를 만족한다. 따라서 ans[s.top()]은 arr[i]이다.
s.top() 인덱스는 오큰수를 구하였으므로 스택에서 pop 한다.
i번째 index를 스택에 push한다.
*/
		while (!s.empty() && arr[s.top()] < arr[i]) {
			ans[s.top()] = arr[i];
			s.pop();
		}
		
		s.push(i);
	}
	
	for (int i = 0; i < n; i++){
        cout << ans[i] << " "; 	// 오큰수 값 출력
    } 
    
	return 0;
}

