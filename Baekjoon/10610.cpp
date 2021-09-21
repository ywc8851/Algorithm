#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<sstream>
#include<algorithm>
#include<math.h>
using namespace std; 
bool cmp(int a,int b){
	return a>b;
}
int main() { 
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	bool haszero=false;
	vector <int> v;
	string str;
	int sum=0;
	cin>>str;
	for(int i=0;i<str.size();i++){
		v.push_back(str[i]-'0');
		sum+=(str[i]-'0');
		if(str[i]-'0'==0){
			haszero=true;
		}
	}
	sort(v.begin(),v.end(),cmp);
	
	if(haszero&&(sum%3==0)){
		for (int i = 0; i < str.size(); ++i){
    		cout << v[i];
		}
	} else {
		cout<<"-1";
	}
	return 0;
	
}
