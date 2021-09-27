#include<iostream>
#include<algorithm>
using namespace std;  
int dp[1001][1001];
string str1,str2;
int main() { 
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>str1>>str2;

	int str1_size=str1.size();
	int str2_size=str2.size();

	for(int i=1;i<=str1_size;i++){
		for(int j=1;j<=str2_size;j++){
			if(str1[i-1]==str2[j-1]){
				dp[i][j]=dp[i-1][j-1]+1; // 현재 비교값이 같으면 왼쪽대각선에서 가져옴
			}
			else{ // 서로 다르다면 LCS의 값을 왼쪽 혹은 위에서 가져온다.
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}

	cout<<dp[str1_size][str2_size];
	
	return 0;
}
