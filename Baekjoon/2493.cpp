#include <iostream>
#include <stack>
using namespace std;
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    stack<pair<int, int> > s;  // pair<int, int> : index, height
    int num, height;
    cin >> num;
 
    for (int i = 0; i < num; i++) {
        cin >> height;
        while (!s.empty()) {
            //수신탑 발견
            if (height < s.top().second) { // 현재 탑보다 왼쪽수신탑에 높이가 높은 경우(수신가능)
                cout << s.top().first << " "; // 수신하는 탑의 index 출력
                break;
            }
            //수신탑 찾을 때까지 계속 pop -> 못찾는경우는 현재탑보다 높이낮은 경우이므로 pop해도 상관없음
            s.pop();
        }
        //수신 탑이 없다면
        if (s.empty()) {
            cout << 0 << " ";
        }
        //현재 높이를 스택에 푸쉬
        s.push(make_pair(i + 1, height));
    }
     
    return 0;
}  
