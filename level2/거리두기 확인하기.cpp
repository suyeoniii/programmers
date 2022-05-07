// 시뮬레이션

#include <string>
#include <vector>

using namespace std;

int dr[13][13] = {{-1, -1}, {-1, 0}, {0, 0}, {0, -1}, {0, 1}, {1, 0}, {1, 1},{0, 1}, {1, 0}, {0, 0}, {0, -1}, {-1, 0}};
int dc[13][13] = {{0, 0}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {0, 1}, {0, 0}, {-1, 0}, {0, -1}, {-1, -1}, {-1, 0}, {0, -1}};

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    int ans = 1;
    
    for(int i = 0; i<5; i++){
        ans = 1;
        for(int r = 0; r<5; r++){
            for(int c = 0; c<5; c++){
                if(places[i][r][c]=='P'){
                    for(int d = 0; d<12; d++){
                        int nr = r + dr[d][0];
                        int nc = c + dc[d][0];
                        
                        if(nr < 0 || nr >= 5 || nc < 0 || nc >= 5) continue;
                        if(places[i][nr][nc] == 'X') continue;
                        if(places[i][nr][nc] == 'P') {
                            ans = 0;
                            break;
                        }
                        
                        nr += dr[d][1];
                        nc += dc[d][1];
                        
                        if(nr < 0 || nr >= 5 || nc < 0 || nc >= 5) continue;
                        if(places[i][nr][nc] == 'X') continue;
                        if(places[i][nr][nc] == 'P') {
                            ans = 0;
                            break;
                        }
                    }
                }
                if(!ans) break;
            }
            if(!ans) break;
        }
        answer.push_back(ans);
    }
    
    return answer;
}