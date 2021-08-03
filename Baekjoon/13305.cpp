#include<iostream>
#define MAX 100000
using namespace std; 
long long int dist[MAX];
long long int price[MAX];
long long int cur_price,min_price,sum_dist,ans;
int main() { 
	ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	int n;
    cin>>n;
    for(int i=0;i<n-1;i++){  // 도시간 거리
        cin>>dist[i];
    }
    for(int i=0;i<n;i++){   // 도시 주유소 가격
        cin>>price[i];
    }
    cur_price=price[0]; dist[n-1]=0;
    for(int i=0;i<n;i++){
        /* 
        시작 지점에서부터 주유소 가격이 작은 값을 만날때까지
        거리를 더해가며 주유소 가격이 작은 값을 만나면
        기존의 (주요소가격 * 현재까지의 거리) 계산하여 ans에 저장
        */
        if(price[i]<cur_price){    
            ans+=(cur_price*sum_dist);
            cur_price=price[i];
            sum_dist=0;
        }
        sum_dist+=dist[i];
        if(i==n-1){
            ans+=(cur_price*sum_dist);
        }
    }
    cout<<ans;
	return 0;
}