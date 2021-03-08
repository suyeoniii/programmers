#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int temp;
    int a = s.length();
    while(a>1)
    {
    for(int i = 0;i<a;i++)
    {
        if(int(s[i])<int(s[i+1]))
        {
            temp = s[i];
            s[i] = s[i+1];
            s[i+1] = temp;
        }
    }
        a-=1;
    }
    answer = s;
    return answer;
}
