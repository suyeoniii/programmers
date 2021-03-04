#include <vector>
#include <map>
#include <utility>
using namespace std;

int solution(vector<int> nums)
{
    map<int, int> m;
    int answer = 0;
    int total = 0;
    for(int i = 0; i<nums.size(); i++){
        if(m[nums[i]]==0){
            m[nums[i]] += 1;
            
            total += 1;
        }
    }
    
    if(total<nums.size()/2){
        answer = total;
    }
    else{
        answer = nums.size()/2;
    }
    return answer;
}
