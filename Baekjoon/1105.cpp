#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string L, R;
    cin >> L >> R;
    int ans = 0;
    // 자릿수가 다른 경우는 무조건 0
    // 자릿수가 같은 경우는 앞부터 8이 몇개인지만 세면 됨
    if (L.length() == R.length()) {
        for (int i = 0; i < L.length(); ++i) {
            if (L[i] != R[i]) break;
            if (L[i] == R[i] && L[i] == '8') ++ans;
        }
    }
    cout << ans;
}
