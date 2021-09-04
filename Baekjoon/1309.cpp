#include<iostream>
#include<algorithm>

#define endl "\n"
#define MAX 100000 + 1
#define Moduler 9901
 
using namespace std; 
int N;
int DP[MAX][3];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin.tie(0);
    cin>>N;
    DP[1][0] = DP[1][1] = DP[1][2] = 1; // 초기값 설정
 
    for(int i = 2; i <= N; i++){
        // i번째줄에 사자가 없는 경우 ( i-1번째줄에 사자가 없거나 오른쪽이나 왼쪽에 있어야함 )
        DP[i][0] = (DP[i - 1][0] + DP[i - 1][1] + DP[i - 1][2]) % Moduler;
        // i번째줄에 사자가 왼쪽에 있는 경우 ( i-1번째줄에 사자가 없거나 오른쪽에 있어야함 )
        DP[i][1] = (DP[i - 1][0] + DP[i - 1][2]) % Moduler;
        // i번째줄에 사자가 오른쪽에 있는 경우 ( i-1번째줄에 사자가 없거나 왼쪽에 있어야함 )
        DP[i][2] = (DP[i - 1][0] + DP[i - 1][1]) % Moduler;
    }
    // 구하고자하는 값 : N번째 줄에 사자가 없거나 오른쪽에 있거나 왼쪽에 있는 경우 세가지 경우의 수의 합
    cout << (DP[N][0] + DP[N][1] + DP[N][2]) % Moduler << endl;
    
    return 0;
}
