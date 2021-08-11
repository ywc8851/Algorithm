#include<iostream>
#define MAX 100000
using namespace std;

int Index[MAX];
int inorder[MAX];
int postorder[MAX];
int n;
// preorder 를 출력하는 함수 (재귀)
void getPreOrder(int inStart, int inEnd, int postStart, int postEnd)
{
    // 더 이상 분할 할 수 없는 경우 return
    if (inStart > inEnd || postStart > postEnd)
        return;
   
    // Index 배열을 통해 inorder에서의 root index를 구함
    int rootIndex = Index[postorder[postEnd]];  // postorder의 끝 값이 root값
    int leftSize = rootIndex - inStart; // 왼쪽 부분트리의 노드개수
    cout << inorder[rootIndex] << ' ';  // root 값 출력 -> root L R 순으로 출력되게됨

    // 재귀 함수 호출
    // 중위순회에서는 시작~root인덱스지점 전칸  후위순회에서는 시작~왼쪽 부분트리의 개수
    getPreOrder(inStart, rootIndex - 1, postStart, postStart + leftSize - 1);
    // 중위순회에서는 root인덱스지점 뒤칸~끝지점   후위순회에서는 오른쪽부분트리개수~끝지점
    getPreOrder(rootIndex + 1, inEnd, postStart + leftSize, postEnd - 1);
}
int main() { 
	ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> inorder[i]; // 중위순회 ( L root R 순으로 탐색)
        Index[inorder[i]] = i; // inorder 요소들의 Index 정보 저장
    }
    for (int i = 1; i <= n; i++){
        cin >> postorder[i]; // 후위순회 (L R root 순으로 탐색)
    }

    getPreOrder(1, n, 1, n); // 전위순회 값 출력

    return 0;
}


