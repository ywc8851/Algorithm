#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int min_rank,max_rank;
    int ans2=0;
    int num_zero=0;
    sort(win_nums.begin(),win_nums.end());
    sort(lottos.begin(),lottos.end());
    for(int i=0;i<6;i++){
        if(lottos[i]==0){
            num_zero++;
        }
    }
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            if(lottos[i]==win_nums[j]){
                ans2++;
            }
        }
    }
    if(ans2==0){
        min_rank=6;
    }else{
        min_rank=7-ans2;
    }
    if(ans2+num_zero<2){
        max_rank=6;
    }else{
        max_rank=7-(ans2+num_zero);
    }
    
    answer.push_back(max_rank);
    answer.push_back(min_rank);
    return answer;
}
