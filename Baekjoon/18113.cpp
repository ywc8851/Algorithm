#include<iostream>
#include<algorithm>

#define MAX 1000000
using namespace std;

int n,k,m,num,max_len;
int ans=-1;
int kimbab[MAX];
bool possible(int cut_len){
    int cnt=0;
    for(int i=0;i<n;i++){ // 모든 김밥을 cut_len으로 자르기
        cnt+=kimbab[i]/cut_len;
    }
    return cnt>=m; // 잘린조각수가 m보다 많으면 가능한경우이므로 true반환
}
void bs(int start,int end){
    if(start>end){
        return;  // 이분탐색 종료조건
    }
    int mid=(start+end)/2;
    if(possible(mid)){
        ans=max(ans,mid);
        bs(mid+1,end);
    }
    else {
        bs(start,mid-1);
    }
}
int main() { 
	ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	cin>>n>>k>>m;
    for(int i=0;i<n;i++){
        cin>>num;
        if(num<=k){
            num=0; // 김밥폐기
        }
        else if(num<2*k){
            num=num-k; // 한쪽만 꼬다리제거
        }
        else if(num>=2*k){
            num=num-2*k; // 양쪽 꼬다리제거
        }
       
        max_len=max(num,max_len); // 자를수있는 김밥의 최대길이
        
        kimbab[i]=num;
    }
    bs(1,max_len); // 이분탐색
    cout<<ans;
    return 0;
}


