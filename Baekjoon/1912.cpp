#include<iostream>
#include<algorithm>

#define MAX 100000
int ans,n;
int arr[MAX];
int cur[MAX];

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cur[0]=arr[0];
    ans=arr[0];
    for(int i=1;i<n;i++){
        cur[i]=max(cur[i-1]+arr[i],arr[i]);
        ans=max(ans,cur[i]);
    }
    cout<<ans;
    return 0;
}
