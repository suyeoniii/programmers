#include <string>
#include <vector>
#include <string.h>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    int dp[101][101];
    memset(dp, 0, sizeof(dp));

    // 못가는곳 표시
    for(int i = 0; i<puddles.size(); i++){
        dp[puddles[i][1]-1][puddles[i][0]-1] = -1;
    }

    dp[0][0] = 1;
    // dp - 각 칸까지의 경우의수 구하기
    for(int row = 0; row<n; row++){
        for(int col = 0; col<m; col++){
            if(dp[row][col] != -1){
                if(dp[row][col+1]!=-1 && col+1 < m) dp[row][col+1] += dp[row][col]%1000000007;
                if(dp[row+1][col]!=-1 && row+1 < n) dp[row+1][col] += dp[row][col]%1000000007;
            }
        }
    }

    return dp[n-1][m-1]%1000000007;
}