#include<iostream>
#include<algorithm>
#define MAX 1000
using namespace std; 
int n,m,ans;
int arr[MAX][MAX];
int dp[MAX][MAX]={0,};
int main() { 
	ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    dp[0][0]=arr[0][0];
    for(int i=1;i<n;i++){ // 모서리부분 dp계산
        dp[i][0]=dp[i-1][0]+arr[i][0];
    }
    for(int i=1;i<m;i++){ // 모서리부분 dp계산
        dp[0][i]=dp[0][i-1]+arr[0][i];
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            dp[i][j]=max(max(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+arr[i][j]; // 위에서 오는것 왼쪽에서 오는것 대각선에서 오는것중 최댓값 : dp값
        }
    }
    cout<<dp[n-1][m-1];
	return 0;
}
