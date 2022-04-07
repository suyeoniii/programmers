#include <string>
#include <vector>
#include <map>
#include <utility>

using namespace std;

vector<string> split(string str, char delimiter)
{
	vector<string> vs;
	string temp;

	for (int i = 0; !(str[i] == 13 || str[i] == '\n' || str[i] == 0); i++)
	{
		if (str[i] == delimiter)
		{
			vs.push_back(temp);
			temp.clear();

			continue;
		}

		temp.push_back(str[i]);
	}
	vs.push_back(temp); 

	return vs;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> m;
    
    for(int i = 0; i<record.size(); i++){
        vector<string> v = split(record[i], ' ');
        
        if(v[0] == "Enter" || v[0] == "Change"){
            m[v[1]] = v[2];
        }
    }
    
    for(int i = 0; i<record.size(); i++){
        vector<string> v = split(record[i], ' ');
        
        if(v[0] == "Enter"){
            string nickname = m[v[1]];
            answer.push_back(nickname+"님이 들어왔습니다.");
        } else if (v[0] == "Leave") {
            string nickname = m[v[1]];
            answer.push_back(nickname+"님이 나갔습니다.");
        }
    }
    
    return answer;
}