#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector <int> answer;
    int arr1[]={1,2,3,4,5};
    int arr2[]={2,1,2,3,2,4,2,5};
    int arr3[]={3,3,1,1,2,2,4,4,5,5};
    vector<int> ans(3,0); 
    for(int i=0;i<answers.size();i++){
        if(answers[i]==arr1[i%5])
            ans[0]++;
        if(answers[i]==arr2[i%8])
            ans[1]++;
        if(answers[i]==arr3[i%10])
            ans[2]++;
    }
    int high_score = max(max(ans[0], ans[1]), ans[2]);

    for(int i=0; i<3; i++){
        if(ans[i]==high_score){
            answer.push_back(i+1);
        }
    }
    return answer;
}
