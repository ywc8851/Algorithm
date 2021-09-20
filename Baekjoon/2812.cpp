#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, k;
    deque <int> ans;
	string str;
	
    cin >> n >> k;
	cin >> str;
	
	for (int i = 0; i < n; i++) {
			while (!(ans.empty()) && (k > 0) && (ans.back() < str[i]-'0')) {
				ans.pop_back();
				k--;
			}
			ans.push_back(str[i]-'0');
		}
	
	for (int i = 0; i < ans.size() - k; ++i) {
		cout << ans[i];
		}
    
	cout << '\n';
}
