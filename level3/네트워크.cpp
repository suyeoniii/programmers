#include <string>
#include <vector>
#include <queue>

using namespace std;

//computers = [[1,1,0], [1,1,0], [0,0,1]]

bool visited[1001] = {0, };
queue<int> q;

void bfs(vector<vector<int>> computers, int n){
    
    //첫번째 노드 방문
    visited[n] = true;
    q.push(n);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(int i = 0; i<computers.size(); i++){
            
            if(i == node) continue;
            
            //현재 노드와 연결된 노드를 탐색 대기열(큐)에 넣기
            if(computers[i][node] && !visited[i]){
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i = 0; i<computers.size(); i++){
        if(!visited[i]){
            bfs(computers, i);
            answer++;
        }
    }
    
    return answer;
}