#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s) {
    int answer = 0;
    string str="";
    for(int i=0;i<s.length();i++){
        if(s[i]>='0'&&s[i]<='9'){ // 숫자인 경우
            str.push_back(s[i]);
        }
        if(s[i]=='z'){ // zero , 즉 0인 경우
            str.push_back('0');
            i+=3;
            continue;
        }
        if(s[i]=='o'){ // one, 즉 1인 경우
            str.push_back('1');
            i+=2;
            continue;
        }
        if(s[i]=='t'){
            if(s[i+1]=='w'){ // two, 즉 2인 경우
                str.push_back('2');
                i+=2;
                continue;
            }else{ // three, 즉 3인 경우
                str.push_back('3');
                i+=4;
                continue;
            }
        }
        if(s[i]=='f'){
            if(s[i+1]=='o'){ // four, 즉 4인 경우
                str.push_back('4');
                i+=3;
                continue;
            }else{ // five, 즉 5인 경우
                str.push_back('5');
                i+=3;
                continue;
            }
        }
        if(s[i]=='s'){
            if(s[i+1]=='i'){ // six, 즉 6인 경우
                str.push_back('6');
                i+=2;
                continue;
            }else{ // seven, 즉 7인 경우
                str.push_back('7');
                i+=4;
                continue;
            }
        }
         if(s[i]=='e'){ // eight, 즉 8인 경우
            str.push_back('8');
            i+=4;
            continue;
        }
         if(s[i]=='n'){ // nine, 즉 9인 경우
            str.push_back('9');
            i+=3;
            continue;
        }
    }
    answer=stoi(str); // str을 int형으로 변환하여 answer에 대입
    return answer;
}
