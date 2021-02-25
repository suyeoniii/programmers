#include <string>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for(int i = 0; i<scoville.size(); i++){
        pq.push(scoville[i]);
    }
    while(pq.top()<K){
        int one = pq.top();
        pq.pop();
        int two = pq.top();
        pq.pop();
        pq.push(one + two*2);
        answer += 1;
        
        if(pq.size()==1&&pq.top()<K){
            return -1;
        }
    }
    
    return answer;
}
