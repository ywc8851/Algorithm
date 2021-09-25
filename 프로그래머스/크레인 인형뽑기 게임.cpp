#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int>basket;
    basket.push(0);
    for(int i=0; i<moves.size(); i++){
        int num=moves[i];
        for(int j=0; j<board.size(); j++){
            if(board[j][num-1] != 0){
                if(basket.top() == board[j][num-1]){ // 같은인형 두개연속
                    answer+=2; 
                    basket.pop(); // 맨 위 인형 제거
                }else { // 아닌경우 바구니에 넣어줌
                    basket.push(board[j][num-1]);
                }
                board[j][num-1]=0; 
                break; 
            }
        }
    }
    return answer;
}
