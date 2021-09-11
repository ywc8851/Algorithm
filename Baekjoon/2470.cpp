#include <iostream>
#include <vector>
#include <algorithm>
#define INF 2000000000    
using namespace std;

vector<int>answer(2);
int main() {
    int N;
    cin>>N;
    vector<int>arr(N);
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end()); // 오름차순정렬
    
    int start=0; // 시작점은 왼쪽끝(제일 작은수)
    int end=N-1; // 끝점은 오른쪽끝(제일 큰수)
    int min=INF; // 0에 제일 근접한 합
    /* 이분탐색 진행 */
    while(start<end){
        int sum=arr[start]+arr[end];
        if(min>abs(sum)){
            min=abs(sum);
            answer[0]=arr[start]; // 오름차순으로 삽입
            answer[1]=arr[end];
            if(sum==0)
                break;
        }
        if(sum<0)   // 합이 0보다 작으면 시작점 증가(합이 증가됨)
            start++;
        else        // 합이 0보다 크면 끝점 감소(합이 감소됨)
            end--;
    }
    cout<<answer[0]<<" "<<answer[1];
}
