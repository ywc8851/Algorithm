#include<iostream>
#include<cstring>
using namespace std; 

int i,a,b,len,ans;
string str,nstr;

int gcd(int a,int b){ // a와 b의 최대공약수를 재귀를 통해 구하는 함수
	if(a%b==0){
		return b;
	}
	return gcd(b,a%b);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>str;
	len=str.length();
	// 문자열로 받은 str 을 정수 두개로 나누기
	while(1){
		if(str[i]==':'){
			nstr=str.substr(0,i);
			a=stoi(nstr); // 숫자로변환
			nstr=str.substr(i+1,len);
			b=stoi(nstr); // 숫자로변환
			break;
		}
		i++;
	}
	
	ans=gcd(a,b); // ans는 a와 b의 최대공약수
	cout<<a/ans<<":"<<b/ans;
	return 0;
}
