/*
BEFORE : 시간복잡도는 O(NM), 공간복잡도는 최악의 경우 O(NM)
AFTER : 시간복잡도는 O(NM), 공간복잡도는 O(1) -> IN-PLACE
*/

//BEFORE
class Solution {
private:
    int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};

    struct cordi{
        int y,x;
    };
    vector<cordi>ch;
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int cnt = 0;
                for(int d=0; d<8; d++){
                    int ny=i+dy[d], nx=j+dx[d];
                    if(ny<0 || nx<0 || ny>=n || nx>=m)continue;
                    if(board[ny][nx])cnt++;
                }

                if(board[i][j]){
                    if(cnt<2 || cnt>3)ch.push_back({i,j});
                }
                else{
                    if(cnt == 3)ch.push_back({i,j});
                }
            }
        }

        for(auto a : ch)board[a.y][a.x] ^= 1;
    }
};


//AFTER
class Solution {
private:
    int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int cnt = 0;
                for(int d=0; d<8; d++){
                    int ny=i+dy[d], nx=j+dx[d];
                    if(ny<0 || nx<0 || ny>=n || nx>=m)continue;
                    if(board[ny][nx] == 1 || board[ny][nx] == 2)cnt++;
                }

                if(board[i][j]){
                    if(cnt<2 || cnt>3)board[i][j] = 2;
                }
                else{
                    if(cnt == 3)board[i][j] = 3;
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] >= 2)board[i][j] -= 2;
            }
        }
    }
};
