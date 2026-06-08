/*
  날짜 : 26.06.08.월
  문제 : 130. Surrounded Regions
  총평 : 처음엔 좌표를 따로 저장하는 q를 만들어서 2번씩 탐색을 했었는데, visited도 따로 만들어야하고, 노드를 2번씩 탐색하기 때문에 비효율적이다. 
  조금만 더 생각해보면 아래 코드처럼 더 효율적인 코드를 짤 수 있다. 
*/

class Solution {
private:
    int m, n;
    struct cordi{
        int y, x;
    };
    int dy[4] = {0, 1, 0, -1};
    int dx[4] = {1, 0, -1, 0};

    void BFS(vector<vector<char>>& board, int a, int b){
        queue<cordi>q;
        q.push({a,b});
        board[a][b] = '#';

        while(!q.empty()){
            int y=q.front().y, x=q.front().x;
            q.pop();

            for(int i=0; i<4; i++){
                int ny=y+dy[i], nx=x+dx[i];
                if(ny<0 || nx<0 || ny>=m || nx>=n)continue;
                if(board[ny][nx] == 'O'){
                    board[ny][nx] = '#';
                    q.push({ny,nx});
                }
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty())return;
        
        m = board.size(), n = board[0].size();

        for(int i=0; i<m; i++){
            if(board[i][0] == 'O'){
                BFS(board, i, 0);
            }
            if(board[i][n-1] == 'O'){
                BFS(board, i, n-1);
            }
        }

        for(int j=0; j<n; j++){
            if(board[0][j] == 'O'){
                BFS(board, 0, j);
            }
            if(board[m-1][j] == 'O'){
                BFS(board, m-1, j);
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 'O')board[i][j] = 'X';
                else if(board[i][j] == '#')board[i][j] = 'O';
            }
        }
        return;
    }
};
