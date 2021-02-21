#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int a[] = {1,2,3,4,5};
    int b[] = {2,1,2,3,2,4,2,5};
    int c[] = {3,3,1,1,2,2,4,4,5,5};
    
    int score_a = 0;
    int score_b = 0;
    int score_c = 0;
    
    for(int i = 0; i<answers.size(); i++){
        if(a[i%5]==answers[i]){
            score_a+=1;
        }
        if(b[i%8]==answers[i]){
            score_b+=1;
        }
        if(c[i%10]==answers[i]){
            score_c+=1;
        }
    }
    
    int max_s = max(max(score_a, score_b), score_c);
    
    if(max_s==score_a){
        answer.push_back(1);
    }
    if(max_s==score_b){
        answer.push_back(2);
    }
    if(max_s==score_c){
        answer.push_back(3);
    }
    
    return answer;
}
