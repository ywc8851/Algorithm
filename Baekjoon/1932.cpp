#include<iostream>
#include<algorithm>
#define MAX 500
using namespace std; 
int n,ans;
int arr[MAX][MAX];
int dp[MAX][MAX]={0,};
int main() { 
	ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cin>>arr[i][j];
        }
    }
    dp[0][0]=arr[0][0];
    for(int i=1;i<n;i++){
        dp[i][0]=dp[i-1][0]+arr[i][0];
        dp[i][i]=dp[i-1][i-1]+arr[i][i];
    }
    for(int i=2;i<n;i++){
        for(int j=1;j<n-1;j++){
            dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+arr[i][j];
        }
    }
    for(int i=0;i<n;i++){
        if(dp[n-1][i]>ans){
            ans=dp[n-1][i];
        }
    }
    cout<<ans;
	return 0;
}
