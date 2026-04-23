/*
  날짜 : 26.04.19.일
  문제 : SWEA 5644. [모의 SW 역량테스트] 무선 충전
  로직 : DP + 재귀함수
  난이도 : Hard
  총평 : 딱히 어렵진 않았음.
*/
class Solution {
private:
    int n, m;
    int dp[200][200];
    int dy[4] = {0, 1, 0, -1};
    int dx[4] = {1, 0, -1, 0};
    int go(int y, int x, vector<vector<int>>& matrix){
        int& ret = dp[y][x];
        if(~ret)return ret;
        ret = 1;

        for(int i=0; i<4; i++){
            int ny=y+dy[i], nx=x+dx[i];
            if(ny<0 || nx <0 || ny>=n || nx>=m)continue;
            if(matrix[ny][nx] < matrix[y][x]){
                ret = max(ret, 1+go(ny,nx,matrix));
            }
        }
        return ret;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n=matrix.size(); 
        m=matrix[0].size();

        memset(dp, -1, sizeof(dp));
        int max_path = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                max_path = max(max_path, go(i,j, matrix));
            }
        }
        return max_path;
    }
};
