#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    int map1[n][n]; // arr1을 나타내는 지도
    int map2[n][n]; // arr2를 나타내는 지도
    
    for (int i = 0; i < n; ++i) {
        int a = arr1[i];
        int b = arr2[i];
        // 2진수로 바꿔주기
        for (int j = n - 1; j >= 0; j--) {
            map1[i][j] = a % 2;
            map2[i][j] = b % 2;
            a /= 2;
            b /= 2;
        }
    }
    
    for(int i=0;i<arr1.size();i++){
        string str;
        for(int j=0;j<arr2.size();j++){
            if(map1[i][j]==0 &&map2[i][j]==0){ // 공백
                str+=' ';
            }else{ // #(벽이 있는 경우)
                str+='#';
            }
        }
        answer.push_back(str);
    }
    return answer;
}
