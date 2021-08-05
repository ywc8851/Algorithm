#include<iostream>
#define MAX 1000
using namespace std;
int n,maxdp,ans;
int arr[MAX];
int dp[MAX]={0,};
int main() { 
	ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    dp[0]=1;
    for(int i=1;i<n;i++){
        maxdp=0;
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){
                if(maxdp<dp[j]){
                    maxdp=dp[j];
                }
            }
        }
        dp[i]=maxdp+1;
    }
    for(int i=0;i<n;i++){
        if(ans<dp[i]){
            ans=dp[i];
        }
    }
    cout<<ans;
	return 0;
}