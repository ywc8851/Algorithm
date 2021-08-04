#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N,temp,ans;
vector<pair<int, int>> v; 
int main() { 
	ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	cin >> N; 
    for (int i = 0; i < N; i++) { 
        pair<int, int> a, b; 
        cin >> a.first >> a.second >> b.first >> b.second;
        // 월에 100을 곱하여 날짜를 mmdd꼴로 변경한다 -> 쉽게 정렬하기위해서  (3월1일은 301,11월30일은 1130)
        v.push_back({ a.first * 100 + a.second, b.first * 100 + b.second }); 
    } 
    sort(v.begin(), v.end()); 
    int idx = -1; 
    /* 
    3월 1일부터 11월 30일까지 꽃이 최소하나는 존재해야한다.
    따라서 3.1을포함하는 꽃들중 가장 늦게지는 꽃을 선택하고 ans++
    전 꽃의 다음날을 포함하는 꽃들중 가장 늦게지는 꽃을 선택하고 ans++
    계속 반복하여 도착점이 11월30일을 포함하면 가능하므로 ans출력 불가능하면 0출력
    */
    for (int i = 301; i <= 1130 && idx < N; i = temp) { 
        bool flag = false; 
        idx++; 
        for (int j = idx; j < v.size(); j++) { 
            if (v[j].first > i) { 
                break; 
            } 
            if (temp < v[j].second) { 
                temp = v[j].second; 
                idx = j; 
                flag = true; 
            } 
        } 
        if (flag) { 
            ans++; 
        } else { 
            cout << 0 << "\n"; 
            return 0; 
        } 
    } 
    cout << ans << "\n";
	return 0;
}