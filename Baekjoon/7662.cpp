#include<iostream>
#include <set>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    int n;
    while (t--){
        cin >> n;
        char order;
        int num;
        multiset<int> ms;
        while (n--){
            cin >> order >> num;
            if (order == 'I'){
                ms.insert(num); // 멀티셋에 원소추가
            }
            else{
                if (!ms.empty() && num == -1){
                    ms.erase(ms.begin()); // 최솟값 삭제
                }
                else if (!ms.empty() && num == 1){
                    auto iter = ms.end(); // end()함수는 가장 끝 값의 다음 주소값을 가리킨다
                    iter--; // 따라서 1을빼줌
                    ms.erase(iter); // 최댓값 삭제
                }
            }
        }
        if (ms.empty()){
            cout << "EMPTY" << '\n';
        }
        else{
            auto end_iter = ms.end();
            end_iter--;
            cout << *end_iter << ' ' << *ms.begin() << '\n'; // 최댓값 최솟값 출력
        }
    }
    return 0;
}
