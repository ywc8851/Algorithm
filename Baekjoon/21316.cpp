#include<iostream>
#include<vector>

using namespace std; 
int degree[13]={0,};
int correct[3]={1,2,3};
bool visited[3]={false,};
int ans;
vector <int> v[13];
int main() { 
	ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	for(int i=0;i<12;i++){
        int a,b;
        cin>>a>>b;
        degree[a]++; degree[b]++;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<13;i++){
        if(degree[i]==3){ // 차수가 3개인 별만 탐색
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    if(correct[j]==degree[v[i][k]]){ 
                        visited[j]=true;
                        break;
                    }else{
                        visited[j]=false; // 스피카 별의 조건에 맞지않음
                    }
                }
            }
            if(visited[0]==true&&visited[1]==true&&visited[2]==true){
            // 이 조건을 만족하면 이어지는 별들의 차수가 각각 1,2,3이다. -> 스피카별의 결정조건     
                ans=i;
                break;
            }else{
                continue;
            }
        }
    }
    cout<<ans;
    return 0;
}


