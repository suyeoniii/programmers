#include <string>
#include <vector>

using namespace std;

string solution(int num) {
    string answer = "";
    if(num<0)
        num*=(-1);
    if(num==0)
        answer = "Even";
    if(num%2==0)
        answer = "Even";
    if(num%2==1)
        answer = "Odd";
        
    return answer;
}
