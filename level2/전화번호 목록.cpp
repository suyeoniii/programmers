#include <string>
#include <vector>
#include <map>
#include <string>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    map<string, pair<int,int>> m;
    
    for(int i = 0; i<phone_book.size(); i++){
        m[phone_book[i]] = make_pair(i,1);  
    }
    
    for(int i = 0; i<phone_book.size(); i++){
        string s = "";
        for(int j = 0; j<phone_book[i].length(); j++){
            s += phone_book[i][j];
            if(m[s].second!=0 && m[s].first!=i){
                answer = false;
                return answer;
            }
        }
    }
    
    return answer;
}
