#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>

using namespace std;

vector<int> a[20001];
bool visited[20001] = {0,};
queue<int> q;
int dist[20001] = {0,};

int ma = 0;
void bfs(int n){
    visited[n] = true;
    q.push(n);

    while(!q.empty()){
        int node = q.front();
        if(ma < dist[node]) ma = dist[node];
        q.pop();

        for(int i = 0; i<a[node].size(); i++){
            int next = a[node][i];
            if(!visited[next]){
                visited[next] = true;
                q.push(next);
                dist[next] = dist[node]+1;
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    for(int i = 0; i<edge.size(); i++){
        a[edge[i][0]].push_back(edge[i][1]);
        a[edge[i][1]].push_back(edge[i][0]);
    }

    for (int i = 1; i <= n; i++)
    {
        sort(a[i].begin(), a[i].end());
    }

    memset(dist, 0, sizeof(dist));

    bfs(1);

    for(int i = 1; i<=n; i++){
        if(dist[i] == ma) answer += 1;
    }

    return answer;
}