#include<iostream>
#include<string>
 
#define endl "\n"
#define MAX 9
using namespace std;
 
int board[MAX][MAX];
// 스도쿠를 만족하기 위한 세가지 조건을 판단할 수 있는 bool배열
bool Row[MAX][MAX];
bool Col[MAX][MAX];
bool Square[MAX][MAX];

void DFS(int Cnt){
    int x = Cnt / MAX;
    int y = Cnt % MAX;
 
    if (Cnt == 81){ // 스도쿠 다채운상태 -> board 출력
        for (int i = 0; i < MAX; i++){
            for (int j = 0; j < MAX; j++){
                cout << board[i][j];
            }
        cout << endl;
        }
        exit(0);
    }
 
    if (board[x][y] == 0){ // 숫자 채워야하는 칸
        for (int i = 1; i <= 9; i++){
            // 3가지 조건이 아직 성립안하는경우 board[x][y]를 i로 채워넣음
            if (Row[x][i] == false && Col[y][i] == false && Square[(x / 3) * 3 + (y / 3)][i] == false){
                // 백트래킹 진행
                Row[x][i] = true;
                Col[y][i] = true;
                Square[(x / 3) * 3 + (y / 3)][i] = true;
                board[x][y] = i;
                DFS(Cnt + 1); // 한칸채웠으므로 다음단계진행
                board[x][y] = 0;
                Row[x][i] = false;
                Col[y][i] = false;
                Square[(x / 3) * 3 + (y / 3)][i] = false;
            }
        }
    }
    else DFS(Cnt + 1); // 숫자 안채워도되는 칸은 그대로 진행
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    for (int i = 0; i < 9; i++){
        string str;
        cin >> str;
        for (int j = 0; j < 9; j++){
            board[i][j] = str[j] - '0'; // 문자에 '0'을 빼야 숫자로 변환됨
            if (board[i][j] != 0){
                // 세단계로 스도쿠 풀이진행
                Row[i][board[i][j]] = true; // i행에는 board[i][j]가 있음 
                Col[j][board[i][j]] = true; // j열에는 board[i][j]가 있음
                Square[(i / 3) * 3 + (j / 3)][board[i][j]] = true;
                // 3*3의 9개 미니사각형중 (i/3)*3+(j/3)번째 사각형에 board[i][j]가 있음
            }
        }
    }
    DFS(0);
    return 0;
}
