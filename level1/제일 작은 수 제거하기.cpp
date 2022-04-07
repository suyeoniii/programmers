#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    if(arr.size()==1) {
        answer.push_back(-1);
        return answer;
    }
    
    int min = 999999999;
    for(int i = 0; i<arr.size(); i++){
        if(min > arr[i]) min = arr[i];
    }
    
    for(int i = 0; i<arr.size(); i++){
        if(min != arr[i]) answer.push_back(arr[i]);
    }
    
    return answer;
}