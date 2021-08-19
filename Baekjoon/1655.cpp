#include<iostream>
#include<algorithm>
#include<queue>
using namespace std; 
priority_queue<int>pq_first,pq_second;
/* 
우선순위 큐를 두개 사용하여 최대힙을 pq_first 최소힙을 pq_second라고 놓고 구현하였다
주의할점 : pq_second의 top 값이 항상 pq_first의 top 값보다 커야함
*/
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
    int n; cin>>n;
	for(int i=0;i<n;i++){
        int num;
        cin>>num;
        if (pq_first.size() > pq_second.size()) { 
            pq_second.push(-num); // 최솟값이 top에 오게끔 -num 을 넣는다
        }else {  // 항상 pq_first.size가 pq_second.size보다 크거나같아야함
            pq_first.push(num);  // 최댓값이 top에 오게끔 num을 넣는다
        }
        if (pq_first.empty() == false && pq_second.empty() == false){
            if (pq_first.top() > -pq_second.top()){ // second의 최솟값이 항상 first의 최댓값보다 커야함
                int max_val = pq_first.top();
                int min_val = -pq_second.top();
                pq_first.pop(); 
                pq_second.pop();
                // swap    
                pq_first.push(min_val);
                pq_second.push(-max_val);
            }
        }
        cout << pq_first.top() << "\n"; // 항상 pq_first의 top(pq_first의 최댓값)이 중간값이됨
    }
	return 0;
}
