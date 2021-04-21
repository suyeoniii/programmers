#include <string>
#include <vector>
#include <math.h>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    vector<pair<int, int>> v;
    v.push_back(make_pair(1,0));
    v.push_back(make_pair(0,3));
    v.push_back(make_pair(1,3));
    v.push_back(make_pair(2,3));
    v.push_back(make_pair(0,2));
    v.push_back(make_pair(1,2));
    v.push_back(make_pair(2,2));
    v.push_back(make_pair(0,1));
    v.push_back(make_pair(1,1));
    v.push_back(make_pair(2,1));
    
    pair<int,int> left = make_pair(0,0);
    pair<int,int> right = make_pair(2,0);
    
    for(int i = 0; i<numbers.size(); i++){
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7){
            answer += "L";
            left = v[numbers[i]];
        }
        else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9){
            answer += "R";
            right = v[numbers[i]];
        }
        else{
            
            int l_len = abs(left.first - v[numbers[i]].first) + abs(left.second - v[numbers[i]].second);
            int r_len = abs(right.first - v[numbers[i]].first) + abs(right.second - v[numbers[i]].second);
            
            if(l_len < r_len){
                answer += "L";
                left = v[numbers[i]];
            }
            else if(l_len > r_len){
                answer += "R";
                right = v[numbers[i]];
            }
            else{
                if(hand=="right"){
                    answer += "R";
                    right = v[numbers[i]];
                }
                else{
                    answer += "L";
                    left = v[numbers[i]];
                }
            }
                
        }
    }
    return answer;
}
