#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    vector<int> v[55];
    bool visited[55] = {0,};
    queue<int> q;
    int dist[55] = {0,};

    words.push_back(begin);


    // 그래프 만들기
    for(int i= 0; i<words.size(); i++){
        for(int j = 0; j<words.size(); j++){
            if(i != j){
                int num = 0;
                for(int k = 0; k<words[i].length(); k++){
                    if(words[i][k] != words[j][k]) num += 1;
                    if(num > 1) break;
                }
                if(num == 1) {
                    v[i].push_back(j);
                    v[j].push_back(i);
                }
            }
        }
    }
    
    //bfs
    int start = words.size()-1;
    visited[start] = true;
    q.push(start);
    dist[start] = 0;

    while(!q.empty()){
        int node = q.front();
        string word = words[node];
        if(word==target) {
            answer = dist[node];
            break;
        }
        q.pop();

        for(int i = 0; i<v[node].size(); i++){
            int next = v[node][i];
            if(!visited[next]){
                visited[next] = true;
                q.push(next);
                dist[next] = dist[node]+1;
            }
        }
    }
    return answer;
}