#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    string s;
    for(int i = 0;i<seoul.size();i++)
        if(seoul[i]=="Kim")
        {
            s = to_string(i);
            answer ="김서방은 "+s+"에 있다";
            break;
        }
    
    return answer;
}
