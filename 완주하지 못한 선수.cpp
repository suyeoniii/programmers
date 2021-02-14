#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    map<string, int> m;
    
    for(int i = 0; i<participant.size(); i++){
        m[participant[i]] += 1;
    }
    
    for(int i = 0; i<completion.size(); i++){
        m[completion[i]] -= 1;
    }
    
    for(auto iter = m.begin(); iter != m.end(); iter++){
        if(iter->second==1){
            answer = iter->first;
            break;
        }
    }
    
    return answer;
}
