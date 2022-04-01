#include <string>
#include <vector>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> v;
 
    int dx[] = {0, -1, 0, 1}; //상좌하우
    int dy[] = {-1, 0, 1, 0};
    
    //초기화
    int num = 1;
    for(int i = 0; i<rows; i++){
        vector<int> temp;
        for(int j = 0; j<columns; j++){
            temp.push_back(num);
            num++;
        }
        v.push_back(temp);
    }
    
    //회전
    for(int i = 0; i<queries.size(); i++){
        int y = queries[i][0]-1;
        int x = queries[i][1]-1;
        int paste = v[y][x];
        int copy = v[y][x];
        int min = 100000;
        for(int j = 3; j>=0; j--){
            while(1){
                
                paste = copy;
                x += dx[j];
                y += dy[j];

                copy = v[y][x];
                v[y][x] = paste;
                if(paste < min) min = paste;
                
                if(j%2!=0 && (x<=queries[i][1]-1 || x>=queries[i][3]-1)) //x
                    break;
                if(j%2==0 && (y<=queries[i][0]-1 || y>=queries[i][2]-1)) //y
                    break;
            }
        }
        
        answer.push_back(min);
    }
    
    return answer;
}