#include<iostream>
#include<algorithm>
using namespace std;  

int n,ans;
int dp[1000][3];
int arr[1000][3];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>arr[i][j];
        }
    }
    // 초기 dp값 설정   
    dp[0][0]=arr[0][0]; // red
    dp[0][1]=arr[0][1]; // green
    dp[0][2]=arr[0][2]; // blue
    
    // dp[n][0]값은 (n번째 집을 red로칠했을때 비용의최솟값) dp[n-1]을 green으로 칠했을때 blue로 칠했을때 최솟값의 min 값과 n번째 집을 red로칠할때의 비용을 더하면됨
    for(int i=1;i<n;i++){
        dp[i][0]=min(dp[i-1][1],dp[i-1][2])+arr[i][0];
        dp[i][1]=min(dp[i-1][0],dp[i-1][2])+arr[i][1];
        dp[i][2]=min(dp[i-1][0],dp[i-1][1])+arr[i][2];
    }
  
    ans=min(min(dp[n-1][0],dp[n-1][1]),dp[n-1][2]);
    
    cout<<ans;
    return 0;
}
