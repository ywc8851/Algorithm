#include <iostream> 
using namespace std; 
int N, K; 
int main(void) { 
  ios_base::sync_with_stdio(0); cin.tie(0); 
  cin >> N >> K; 
  if (N <= K) { // 안합쳐도 되는 경우
    cout << 0 << "\n"; 
    return 0; 
  } 
  int result; 
  for (result = 0; ;result++) { // 물병합치기
    int cnt = 0; 
    int tempN = N; 
    while (tempN) { 
      if (tempN % 2) { 
      cnt++; 
      } 
      tempN /= 2; 
    } 
    if (cnt <= K) {
      break; 
    } 
    N++; 
  } 
cout << result << "\n";
return 0; 
}

