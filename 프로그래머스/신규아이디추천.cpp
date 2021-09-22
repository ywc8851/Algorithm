#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

string solution(string new_id) {
    int length = new_id.length();
    string answer = "";
    // 1단계 : 대문자인 알파벳 소문자로 치환
    for(int i=0;i<length;i++){
        if (new_id[i] >= 65 && new_id[i] <= 90) // 대문자인 경우
            new_id[i] += 32; //소문자 치환
    }
  
    // 2단계 : 조건에 맞지 않은 문자제거
    for(int i=0;i<length;i++){
        if (new_id[i] >= 97 && new_id[i] <= 122){ 
            continue; // 소문자인 경우
        }
        else if(isdigit(new_id[i])!=0 || new_id[i]=='-'|| new_id[i]=='_'|| new_id[i]=='.'){
            continue; // 숫자,빼기,밑줄,마침표 인 경우    
        }
        else { // 나머지는 제거
            new_id[i]=' ';
        }
    }
    new_id.erase(remove(new_id.begin(), new_id.end(), ' '), new_id.end()); // 공백제거
  
    // 3단계 : 연속된 마침표 두개이상일때 하나제거
    for(int i=0;i<length-1;i++){
        if(new_id[i]=='.' && new_id[i+1]=='.'){ // 마침표 2번이상이면 하나제거
            new_id[i]=' ';
        }
    }
    new_id.erase(remove(new_id.begin(), new_id.end(), ' '), new_id.end()); // 공백제거
  
    // 4단계 : 마침표가 처음이나 끝에 위치하면 제거
    if(new_id[0]=='.') new_id[0]=' '; 
    if(new_id[new_id.length()-1]=='.') new_id[new_id.length()-1]=' '; 
    new_id.erase(remove(new_id.begin(), new_id.end(), ' '), new_id.end()); // 공백제거
    int nnew_length = new_id.length();
    
    if(nnew_length==0){ // 5단계 : 빈문자열이면 a 대입
        new_id.push_back('a');
    } else if(nnew_length>=16) { // 6단계 : 길이가 16자이상이면 첫15개 문자만 저장
        new_id=new_id.substr(0,15);
        if(new_id[14]=='.'){
            new_id[14]=' '; // 제거후 마침표가 마지막에 있는 경우 마침표 제거
        }
    }
  
    // 7단계 : 2자 이하이면 길이가 3될때까지 끝문자 붙히기
    if(new_id.length()<=2){
        while(new_id.length()!=3){
            new_id.push_back(new_id[new_id.length()-1]);
        }
    }
    new_id.erase(remove(new_id.begin(), new_id.end(), ' '), new_id.end()); // 공백제거
    answer.assign(new_id); // answer에 new_id 대입
    return answer;
}
