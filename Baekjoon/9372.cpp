#include <iostream>  
using namespace std;
int main(void) { 
    int tc; 
    cin >> tc;
    while(tc--){
        int N, M;
        cin >> N >> M;  
        for (int i = 0; i < M; i++){
            int a, b; 
            cin >> a >> b; 
        }
        cout << N-1 << "\n";
    }
    return 0;
}