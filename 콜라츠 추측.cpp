#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = -1;
    int i = 0;
    while(num!=1&&i<500){
    if(num%2==0){
        num /= 2;
    }
    else if(num%2==1){
        num  = num*3+1;
    }
        i++;
    }
    if(num==1){
        answer = i;
         }
    return answer;
}
