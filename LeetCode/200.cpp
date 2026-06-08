/*
  날짜 : 26.06.08 월
*/


class Solution {
private:
    int dy[4] = {0, 1, 0, -1};
    int dx[4] = {1, 0, -1, 0};
    int visited[305][305] = {0};
    
    struct cordi{
        int y, x;
    };

    int m, n;
    void init(vector<vector<char>>& grid){
        m = grid.size();
        n = grid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++)visited[i][j] = 0;
        }
    }
    void BFS(vector<vector<char>>&grid, int p, int q){
        if(grid[p][q] == '0' || visited[p][q])return;
        queue<cordi>k;
        k.push({p,q});
        visited[p][q] = 1;

        while(!k.empty()){
            int y=k.front().y, x=k.front().x;
            k.pop();
            for(int i=0; i<4; i++){
                int ny=y+dy[i], nx=x+dx[i];
                if(ny<0 || nx<0 || ny>=m || nx>=n)continue;
                if(visited[ny][nx])continue;
                if(grid[ny][nx] == '0')continue;
                k.push({ny,nx});
                visited[ny][nx] = 1;
            }
        }
    }
public:

    int numIslands(vector<vector<char>>& grid) {
        init(grid);

        int ret = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    BFS(grid, i, j);
                    ret++;
                }
            }
        }
        return ret;
    }
};
