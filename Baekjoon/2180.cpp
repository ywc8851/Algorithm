#include<iostream>
#include<vector>
#include<algorithm>
using namespace std; 
int ans,exc;
bool cmp(pair<int, int> p1, pair<int, int> p2)
{
	int a = p1.first, b = p1.second, c = p2.first, d = p2.second;
	if (b == 0 && d == 0){ // b가 둘다 0인경우 t의계수에 따라 정렬
		return a < c;  // 예외처리
	}
	return  b * c < a * d ; 
}
int main() { 
	ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	int n;
    vector<pair<int, int>> v;
    cin>>n;
    for(int i=0;i<n;i++){  
        int a,b;
        cin>>a>>b;
        if(a==0){          // at+b 에서 a가 0인경우 예외합(exc)에 저장
            exc+=b;
        }else{             // a가 0이 아닌경우만 벡터에 저장
            v.push_back(make_pair(a,b));
        }
    }
    sort(v.begin(),v.end(),cmp); 
    // ans 계산
    for(int i=0;i<v.size();i++){
        int a,b;
        a=v[i].first;
        b=v[i].second;
        ans+=ans*a+b;
        ans%=40000;
    }
    ans+=exc;
    ans%=40000;
    cout<<ans;
	return 0;
}
