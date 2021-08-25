#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 100000
using namespace std; 
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin.tie(0);
    int tc;
    cin>>tc;
    while(tc--){
        pair<int,int>p[MAX];
        int n,start;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>p[i].first>>p[i].second;           
        }
        sort(p,p+n); // 서류성적으로 오름차순 정렬
        int ans=1; // 서류 1등은 무조건 뽑힘
        start=p[0].second; // 서류 1등의 면접점수가 기준
        for(int i=1;i<n;i++){
            if(start>p[i].second){ // 현재 최고 면접점수보다 좋으면
                ans++; // 합격시킴
                start=p[i].second; // 최고 면접점수 
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
