#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string s = new_id;
    string answer = "";
    string ans = "";
    for(int i = 0; i<new_id.length(); i++){
        if(new_id[i]>='A'&&new_id[i]<='Z'){
            answer += new_id[i]+32;
        }
        else if(new_id[i]=='.'){
            if(i!=0&&answer.length()!=0){
                if(answer[answer.length()-1]!='.'){
                    answer += new_id[i];
                }
            }
        }
        else if((new_id[i]>='a'&&new_id[i]<='z')||(new_id[i]=='-')||(new_id[i]=='_')||(new_id[i]=='.')||(new_id[i]>='0'&&new_id[i]<='9')){
            answer += new_id[i];
        }
    }
    new_id = answer;
    if(answer.length()==0){
        answer += 'a';
    }
    while(answer[0] == '.'||answer[answer.length()-1]=='.') {
        if (answer[0] == '.') {
            answer[0] = ' ';
            for (int i = 0; i < answer.length() && ans.length() < 15; i++) {
                if (answer[i] != ' ') {
                    ans += answer[i];
                }
            }
            answer = ans;
            ans = "";
        }
        if(answer[answer.length()-1]=='.'){
            answer[answer.length()-1] = ' ';
            for (int i = 0; i < answer.length() && ans.length() < 15; i++) {
                if (answer[i] != ' ') {
                    ans += answer[i];
                }
            }
            answer = ans;
            ans = "";
        }
    }
    ans = "";
    for (int i = 0; i < answer.length() && ans.length() < 15; i++) {
        if (answer[i] != ' ') {
            ans += answer[i];
        }
    }
    answer = ans;
    while(answer[0] == '.'||answer[answer.length()-1]=='.') {
        if (answer[0] == '.') {
            answer[0] = ' ';
            for (int i = 0; i < answer.length() && ans.length() < 15; i++) {
                if (answer[i] != ' ') {
                    ans += answer[i];
                }
            }
            answer = ans;
            ans = "";
        }
        if(answer[answer.length()-1]=='.'){
            answer[answer.length()-1] = ' ';
            for (int i = 0; i < answer.length() && ans.length() < 15; i++) {
                if (answer[i] != ' ') {
                    ans += answer[i];
                }
            }
            answer = ans;
            ans = "";
        }
    }
    if(answer.length()==0){
        answer += 'a';
    }
    if(answer.length()<=2){
        while(answer.length()<3){
            answer += answer[answer.length()-1];
        }
    }
    return answer;
}
