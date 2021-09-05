#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;
int main(void)
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int test_case;
        cin >> test_case;
        for (int t = 0; t < test_case; t++){
                 string func;
                 cin >> func; // 함수 입력
                 int N;
                 cin >> N; // 원소 개수
                 string arr;
                 cin >> arr; //배열 입력
                 deque<int> dq; //덱
                 string temp; //두 자릿수 이상 숫자를 위하여
                 for (int i = 0; i < arr.length(); i++)
                         if (arr[i] == '[')
                                 continue;
                         else if ('0' <= arr[i] && arr[i] <= '9')
                                 temp += arr[i];
                         else if (arr[i] == ',' || arr[i] == ']')
                         {
                                 if (!temp.empty())
                                 {
                                          dq.push_back(stoi(temp)); // 정수로 변환하여 덱에 저장
                                          temp.clear();
                                 }
                         }
                 bool print = true; // error가 아닐 경우 true
                 bool left = true; // 뒤집어져있지 않으면 true
                 for (int i = 0; i < func.length(); i++)
                         if (func[i] == 'R') // 뒤집기
                                 left = !left;
                         else // 버리기
                         {
                                 if (dq.empty()) // 비어있을때 버리면안됨 (에러)
                                 {
                                          print = false;
                                          cout << "error\n";
                                          break;
                                 }
                                 else
                                          if (left)
                                                  dq.pop_front();
                                          else
                                                  dq.pop_back();
                         }
                 if (print)
                 {
                         if (left)
                         {
                                 cout << "[";
                                 while (!dq.empty())
                                 {
                                          cout << dq.front();
                                          dq.pop_front();
                                          if (!dq.empty())
                                                  cout << ",";
                                 }
                                 cout << "]\n";
                         }
                         else
                         {
                                 cout << "[";
                                 while (!dq.empty())
                                 {
                                          cout << dq.back();
                                          dq.pop_back();
                                          if (!dq.empty())
                                                  cout << ",";
                                 }
                                 cout << "]\n";
                         }
                 }
        }
        return 0;
}
