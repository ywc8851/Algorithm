#include <string>
#include <vector>
#include <cmath>
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int cur_left = 10, cur_right = 12, l_dist = 0, r_dist = 0;
    
    for(int i = 0; i < numbers.size(); i++)
    {
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7)
        {
            answer += "L";
            cur_left = numbers[i];
        }
        else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9)
        {
            answer += "R";
            cur_right = numbers[i];
        }
        else
        {
            if(numbers[i] == 0)
                numbers[i] = 11;
            int tmp_l = abs(cur_left - numbers[i]);
            int tmp_r = abs(cur_right - numbers[i]);
            
            l_dist = (tmp_l / 3) + (tmp_l % 3);
            r_dist = (tmp_r / 3) + (tmp_r % 3);
            
            if(l_dist == r_dist)
            {
                if(hand == "right")
                {
                    answer += "R";
                    cur_right = numbers[i];
                }
                else
                {
                    answer += "L";
                    cur_left = numbers[i];
                }
            }
            else if(l_dist < r_dist)
            {
                answer += "L";
                cur_left = numbers[i];
            }
            else
            {
                answer += "R";
                cur_right = numbers[i];
            }
        }
    }
    return answer;
}
